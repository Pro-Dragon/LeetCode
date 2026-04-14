class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int> (n));
        int m = n;
        int i1 = 0, j1 = 0, size, val = 1;
        while(n > 0 && m > 0) {
            size = m;
            while(n > 0 && m > 0 && size > 0) {
                mat[i1][j1] = val++;
                j1++, size--;
            }
            j1--, n--, i1++;
            size = n;
            while(n > 0 && m > 0 && size > 0) {
                mat[i1][j1] = val++;
                i1++, size--;
            }
            i1--, m--, j1--;
            size = m;
            while(n > 0 && m > 0 && size > 0) {
                mat[i1][j1] = val++;
                j1--, size--;
            }
            j1++, n--, i1--;
            size = n;
            while(n > 0 && m > 0 && size > 0) {
                mat[i1][j1] = val++;
                i1--, size--;
            }
            i1++, m--, j1++;
        }
        return mat;
    }
};