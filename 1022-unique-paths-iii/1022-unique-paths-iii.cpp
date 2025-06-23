class Solution {
public:
int res = 0;
    void Dragon(vector<vector<int>>& grid, int i, int j, int count) {
        if(i == grid.size() || j == grid[0].size() || i < 0 || j < 0 || grid[i][j] < 0) return;
        if(grid[i][j] == 2) {
            if(!count) res++;
            return;
        }
        grid[i][j] = -1;
        Dragon(grid, i + 1, j, count - 1);
        Dragon(grid, i, j + 1, count - 1);
        Dragon(grid, i - 1, j, count - 1);
        Dragon(grid, i, j - 1, count - 1);
        grid[i][j] = 1;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), count = 0, ind1 = -1, ind2 = -1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) count++;
                else if(grid[i][j] == 1) {
                    ind1 = i;
                    ind2 = j;
                    count++;
                }
            }
        }
        Dragon(grid, ind1, ind2, count);
        return res;
    }
};