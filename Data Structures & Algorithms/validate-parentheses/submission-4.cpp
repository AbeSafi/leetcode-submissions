class Solution {
public:
    bool isValid(string s) {
        stack<char> pths;
        for (char c : s) {
            bool isClosing = (c == ')' || c == '}' || c == ']');

            if (isClosing && !pths.empty() && (c == pths.top()+1 || c == pths.top()+2)) {
                pths.pop();
            }
            else if (isClosing) {
                return false;
            }
            else {
                pths.push(c);
            }
        }

        return pths.empty();
    }
};
