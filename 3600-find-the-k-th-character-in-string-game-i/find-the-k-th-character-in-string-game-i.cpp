class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        int j = 0;
        int i = 0;
        while(s.size() < k) {
            string t;
            int n = s.size();
            for(int i = 0; i < n; i++) {
                char ch = s[i];
                cout<<ch<<" ";
                ch += 1;
                t += ch;
                cout<<ch<<" ";
            } 
            cout<<endl;
            s += t;
        }
        return s[k-1];
    }
};