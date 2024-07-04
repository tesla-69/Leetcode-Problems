class Solution {
public:
    string firstPalindrome(vector<string>& words) {
    for (auto &w : words)
        if (w == string(rbegin(w), rend(w)))
            return w;
    return "";
}
private:
    bool isPalin(string & word){
        int left = 0, right = word.size() - 1;
        while(left <= right){
            if(word[left++] != word[right--])return false;
        }
        return true;
    }    
};