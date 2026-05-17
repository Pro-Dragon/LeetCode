class Solution {
public:
    bool solve(vector<int> &arr, int start, vector<int> &res) {
        if(start < 0 || start >= arr.size() || res[start]) return 0;
        if(!arr[start]) return 1;
        res[start] = 1;
        if(solve(arr, start + arr[start], res) || solve(arr, start - arr[start], res)) return 1;
        return 0;
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> res(n, 0);
        return solve(arr, start, res);
    }
};