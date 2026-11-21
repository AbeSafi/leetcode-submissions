class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        unordered_set<int> inUseNums;
        vector<int> permutation;

        auto getPermutations = [&](this auto && getPermutations) -> void {
            if (permutation.size() == nums.size()) {
                permutations.push_back(permutation);
                return;
            }

            for (int i = 0; i < nums.size(); ++i) {
                if (inUseNums.contains(nums[i])) continue;
                inUseNums.insert(nums[i]);
                permutation.push_back(nums[i]);
                getPermutations();
                inUseNums.erase(nums[i]);
                permutation.pop_back();
            }
        };

        getPermutations();
        return permutations;
    }
};
