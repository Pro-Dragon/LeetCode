class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), mini = INT_MAX;
        long long sum = 0;
        bool count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] < 0) {
                    matrix[i][j] *= -1;
                    count = !count;
                }
                mini = min(matrix[i][j], mini);
                sum += matrix[i][j];
            }
        }
        return (count) ? (sum - (mini * 2)) : sum;
    }
};