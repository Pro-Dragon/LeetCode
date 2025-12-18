class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        long long count = 0, cur = 0, total = 0;
        for(int i = 0; i < n; i++) {
            if(i >= k / 2 && i < k) count += prices[i];
            if(i < k) cur += (prices[i] * strategy[i]);
            total += (prices[i] * strategy[i]);
        }
        long long maxi = total;
        maxi = max(maxi, (total - cur) + count);
        for(int i = k; i < n; i++) {
            count -= prices[(i - k / 2)];
            cur -= (prices[i - k] * strategy[i - k]);
            count += prices[i];
            cur += (prices[i] * strategy[i]);
            maxi = max(maxi, (total - cur) + count);
        }
        return maxi;
    }
};