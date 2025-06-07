class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_map<int, int> mp;
        vector<int> res;
        int n = x.size();
        for(int i = 0; i < n; i++) {
            if(mp.find(x[i]) != mp.end()) {
                if(y[mp[x[i]]]< y[i])  mp[x[i]] = i;
            }
            else mp[x[i]] = i;
        }
        for(auto &[ele, val] : mp) {
            res.push_back(y[val]);
        }
        if(res.size() < 3) return -1;
        sort(res.begin(), res.end(), greater<int>());
        return res[0] + res[1] + res[2];
    }
};