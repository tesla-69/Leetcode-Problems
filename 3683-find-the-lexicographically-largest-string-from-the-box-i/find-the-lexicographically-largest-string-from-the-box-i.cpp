class Solution {
public:
    string answerString(string word, int num) {
        if(num == 1) return word;
        int n = word.size();
        char lar = 'a';
        vector<vector<int>> arr(26);
        for (int i = 0; i < n; i++) {
            char ch = word[i];
            arr[ch - 'a'].push_back(i);
            if (ch > lar) {
                lar = ch;
            }
        }
        string sub = "";
        int len = n - num + 1;
        for (int i = 0; i < n; i++) {
            if (word[i] == lar) {
                int sz = min(n - i, len);
                cout<<len<<" "<<n-i<<" "<<sz<<endl;
                string temp = word.substr(i, sz);
                cout<<temp<<endl;
                if(temp > sub) sub = temp;
            }
        }
        return sub;
    }
};