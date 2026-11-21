class Solution {
private:
    vector<vector<string>> partitions;
    vector<string> palindromes;
    string candidate;

    bool isPalindrome() {
        int l = 0, r = candidate.size()-1;

        while (l < r) {
            if (candidate[l] != candidate[r]) return false;
            ++l;--r;
        }

        return true;
    }

    void findPartitions(string& s, int index) {
        if (index >= s.size() && isPalindrome()) {
            partitions.push_back(palindromes);
            return;
        }
        if (index >= s.size()) {
            return;
        }

        candidate += s[index];
        
        // Branch by moving to next substring
        if (isPalindrome()) {
            palindromes.push_back(candidate);
            string temp = candidate;
            candidate.clear();
            findPartitions(s, index+1);
            candidate = temp;
            palindromes.pop_back();
        }

        // Branch by adding another char to string
        if (index+1 < s.size()) findPartitions(s, index+1);
        candidate.pop_back();

        return;
    }
public:
    vector<vector<string>> partition(string s) {
        findPartitions(s, 0);
        return partitions;
    }
};
