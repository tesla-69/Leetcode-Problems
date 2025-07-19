class Solution {
public:
    std::vector<std::string> removeSubfolders(std::vector<std::string>& folder) {
        
        std::sort(folder.begin(), folder.end());
        std::vector<std::string> ans;
        std::string prev = folder[0] + "/";
        ans.push_back(folder[0]);

        for (int i = 1; i < folder.size(); ++i) {
            if (folder[i].find(prev) == 0) {

                continue;
            }
            ans.push_back(folder[i]);
            prev = folder[i] + "/";}
        
        return ans; }
};