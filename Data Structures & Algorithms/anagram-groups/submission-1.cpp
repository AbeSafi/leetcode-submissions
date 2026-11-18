class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> buckets;
        
        for (int i = 0; i < strs.size(); ++i) {
            string currString = strs[i];
            string sorted = currString;
            sort(sorted.begin(), sorted.end());
            buckets[sorted].push_back(currString);
        }
		
		vector<vector<string>> bucketList;
		
		for (const auto& [_, i] : buckets) {
			bucketList.push_back(i);
		}
		
		return bucketList;
    }
};
