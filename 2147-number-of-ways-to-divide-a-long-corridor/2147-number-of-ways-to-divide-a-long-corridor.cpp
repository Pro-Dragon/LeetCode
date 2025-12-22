class Solution {
public:
    int numberOfWays(string corridor) {
        long long count = 0, res = 1, cur = 1, mod = 1e9 + 7, seats = 0, n = corridor.size();
        for(int i = 0; i < n; i++) {
            if(corridor[i] == 'S') {
                count++;
                seats++;
            }
            if(count == 2 && corridor[i] == 'P') {
                cur++;
            }
            else if(count == 3) {
                count -= 2;
                res = (res * cur) % mod;
                cur = 1;
            }
        }
        if(seats % 2 || seats < 2) return 0;
        return res;
    }
};