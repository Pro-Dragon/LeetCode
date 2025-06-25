class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prv = -1, cur = 0, res = 0, n = bank.size(), m = bank[0].size();
        for(int i = 0; i < n; i++) {
            cur = count(bank[i].begin(),bank[i].end(),'1');  
            if(prv > 0 && cur > 0) res += (prv * cur);
            if(cur > 0) prv = cur;
        }
        return res;
    }
};