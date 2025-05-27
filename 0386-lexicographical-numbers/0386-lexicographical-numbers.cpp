class Solution {
public:
    void slayer(int num, vector<int> &res) {
        int n = num;
        while(!(num % 10)) {
            num /= 10;
        }
        do{
            res.push_back(num);
            num *= 10;
        }while(num <= n);
    }
    int isvalid(int num, int n) {
        while(num >= n) num /= 10;
        return ++num;
    }
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        int num = pow(10, ((int)log10(n))), last = num;
        slayer(num, res);
        while(1) {
            num = isvalid(num, n);
            if(num == last) break;
            slayer(num, res);
        }
        return res;
    }
};