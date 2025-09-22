class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b) {
        return (a[0] - b[0] < a[1] - b[1]);
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size(), count = 0;
        sort(costs.begin(),costs.end(), comp);
        for(int i = 0; i < n; i++) {
            if(i < n / 2) count += costs[i][0];
            else count += costs[i][1];
        }
        return count;
    }
};