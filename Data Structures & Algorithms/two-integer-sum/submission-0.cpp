class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numSet = {};

        for (int i = 0; i < nums.size(); ++i) {
            auto pairLocation = numSet.find(target-nums[i]);
            if (pairLocation != numSet.end()) return {(pairLocation->second), i};

            numSet[nums[i]] = i;
        }
    }
};
