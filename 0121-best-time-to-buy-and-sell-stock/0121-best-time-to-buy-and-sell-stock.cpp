class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), maxi = 0, mini = prices[0];
        for(int i = 0; i < n; i++) {
            maxi = max(maxi, prices[i] - mini);
            mini = min(mini, prices[i]);
        }
        return maxi;
    }
};