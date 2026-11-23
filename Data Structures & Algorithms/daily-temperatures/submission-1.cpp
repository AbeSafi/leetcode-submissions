class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size());
        stack<pair<int,int>> temps;

        for (int i = 0; i < temperatures.size(); ++i) {
            while (!temps.empty() && temperatures[i] > temps.top().first) {
                result[temps.top().second] = i-temps.top().second;
                temps.pop();
            }

            temps.push({temperatures[i], i});
        }

        return result;
    }
};
