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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> arr;
        if(head == NULL || head->next == NULL || head->next->next == NULL) return {-1,-1};
        ListNode*temp = head->next;
        int prev = head->val;
        int i = 2;
        while(temp->next!=NULL){
            int curr = temp->val;
            int next = temp->next->val;
            if(curr > prev && curr > next) {
                arr.push_back(i);
            } 
            else if(curr < prev && curr < next) {
                arr.push_back(i);
            }
            i++;
            prev = temp->val;
            temp= temp->next;
        }
        if(arr.size()<=1) return {-1,-1};
        else {
            sort(arr.begin(),arr.end());
            int mx = arr[arr.size()-1] - arr[0];
            int mn = INT_MAX;
            for(int i=1;i<arr.size();i++){
                mn = min(mn,arr[i]-arr[i-1]);
            }
            return {mn,mx};
        }
    }
};