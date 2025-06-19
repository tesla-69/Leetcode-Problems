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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        int cnt = 0;
        while(temp != NULL) {
            cnt++;
            temp = temp -> next;
        }
        // cout<<cnt<<" ";
        ListNode * node = head;
        ListNode * first = NULL;
        int n = 1;
        while(n <= cnt) {
            if(n == k) {
                if(first == NULL) first = node;
                else swap(first->val, node->val);
                // cout<<n<< " ";
            }
            if(n == cnt - k + 1) {
                // cout<< n <<" ";
                if(first == NULL) first = node;
                else swap(first->val, node->val);
            }
            node = node->next;
            n++;
        }
        return head;
    }
};