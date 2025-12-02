class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> mp;
        long mod = 1e9 + 7, total = 0, res = 0, n = points.size();
        for(int i = 0; i < n; i++) mp[points[i][1]]++;
        for(auto val : mp) {
            long num = ((long) val.second * (val.second - 1));
            num = (num >> 1);
            res = (res + (total * num));
            total = (total + num);
            res %= mod;
        }
        return res;
    }
};