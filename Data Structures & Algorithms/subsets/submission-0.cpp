class Solution {
private:
    void backtrackSubsets(
            vector<int>& nums,
            vector<vector<int>>& result, 
            vector<int> currVector,
            int currIndex
            ) {
        result.push_back(currVector);

        for (int i = currIndex; i < nums.size(); ++i) {
            currVector.push_back(nums[i]);
            backtrackSubsets(nums, result, currVector, i+1);
            currVector.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result = {};
        backtrackSubsets(nums, result, {}, 0);

        return result;
    }
};
