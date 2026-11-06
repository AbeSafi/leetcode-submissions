class Solution {
private:
    char retMap(char b) {
        switch (b) {
            case '[': return ']';
            case '{': return '}';
            case '(': return ')';
        }

        return '\0';
    }
public:
    bool isValid(string s) {
        deque<char> sQueue;
        

        for (const char &c : s) {
            if (c == '[' || c == '{' || c == '(') {
                sQueue.push_front(c); continue;
            }
            
            if (sQueue.empty() || c != retMap(sQueue.front())) return false;
            sQueue.pop_front();
        }

        if (!sQueue.empty()) return false;
        return true;
    }
};
