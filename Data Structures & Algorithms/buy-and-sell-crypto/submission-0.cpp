class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int i = 0, j = 1;

        while (i <= j && j < prices.size()) {
            if (prices[j] > prices[i]) {
                profit = max(profit, prices[j] - prices[i]);
            }

            if (prices[j] < prices[i]) i = j;

            j++;
        }        

        return profit;
    }
};
