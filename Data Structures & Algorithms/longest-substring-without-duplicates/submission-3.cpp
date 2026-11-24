class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> existingChars;
        int longest = 0;

        int l = 0, r = 0;
        while (r < s.size()) {
            if (existingChars.contains(s[r]) && existingChars[s[r]] >= l) {
                l = existingChars[s[r]] + 1;
            }
            
            existingChars[s[r]] = r;
            longest = max(longest, r-l+1);
            ++r;
        }

        return longest;
    }
};
