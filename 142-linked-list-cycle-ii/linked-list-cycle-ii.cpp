/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map<ListNode* , int> mp;
        ListNode* temp = head;
        ListNode* dup = NULL;
        while(temp != NULL){
            if(mp[temp] == 0)
                mp[temp]++;
            else {
                dup = temp;
                break;
            }
            temp= temp->next;
        }
        return dup;
       
    }
};