class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        vector<int> left(n, 1e9), right(n, 1e9);
        int n1 = restrictions.size(), maxi = 0;
        for(int i = 0; i < n1; i++) {
            left[restrictions[i][0]] = restrictions[i][1];
            right[restrictions[i][0]] = restrictions[i][1];
        }
        left[0] = 0, right[0] = 0;
        for(int i = 1; i < n; i++) {
            left[i] = min(left[i], left[i - 1] + diff[i - 1]);
        }
        maxi = left[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            right[i] = min(right[i], right[i + 1] + diff[i]);
            maxi = max(maxi, min(right[i], left[i]));
        }
        return maxi;
    }
};