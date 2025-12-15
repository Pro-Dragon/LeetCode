class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long count = 0, n = prices.size(), cur = 1;
        for(int i = 1; i < n; i++) {
            if(prices[i] + 1 == prices[i - 1]) {
                cur++;
            }
            else {
                count += (cur * (cur + 1)) >> 1;
                cur = 1;
            }
        }
        count += (cur * (cur + 1)) >> 1;
        return count;
    }
};