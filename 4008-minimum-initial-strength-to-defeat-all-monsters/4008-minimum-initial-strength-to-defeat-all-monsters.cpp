class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n = monsters.size(), flag = 0;
        vector<long long> res(n + 1, 0);
        for(int i = 0; i < boosts.size(); i++) {
            res[boosts[i][0]] += boosts[i][2];
            res[boosts[i][1] + 1] -= boosts[i][2];
        }
        long long ans = 0, cur = 0, prv = 0;
        for(int i = 0; i < n; i++) {
            cur += res[i];
            if(monsters[i] > cur) res[i] = monsters[i] - cur;
            else res[i] = 0;
        }
        for(int i = n - 1; i >= 0; i--) {
            if(flag) ans += monsters[i];
            if(res[i] && !flag) {
                ans += res[i];
                flag = 1;
            }
        }
        return ans;
    }
};