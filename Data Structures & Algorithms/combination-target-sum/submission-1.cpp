class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> allSums;
        vector<int> currSum;
        
        auto findSums = [&](this auto&& findSums, int index, int sum) {
            if (sum == target) {allSums.push_back(currSum);return;}
            if (sum > target || index >= nums.size()) return;
            
            currSum.push_back(nums[index]);
            findSums(index,sum+nums[index]);
            currSum.pop_back();
            
            findSums(index+1,sum);
        };

        findSums(0,0);
        return allSums;
    }
};
