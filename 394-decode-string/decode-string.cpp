class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> result;
        string currentString = "";
        int index = 0;

        while (index < s.size()) {
            if (isdigit(s[index])) {
                int count = 0;
                while (isdigit(s[index])) {
                    count = count * 10 + (s[index] - '0');
                    index++;
                }
                counts.push(count);
            } else if (s[index] == '[') {
                result.push(currentString);
                currentString = "";
                index++;
            } else if (s[index] == ']') {
                string temp = currentString;
                currentString = result.top();
                result.pop();
                int count = counts.top();
                counts.pop();
                while (count > 0) {
                    currentString += temp;
                    count--;
                }
                index++;
            } else {
                currentString += s[index];
                index++;
            }
        }
        return currentString;
    }
};
