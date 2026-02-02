class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        priority_queue<pair<int, int>> pq1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;
        long long exp = 0, n = nums.size(), cost = 0, cur = 0;
        vector<int> check(n, 0);
        for(int i = 1; i <= dist + 1; i++) {
            pq1.push({nums[i], i});
            cur += nums[i];
            if(pq1.size() == k) {
                cur -= pq1.top().first;
                check[pq1.top().second] = 1;
                pq2.push(pq1.top());
                pq1.pop();
            }
        }
        cost = cur;
        for(int i = dist + 2, j = 2; i < n; i++, j++) {
            if(!check[j - 1]) {
                exp++;
                cur -= nums[j - 1];
            }
            while(!pq1.empty() && pq1.top().second < j) {
                pq1.pop();
                exp--;
            }
            while(!pq2.empty() && pq2.top().second < j) {
                pq2.pop();
            }
            pq1.push({nums[i], i});
            cur += nums[i];
            if(pq1.size() - exp == k) {
                cur -= pq1.top().first;
                check[pq1.top().second] = 1;
                pq2.push(pq1.top());
                pq1.pop();
            }
            if(!pq2.empty() && pq1.top().first > pq2.top().first) {
                cur -= pq1.top().first;
                cur += pq2.top().first;
                auto val = pq1.top();
                check[pq1.top().second] = 1;
                check[pq2.top().second] = 0;
                pq1.pop();
                pq1.push(pq2.top());
                pq2.pop();
                pq2.push(val);
            }
            cost = min(cur, cost);
        }
        return cost + nums[0];
    }
};