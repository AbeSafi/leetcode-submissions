class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> charsAmount;

        int l = 0;
        int maxFreq = 0; int longest = 0;
        for (int r = 0; r < s.size(); ++r) {
            charsAmount[s[r]]++;
            maxFreq = max(maxFreq, charsAmount[s[r]]);

            while (((r-l+1)-maxFreq) > k) {
                --charsAmount[s[l]];
                ++l;
            }

            longest = max(longest, r-l+1);
        }

        return longest;
    }
};
