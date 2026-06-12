class Solution {
public:
    int mod = 1e9 + 7;
    void build(vector<vector<int>> &graph, vector<vector<int>> &binarylift, vector<int> &level, vector<int> &levels, int root, int cur_level, int prv) {
        level[cur_level] = root;
        levels[root] = cur_level;
        int n = graph[root].size(), ind = 1;
        while(cur_level >= ind) {
            binarylift[root].push_back(level[cur_level - ind]);
            ind = (ind * 2) % mod;
        }
        for(int i = 0; i < n; i++) {
            if(prv != graph[root][i]) build(graph, binarylift, level, levels, graph[root][i], cur_level + 1, root);
        }
    }
    int find(int val1, int val2, vector<vector<int>> &binarylift, vector<int> &levels) {
        if(levels[val2] > levels[val1]) swap(val1, val2);
        long target = levels[val2], res = 1, prv = -1, i, cur = 1, flag = 0, prv1, prv2;
        if(levels[val1] == levels[val2]) flag = 1;
        while(levels[val1] > target) {
            int n = binarylift[val1].size();
            for(i = 0; i < n; i++) {
                if(i > 1) cur = (cur * cur) % mod;
                else if(i == 1) cur = 2;
                if(levels[binarylift[val1][i]] < target) {
                    val1 = prv;
                    break;
                }
                res = (res * cur) % mod;
                prv = binarylift[val1][i];
                if(levels[binarylift[val1][i]] == target) {
                    val1 = binarylift[val1][i];
                    break;
                }
            }
            cur = 2;
            if(i == n) val1 = prv;
        }
        while(val1 != val2) {
            int n = binarylift[val1].size();
            cur = 4, prv1 = -1, prv2 = -1;
            for(i = 0; i < n; i++) {
                if(i > 1) cur = (cur * cur) % mod;
                if(binarylift[val1][i] == binarylift[val2][i]) {
                    if(!i) {
                        if(flag) {
                            res = (res * (cur / 2)) % mod;
                            flag = 0;
                        }
                        else res = (res * cur) % mod;
                        val1 = binarylift[val1][i];
                        val2 = binarylift[val2][i];
                        break;
                    }
                    val1 = prv1;
                    val2 = prv2;
                    break;
                }
                if(flag) {
                    res = (res * (cur / 2)) % mod;
                    flag = 0;
                }
                else {
                if(i == 2) cout<<res<< " " << cur<<endl;
                    res = (res * cur) % mod;
                }
                prv1 = binarylift[val1][i];
                prv2 = binarylift[val2][i];
            }
            if(i == n) {
                val1 = prv1;
                val2 = prv2;
            }
        }
        return (flag) ? 0 : res;
    }
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size(), m = queries.size(), val2, val1;
        vector<vector<int>> graph(n + 2), binarylift(n + 2);
        vector<int> level(n + 2), res(m), levels(n + 2);
        for(int i = 0; i < n; i++) {
            graph[edges[i][1]].push_back(edges[i][0]);
            graph[edges[i][0]].push_back(edges[i][1]);
        }
        build(graph, binarylift, level, levels, 1, 0, 0);
        for(int i = 0; i < m; i++) {
            val1 = queries[i][0], val2 = queries[i][1];
            res[i] = find(val1, val2, binarylift, levels);
        }
        return res;
    }
};