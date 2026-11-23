class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size());
        stack<int> tempIds;

        for (int i = 0; i < temperatures.size(); ++i) {
            while (!tempIds.empty() && temperatures[i] > temperatures[tempIds.top()]) {
                result[tempIds.top()] = i-tempIds.top();
                tempIds.pop();
            }

            tempIds.push(i);
        }

        return result;
    }
};
