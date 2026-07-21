class Solution {
public:
    void creator(vector<string> &res, string str, int check, int n, int opens) {
        if(str.size() == n * 2) {
            res.push_back(str);
            return;
        }
        if(opens < n)
        creator(res, str + '(', check + 1, n, opens + 1);
        if(check)
        creator(res, str + ')', check - 1, n, opens);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str;
        creator(res, str + '(', 1, n, 1);
        return res;
    }
};