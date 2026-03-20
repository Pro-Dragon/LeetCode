class Solution {
private:
    int Demon(int i1, int i2, int k, vector<vector<int>>& grid) {
        int mini = INT_MAX;
        map<int, int> maxico;
        for(int i = i1; i <= i1 + k - 1; i++) {
            for(int j = i2; j <= i2 + k - 1; j++) {
                maxico[grid[i][j]]++;
            }
        }
        if(maxico.size() == 1) return 0;
        for(auto mp = maxico.begin(); next(mp) != maxico.end(); mp++) {
            mini = min(mini, abs(next(mp)->first - mp->first));
        }
        return mini;
    }
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> res(n - k + 1, vector<int> (m - k + 1, 0));
        if(k == 1) return res;
        for(int i = 0; i <= n - k; i++) {
            for(int j = 0; j <= m - k; j++) {
                res[i][j] = Demon(i, j, k, grid);
            }
        }
        return res;
    }
};