class Solution {
private:
    const array<string, 10> digitMap = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    vector<string> combinations;
    string combination;

    void getAllCombinations(string& digits, int index) {
        if (index >= digits.size() && combination.size() > 0) {
            combinations.push_back(combination);
            return;
        }
        if (index >= digits.size()) {
            return;
        }

        const string& letters = digitMap[digits[index] - '0'];

        for (int i = 0; i < letters.size(); ++i) {
            combination += letters[i];
            getAllCombinations(digits, index+1);
            combination.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        getAllCombinations(digits, 0);
        return combinations;
    }
};
