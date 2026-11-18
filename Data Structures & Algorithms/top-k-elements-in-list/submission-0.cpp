class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> counts;
		for (int num : nums) counts[num]++;
		
		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> topK;
		for (auto& [num, count] : counts) {
			topK.push({count, num});
			if ((int)topK.size() > k) topK.pop();
		}
		
		vector<int> result;
		while (!topK.empty()) {
			result.push_back(topK.top().second);
			topK.pop();
		}
		
		return result;
	}
};