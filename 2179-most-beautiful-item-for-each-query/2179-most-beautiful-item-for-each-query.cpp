class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = queries.size(), m = items.size();
        unordered_map<int, vector<int>> mp;
        vector<int> res(n);
        for(int i = 0; i < n; i++) mp[queries[i]].push_back(i);
        sort(items.begin(), items.end());
        sort(queries.begin(), queries.end());
        int maxi = items[0][1], k;
        for(int i = 0, j = 0; i < n; i++) {
            if(queries[i] < items[0][0]) {
                queries[i] = 0;
                continue;
            }
            while(j < m - 1 && items[j + 1][0] <= queries[i]) maxi = max(items[++j][1], maxi);
            res[mp[queries[i]].back()] = maxi;
            mp[queries[i]].pop_back();
        }
        return res;
    }
};