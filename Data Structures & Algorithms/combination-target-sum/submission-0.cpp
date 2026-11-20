class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> allSums;
        vector<int> currSum;

        if (nums.size() == 0) return {};
        if (target == 0) return {{0}};
        
        auto findSums = [&](this auto&& findSums, int index, int sum) {
            if (sum > target) return;

            if (sum == target) {
                allSums.push_back(currSum);
                return;
            }
            
            currSum.push_back(nums[index]);
            findSums(index,sum+nums[index]);
            currSum.pop_back();
            
            if (index+1 >= nums.size()) return;
            findSums(index+1,sum);
        };

        findSums(0,0);
        return allSums;
    }
};
