class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.length() < s1.length()) return false;
        vector<int> s1Map(26,0);
        vector<int> substr(26,0);
        
        for (int i = 0; i < s1.size(); ++i) {
            s1Map[s1[i] - 'a']++;
        }

        int l = 0;
        for (int r = 0; r < s2.size(); ++r) {
            if (s1Map[s2[r]-'a'] <= 0) {
                l = r+1;
                fill(substr.begin(), substr.end(), 0);
                continue;
            }

            while (s1Map[s2[r]-'a'] < substr[s2[r]-'a']+1) {
                --substr[s2[l]-'a'];
                ++l;
            }

            substr[s2[r]-'a']++;
            if (r-l+1 >= s1.size()) return true;
        }

        return false;
    }
};
