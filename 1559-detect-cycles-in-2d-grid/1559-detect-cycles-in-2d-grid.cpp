class Solution {
public:
    char val;
    bool dfs(vector<vector<char>>& grid, vector<vector<bool>> &vis, int i, int j, int i1, int j1) {
        if(i >= grid.size() || j >= grid[0].size() || grid[i][j] != val) return 0;
        if(vis[i][j]) return 1;
        vis[i][j] = 1;
        if(((i + 1 != i1 || j != j1) && dfs(grid, vis, i + 1, j, i, j)) || ((i - 1 != i1 || j != j1) && dfs(grid, vis, i - 1, j, i, j)) || ((i != i1 || j + 1 != j1) && dfs(grid, vis, i, j + 1, i, j)) || ((i != i1 || j - 1 != j1) && dfs(grid, vis, i, j - 1, i, j))) return 1;
        return 0;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j]) {
                    val = grid[i][j];
                    if(dfs(grid, vis, i, j, -1, -1)) {
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
};