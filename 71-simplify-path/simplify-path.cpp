class Solution {
public:
    string simplifyPath(string path) {
        stack <string> s;
        int i=0;
        while(i<path.length()){
            int start=i;
            int end=i+1;
            while(end<path.size() && path[end]!='/'){
                end++;
            }
            i=end;
            int len= end-start;
            string subs=path.substr(start,len);
            if(subs=="/" || subs=="/.") continue;
            else if(subs=="/.." && !s.empty()) s.pop();
            else if(subs == "/.." && s.empty()) continue;
            else s.push(subs);
        }
        string ans= s.empty() ? "/" : "";
        while(!s.empty()) {
            string temp = s.top();
            reverse(temp.begin(),temp.end());
            ans+=temp;
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};