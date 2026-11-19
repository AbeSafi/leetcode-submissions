class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        int i1 = 0;
        while (i1 < nums.size() && nums[i1] <= 0) {
            if (i1 > 0 && nums[i1-1] == nums[i1]) {++i1; continue;}
            
            int i2 = i1+1, i3 = nums.size()-1;
            while (i2 < i3) {
                int sum = nums[i1]+nums[i2]+nums[i3];
                if (sum == 0) {
                    result.push_back({nums[i1], nums[i2], nums[i3]});
                    ++i2;
                    while (nums[i2] == nums[i2-1] && i2 < i3) {
                        ++i2;
                    }
                }
                else if (sum > 0) {
                    --i3;
                }
                else {
                    ++i2;
                }
            }

            ++i1;
        }

        return result;
    }
};
