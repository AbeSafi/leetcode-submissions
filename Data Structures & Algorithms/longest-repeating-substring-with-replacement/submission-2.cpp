class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> charsAmount = {
            {'A',0},{'B',0},{'C',0},{'D',0},{'E',0},{'F',0},
            {'G',0},{'H',0},{'I',0},{'J',0},{'K',0},{'L',0},
            {'M',0},{'N',0},{'O',0},{'P',0},{'Q',0},{'R',0},
            {'S',0},{'T',0},{'U',0},{'V',0},{'W',0},{'X',0},
            {'Y',0},{'Z',0}
        };

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
