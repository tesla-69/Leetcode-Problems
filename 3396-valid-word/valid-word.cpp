class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3) return false;
        bool vowel = false, consonant = false;
        for(auto it: word) {
            if(it >= '0' && it <= '9') continue;
            else if((it >= 'a' && it <= 'z') || (it >= 'A' && it <= 'Z')) {
                if(it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u' || 
                it == 'A' || it == 'E' || it == 'I' || it == 'O' || it == 'U') vowel = true;
                else consonant = true;
            }
            else return false;
        }
        return vowel && consonant;
    }
};