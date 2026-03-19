class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), count = 0, col = m, cur;
        vector<int> res(m, 0);
        for(int i = 0; i < n; i++) {
            cur = 0;
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 'X') {
                    cur++;
                    col = min(col, j);
                }
                else if(grid[i][j] == 'Y') cur--;
                res[j] += cur;
                if(!res[j] && j >= col) count++;
            }
        }
        return count;
    }
};