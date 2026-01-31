class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        res[0] = {1};
        for(int i = 1; i < numRows; i++) {
            res[i].push_back(1);
            int j = 0;
            while(j < i - 1) {
                res[i].push_back(res[i - 1][j] + res[i - 1][j + 1]);
                j++;
            }
            res[i].push_back(1);
        }
        return res;
    }
};