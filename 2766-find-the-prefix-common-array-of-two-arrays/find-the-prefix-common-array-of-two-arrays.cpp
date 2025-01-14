class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        int n = A.size();
        // stack<int> st;
        set<int> s;
        int cnt = 0;
        for(int i =0;i<n;i++){
            // st.push(A[i]);
            // s.insert(B[i]);
            // if(s.find(st.top()) != s.end()){
            //     while(!st.empty()){
                     
            //     }
            // }
            s.insert(B[i]);
            for(int j =0;j<=i;j++){
                if(s.find(A[j]) != s.end()){
                    A[j] = -1;
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};