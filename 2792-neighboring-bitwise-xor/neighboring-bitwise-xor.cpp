class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        vector<int> possible(n);
        possible[0] = 0;
        int flag = 0;
        for(int i = 0 ; i < n-1; i++){
            if(derived[i] == 1){
                if(possible[i] == 1) possible[i+1] = 0;
                else possible[i+1] = 1;

            }
            else {
                if(possible[i] == 1) possible[i+1] =1;
                else possible[i+1] = 0; 
            }
        }
        if(possible[0] ^ possible[n-1] == derived[n-1]) return true;
        else return false;
    }
};