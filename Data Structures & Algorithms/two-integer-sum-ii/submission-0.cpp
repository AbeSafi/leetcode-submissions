class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i1 = 0, i2 = numbers.size()-1;

        while (i1 < i2) {
            if (numbers[i1] + numbers[i2] == target) return {i1+1, i2+1};

            if (numbers[i1] + numbers[i2] > target) --i2;
            else ++i1;
        }

        return {i1+1,i2+1};
    }
};
