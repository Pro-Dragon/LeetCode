class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int maxi = 0, n = trips.size(), cur = 0;
        for(int i = 0; i < n; i++) maxi = max(trips[i][2], maxi);
        vector<int> res(maxi + 1, 0);
        for(int i = 0; i < n; i++) {
            res[trips[i][1]] += trips[i][0];
            res[trips[i][2]] -= trips[i][0];
        }
        for(int i = 0; i <= maxi; i++) {
            cur += res[i];
            if(cur > capacity) return 0;
        }
        return 1;
    }
};