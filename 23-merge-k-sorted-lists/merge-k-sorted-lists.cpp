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
class compare{
    public :
        bool operator() (ListNode*a , ListNode*b) {
            return a->val > b->val;
        }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*> , compare > pq;
        int n = lists.size();
        if(n == 0) return NULL;
        for(int i=0; i< n ;i++) {
            if(lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while(!pq.empty()){
            if(head == NULL) {
                head = pq.top();
                tail = pq.top();
                pq.pop();
                if(head->next != NULL) pq.push(head->next);
            }
            else {
                tail->next = pq.top();
                pq.pop();
                tail = tail->next;
                if(tail->next != NULL) pq.push(tail->next);
            }
        }
        return head;
        
    }
};