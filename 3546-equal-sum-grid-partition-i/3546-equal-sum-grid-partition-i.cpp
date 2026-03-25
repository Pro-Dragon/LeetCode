class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long n1 = grid.size(), m1 = grid[0].size(), total = 0, now = 0;
        for(int i = 0; i < n1; i++) {
            for(int j = 0; j < m1; j++) {
                total += grid[i][j];
            }
        }
        for(int i = 0; i < n1; i++) {
            for(int j = 0; j < m1; j++) {
                now += grid[i][j];
            }
            if(now == total - now) return 1;
        }
        now = 0;
        for(int i = 0; i < m1; i++) {
            for(int j = 0; j < n1; j++) {
                now += grid[j][i];
            }
            if(now == total - now) return 1;
        }
        return 0;
    }
};