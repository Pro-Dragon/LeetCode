class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size(), m = queries.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<vector<pair<int, int>>> freq(n);
        vector<int> res(m, -1);
        for(int i = 0; i < m; i++) {
            int a = min(queries[i][0], queries[i][1]), b = max(queries[i][0], queries[i][1]);
            if(a == b) {
                res[i] = queries[i][0];
            }
            else if(heights[a] < heights[b]) res[i] = b;
            else freq[b].push_back({max(heights[a], heights[b]), i});
        }
        for(int i = 0; i < n; i++) {
            while(!pq.empty() && pq.top().first < heights[i]) {
                res[pq.top().second] = i;
                pq.pop();
            }
            for(auto val : freq[i]) pq.push(val);
        }
        return res;
    }
};