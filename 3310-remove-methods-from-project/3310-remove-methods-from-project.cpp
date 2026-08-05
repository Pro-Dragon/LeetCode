class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> mp1(n), mp2(n);
        for(int i = 0; i < invocations.size(); i++) {
            mp1[invocations[i][0]].push_back(invocations[i][1]);
            mp2[invocations[i][1]].push_back(invocations[i][0]);
        }

        vector<int> vis(n, 0), res, opt;
        queue<int> pq;
        pq.push(k);
        vis[k] = 1;
        int cnt = 0;
        while(!pq.empty()) {
            int cur = pq.front(), m = mp1[cur].size();
            while(m--) {
                int val = mp1[cur][m];
                if (!vis[val]) {
                    pq.push(val);
                    vis[val] = 1;
                }
            }
            pq.pop();
        }

        for(int i = 0; i < n; i++) {
            opt.push_back(i);
            if(cnt) continue;
            if(!vis[i]) {
                res.push_back(i);
                continue;
            }
            int m = mp2[i].size();
            for(int j = 0; j < m; j++) {
                if(!vis[mp2[i][j]]) cnt = 1;
            }
        }
        return (cnt) ? opt : res;
    }
};