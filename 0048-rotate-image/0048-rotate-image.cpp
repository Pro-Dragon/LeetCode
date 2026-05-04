class Solution {
public:
    void rotate(vector<vector<int>>& mat){
    int n1 = mat.size()/2;
    int i1 = 0, j1 = 0, i2 = 0, j2 = mat.size() - 1;
    int i3 = j2, j3 = j2, i4 = j2, j4 = 0;
    int size = j2;
    int t1, t2, t3, t4;
    while(n1--){
        int c1 = i1, c2 = i2, c3 = i3, c4 = i4;
        int d1 = j1, d2 = j2, d3 = j3, d4 = j4;
        int n = size;
        while(n--){
            t1 = mat[i1][j1];
            t2 = mat[i2][j2];
            t3 = mat[i3][j3];
            t4 = mat[i4][j4];
            mat[i2][j2] = t1;
            mat[i3][j3] = t2;
            mat[i4][j4] = t3;
            mat[i1][j1] = t4;
            j1++;
            i2++;
            j3--;
            i4--;
        }
        i1 = c1 + 1;
        j1 = d1 + 1;
        i2 = c2 + 1;
        j2 = d2 - 1;
        i3 = c3 - 1;
        j3 = d3 - 1;
        i4 = c4 - 1;
        j4 = d4 + 1;
        size -= 2;
    }
    }
};