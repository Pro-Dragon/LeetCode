class Solution {
public:
    void Dragon(int n, vector<string> &res, int i, int check, string str) {
        if(!check) {
            str += '0';
            if(i == n - 1) {
                res.push_back(str);
                return;
            }
            Dragon(n, res, i + 1, !check, str);
        }
        else {
            str += '1';
            if(i == n - 1) {
                res.push_back(str);
                return;
            }
            Dragon(n, res, i + 1, 0, str);
            Dragon(n, res, i + 1, 1, str);
        }
    }
    vector<string> validStrings(int n) {
        vector<string> res;
        string str;
        Dragon(n, res, 0, 0, str);
        Dragon(n, res, 0, 1, str);
        return res;
    }
};