class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int val = grid[0][0] % x, n = grid.size(), m = grid[0].size(), mini = grid[0][0], count = 0, total = 0;
        vector<int> mp(10001, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] % x != val) return -1;
                mp[grid[i][j]]++;
                mini = min(mini, grid[i][j]);
                total += (grid[i][j] - val) / x;
            }
        }
        total -= ((mini - val) / x) * ((n * m));
        int i = mini + x, prv = mini, cur = mp[mini];
        while(cur <= (n * m) / 2) {
            count += cur;
            if(mp[i]) {
                total -= ((i - prv) / x) * ((n * m) - cur);
                prv = i;
                cur += mp[i];
            }
            i += x;
        }
        return count + total;
    }
};