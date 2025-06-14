class Solution {
public:
    string findReplaceString(string S, vector<int>& idx, vector<string>& src,
                             vector<string>& tg, string res = "") {
        vector<pair<int, string>> r(S.size());
        for (auto i = 0; i < idx.size(); ++i)
            if (S.compare(idx[i], src[i].size(), src[i]) == 0)
                r[idx[i]] = {src[i].size(), tg[i]};
        for (int i = 0; i < S.size(); ++i) {
            if (r[i].first == 0)
                res += S[i];
            else
                res += r[i].second, i += r[i].first - 1;
        }
        return res;
    }
};