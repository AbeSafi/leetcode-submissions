class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hashMapS = {};
        unordered_map<char, int> hashMapT = {};

        if (s.length() != t.length()) return false;

        for (int i = 0; i < s.length(); ++i) {
            hashMapS[s[i]]++;
            hashMapT[t[i]]++;
        }
        
        for (const auto& [key, value] : hashMapS) {
            if (!hashMapT.contains(key)) return false;
            if (hashMapT.at(key) != hashMapS.at(key)) return false;
        }

        return true;
    }
};
