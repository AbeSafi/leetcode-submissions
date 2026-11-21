class Solution {
private:
    vector<vector<int>> subsets;
    vector<int> subset;

    void findSubsets(vector<int>& nums, int index) {
        if (index == nums.size()) {
            subsets.push_back(subset);
            return;
        }

        subset.push_back(nums[index]);
        findSubsets(nums, index+1);
        subset.pop_back();

        ++index;
        while (index < nums.size() && nums[index] == nums[index-1]) ++index;
        findSubsets(nums, index);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        findSubsets(nums, 0);
        return subsets;
    }
};
