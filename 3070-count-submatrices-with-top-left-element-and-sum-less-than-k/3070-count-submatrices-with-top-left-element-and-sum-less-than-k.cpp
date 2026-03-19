class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size(), count = 0, cur;
        vector<int> res(m, 0);
        for(int i = 0; i < n; i++) {
            cur = 0;
            for(int j = 0; j < m; j++) {
                cur += grid[i][j];
                res[j] += cur;
                if(res[j] <= k) count++;
            }
        }
        return count;
    }
};