class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size(), m = boxGrid[0].size();
        vector<vector<char>> res(m, vector<char> (n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                res[i][n - j - 1] = boxGrid[j][i];
            }
        }
        boxGrid = res;
        for(int i = 0; i < n; i++) {
            int ptr = -1;
            for(int j = 0; j < m; j++) {
                if(ptr < 0 && boxGrid[j][i] == '#') ptr = j;
                if(ptr >= 0 && boxGrid[j][i] == '.') {
                    swap(boxGrid[j][i], boxGrid[ptr][i]);
                    ptr++;
                }
                if(boxGrid[j][i] == '*') ptr = -1;
            }
        }
        return boxGrid;
    }
};