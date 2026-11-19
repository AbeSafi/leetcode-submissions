class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            int j = nums.size()-i-1;

            prefix[i] = (i-1 >= 0) ? prefix[i-1]*nums[i] : nums[i];
            suffix[j] = (j+1 < nums.size()) ? suffix[j+1]*nums[j] : nums[j];
        }

        vector<int> output(nums.size());
        for (int i = 0; i < output.size(); ++i) {
            int prefInt = (i-1 >= 0) ? prefix[i-1] : 1;
			int suffInt = (i+1 < suffix.size()) ? suffix[i+1] : 1;
			
			output[i] = prefInt * suffInt;
        }
		
		return output;
    }
};
