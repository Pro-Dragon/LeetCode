class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), count = 0;
        vector<int> r(n, 0), c(m, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j]) {
                    r[i]++;
                    c[j]++;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] && r[i] == 1 && c[j] == 1) count++;
            }
        }
        return count;
    }
};