class Solution {
public:
    long long minMoves(vector<int>& balance) {
        int n = balance.size(), ind = -1;
        for(int i = 0; i < n; i++) if(balance[i] < 0) ind = i;
        if(ind < 0) return 0;
        int left = ind - 1, right = ind + 1;
        long long count = 0, val, res = 0, cur;  
        if(left < 0) left = n - 1;
        while((left != n - 1 || (right % n))) {
            if(left == (right % n)) cur = balance[left];
            else cur = balance[left] + balance[right % n];
            count += cur;
            val = count + balance[ind];
            if(val >= 0) {
                res += (long)(cur - val) * (right - ind);
                break;
            }
            else res += (long)(cur) * (right - ind);
            if(left == (right % n) || left == (right % n) + 1 || left + 1 == (right % n)) break;
            left--, right++;
            if(left < 0) left = n - 1;
        }
        return (count + balance[ind] >= 0) ? res : -1;
    }
};