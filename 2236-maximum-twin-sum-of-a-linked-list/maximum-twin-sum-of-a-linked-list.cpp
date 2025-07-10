/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        unordered_map<int, int> mp;
        ListNode* slow = head;
        ListNode* fast = head;
        int i = 0;
        while(fast != NULL) {
            mp[i++] = slow->val;
            slow = slow->next;
            fast = fast->next->next;
        }
        i--;
        int maxi = 0;
        int cnt = 1;
        while(slow != NULL) {
            maxi = max(maxi, slow->val + mp[i--]);
            slow = slow->next;
        }
        return maxi;
    }
};