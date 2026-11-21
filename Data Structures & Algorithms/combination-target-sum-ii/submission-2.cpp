class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> combinations;
        vector<int> combination;

        auto getNextUniqueIndex = [&](int i) {
            while (i < candidates.size() && candidates[i] == candidates[i-1]) ++i;
            return i;
        };

        auto findCombinations = [&](this auto&& findCombinations, int index, int sum) -> void {
            if (sum == target) {
                combinations.push_back(combination);
                return;
            }
            if (index >= candidates.size() || sum > target) return;
            
            combination.push_back(candidates[index]);
            findCombinations(index+1, sum+candidates[index]);
            combination.pop_back();

            index = getNextUniqueIndex(index+1);
            findCombinations(index, sum);
        };

        findCombinations(0,0);
        return combinations;
    }
};
