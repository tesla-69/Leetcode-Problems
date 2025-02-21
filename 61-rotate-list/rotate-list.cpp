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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        ListNode*tail = head;
        int n = 1;
        while(tail->next != NULL) {
            tail = tail->next;
            n++;
        }
        k %= n;
        ListNode * temp = head;
        for(int i =0;i < n-k-1;i++) {
            temp = temp->next;
        }
        if(temp->next == NULL) return head;
        else {
            ListNode* newhead = temp->next;
            temp->next = NULL;
            tail->next = head;
            return newhead;
        }
        return NULL;
    }
};