class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size(), m = queries.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<vector<pair<int, int>>> freq(n);
        vector<int> res(m);
        for(int i = 0; i < m; i++) {
            int a = min(queries[i][0], queries[i][1]), b = max(queries[i][0], queries[i][1]);
            if(a == b) {
                res[i] = queries[i][0];
            }
            else if(heights[a] < heights[b]) res[i] = b;
            else freq[max(queries[i][0], queries[i][1])].push_back({max(heights[queries[i][0]], heights[queries[i][1]]), i});
        }
        for(int i = 0; i < n; i++) {
            while(!pq.empty() && pq.top().first < heights[i]) {
                res[pq.top().second] = i;
                pq.pop();
            }
            while(freq[i].size()) {
                pq.push(freq[i].back());
               // cout<<freq[i].back().first<<" "<<freq[i].back().second<<" "<<i<<endl;
                freq[i].pop_back();
            }
        }
        while(!pq.empty()) {
            res[pq.top().second] = -1;
            pq.pop();
        }
        return res;
    }
};