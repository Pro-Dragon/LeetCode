class Solution {
public:
    void Dragon(int k, int n, int sum, vector<int> cur, vector<vector<int>> &res, int i) {
        if(sum > n || cur.size() == k) return;
        if(i) cur.push_back(i);
        if(sum == n && cur.size() == k) {
            res.push_back(cur);
            return;
        }
        i++;
        while(i < 10) {
            Dragon(k, n, sum + i, cur, res, i);
            i++;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> cur;
        Dragon(k, n, 0, cur, res, 0);
        return res;
    }
};