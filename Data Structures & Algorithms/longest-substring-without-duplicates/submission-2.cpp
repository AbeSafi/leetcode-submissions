class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> existingChars;
        int longest = 0;

        int l = 0, r = 0;
        while (r < s.size()) {
            if (existingChars.contains(s[r])) {
                existingChars.erase(s[l]);
                ++l;
                continue;
            }
            
            existingChars.insert(s[r]);
            ++r;
            longest = max(longest, r-l);
        }

        return longest;
    }
};
