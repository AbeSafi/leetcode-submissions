class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        unordered_set<int> starters;
        

        for (int num : numSet) {
            if (numSet.contains(num-1)) continue;
            starters.insert(num);
        }

        int maxLength = 0;
        for (int starter : starters) {
            int index = 0;
            while (numSet.contains(starter+index)) {
                index+=1;
            }
            maxLength = (index > maxLength) ? index : maxLength;
        }

        return maxLength;
    }
};
