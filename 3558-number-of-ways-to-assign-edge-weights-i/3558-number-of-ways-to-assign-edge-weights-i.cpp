class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size(), mod = 1e9 + 7, res = 0, m, ele, k, prv;
        vector<vector<int>> graph(n + 2);
        for(int i = 0; i < n; i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(n + 2, 0);
        queue<int> pq;
        pq.push(1);
        vis[1] = 1;
        while(!pq.empty()) {
            m = pq.size();
            res = (res * 2) % mod;
            if(!res && pq.front() != 1) res = 1;
            while(m--) {
                ele = pq.front(), k = graph[ele].size();
                for(int i = 0; i < k; i++) {
                    if(!vis[graph[ele][i]]) {
                        pq.push(graph[ele][i]);
                        vis[graph[ele][i]]++;
                    }
                }
                pq.pop();
            }
        }
        return res;
    }
};