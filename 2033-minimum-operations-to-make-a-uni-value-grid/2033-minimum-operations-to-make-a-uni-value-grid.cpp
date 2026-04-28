class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size(), m = grid[0].size(), prv = grid[0][0] % x, count = 0;
        vector<int> arr(n * m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(prv != grid[i][j] % x) return -1;
                prv = grid[i][j] % x;
                arr[m * i + j] = grid[i][j];
            }
        }
        sort(arr.begin(), arr.end());
        for(int i = 0; i < n * m; i++) {
            count += ((abs(arr[(n*m)/2] - arr[i])) / x);
        }
        return count;
    }
};