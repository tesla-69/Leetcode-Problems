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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*, int> mp;

        ListNode* node = headA;
        ListNode* node2 = headB;

        while(node != NULL || node2 != NULL) {
            if(node && mp[node] == 1) return node;
            if(node2 && mp[node2] == 1) return node2;
            if(node == node2) return node;
            mp[node]++;
            mp[node2]++;
            if(node)node = node->next;
            if(node2)node2 = node2->next;
        }
        return NULL;

    }
};