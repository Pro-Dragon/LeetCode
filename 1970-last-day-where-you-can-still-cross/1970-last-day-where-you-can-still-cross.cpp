class Solution {
public:
    vector<vector<int>> top, btm;
    int search(vector<vector<int>>& mat, int i, int j, int state) {
        if(i < 0 || i == mat.size() || j < 0 || j == mat[0].size() || !mat[i][j] || (!state && btm[i][j]) || (state && top[i][j])) return 0;
        if(!state) btm[i][j] = 1;
        else top[i][j] = 1;
        if(top[i][j] && btm[i][j]) return 1;
        if(search(mat, i + 1, j, state) || search(mat, i - 1, j, state) || search(mat, i, j + 1, state) || search(mat, i, j - 1, state)) return 1;
        return 0;
    }
    int solve(vector<vector<int>>& mat, int i, int j) {
        int state = -1;
        if(i - 1 >= 0 && mat[i - 1][j]) {
            if(!btm[i][j]) btm[i][j] = btm[i - 1][j];
            if(!top[i][j]) top[i][j] = top[i - 1][j];
        }
        if(j - 1 >= 0 && mat[i][j - 1]) {
            if(!btm[i][j]) btm[i][j] = btm[i][j - 1];
            if(!top[i][j]) top[i][j] = top[i][j - 1];
        }
        if(i + 1 < mat.size() && mat[i + 1][j]) {
            if(!btm[i][j]) btm[i][j] = btm[i + 1][j];
            if(!top[i][j]) top[i][j] = top[i + 1][j];
        }
        if(j + 1 < mat[0].size() && mat[i][j + 1]){
            if(!btm[i][j]) btm[i][j] = btm[i][j + 1];
            if(!top[i][j]) top[i][j] = top[i][j + 1];
        }
        if(i == mat.size() - 1) btm[i][j] = 1;
        if(!i) top[i][j] = 1;
        if(top[i][j] && btm[i][j]) return 1;
        if(btm[i][j]) state = 0;
        if(top[i][j]) state = 1;
        if(state < 0) return 0;
        if(search(mat, i + 1, j, state) || search(mat, i - 1, j, state) || search(mat, i, j + 1, state) || search(mat, i, j - 1, state)) return 1;
        return 0;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> mat(row, vector<int>(col, 0));
        top = mat, btm = mat;
        int r, c;
        for(int i = row * col - 1; i >= 0; i--) {
            r = cells[i][0] - 1, c = cells[i][1] - 1;
            mat[r][c] = 1;
            if(solve(mat, r, c)) return i;
        }
        return 0;
    }
};