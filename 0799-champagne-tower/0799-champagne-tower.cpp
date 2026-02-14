class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> res(101, vector<double>(101, 0.0));
        res[0][0] = poured;
        for(int i = 0; i <= query_row; i++) {
            for(int j = 0; j <= i; j++) {
                res[i + 1][j] += (max(res[i][j] - 1, 0.0)) * 0.5;
                res[i + 1][j + 1] += (max(res[i][j] - 1, 0.0)) * 0.5;
            }
            if(i == query_row) return min(res[i][query_glass], 1.0);
        }
        return 1.0;
    }
};