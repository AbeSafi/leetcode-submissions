class Solution {
private:
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currVector;

        auto backtrackSubsets = [&](this auto&& self, int index) -> void {
            if (index == nums.size()) {
                result.push_back(currVector);
                return;
            }

            currVector.push_back(nums[index]);
            self(index+1);
            currVector.pop_back();

            self(index+1);
        };


        backtrackSubsets(0);
        return result;
    }
};