class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), mod = 1e9 + 7;
        vector<vector<pair<long long, long long>>> res(n, vector<pair<long long, long long>> (m));
        res[0][0].first = grid[0][0];
        res[0][0].second = grid[0][0];
        for(int i = 1; i < m; i++) {
            grid[0][i] *= grid[0][i - 1];
            res[0][i].first = grid[0][i];
            res[0][i].second = grid[0][i];
        }
        for(int i = 1; i < n; i++) {
            grid[i][0] *= grid[i - 1][0];
            res[i][0].first = grid[i][0];
            res[i][0].second = grid[i][0];
        }
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(grid[i][j] < 0) {
                    res[i][j].first = (1ll * grid[i][j] * min(res[i - 1][j].second, res[i][j - 1].second));
                    res[i][j].second = (1ll * grid[i][j] * max(res[i - 1][j].first, res[i][j - 1].first));
                }
                else {
                    res[i][j].first = (1ll * grid[i][j] * max(res[i - 1][j].first, res[i][j - 1].first));
                    res[i][j].second = (1ll * grid[i][j] * min(res[i - 1][j].second, res[i][j - 1].second));
                }
            }
        }

        return (res[n - 1][m - 1].first % mod < 0) ? -1 : res[n - 1][m - 1].first % mod;
    }
};