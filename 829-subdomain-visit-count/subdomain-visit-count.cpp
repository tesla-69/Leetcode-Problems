class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        int n = cpdomains.size();
        map<string, int> mp;
        for(int i = 0; i < n; i++) {
            string t = cpdomains[i];
            int j = 0;
            int num = 0;
            while(t[j] != ' ') {
                num = num * 10 + (t[j] - '0');
                j++; 
            }
            j++;

            int len = t.size();
            t = cpdomains[i].substr(j, len);
            // cout<<t<<" ";
            j = 0;
            mp[t] += num;
            len = t.size();
            while(j < len && t[j] != '.'){    
                j++;
            }
            if(j != len - 1) j++;
            while(j < len) {
                string domain = "";
                while(j < len && t[j] != '.'){
                    domain += t[j];
                    j++;
                }
                domain += t.substr(j, len);
                mp[domain] += num;
                j++;
            }
        }
        vector<string> ans;
        for(auto it: mp) {
            string t = to_string(it.second) + ' ' + it.first;
            ans.push_back(t);
        }
        return ans;
    }
};