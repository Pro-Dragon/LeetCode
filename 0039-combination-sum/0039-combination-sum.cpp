class Solution {
public:
    void solver(vector<int>& nums, int target, vector<vector<int>> &res, vector<int> arr, int cur, int n, int sum) {
        if(cur == n) return;
        arr.push_back(nums[cur]);
        int n1 = arr.size() - 1;
        for(int i = cur; i < n; i++) {
            arr[n1] = nums[i];
            sum += nums[i];
            if(sum == target) res.push_back(arr);
            if(sum < target)
            solver(nums, target, res, arr, i, n, sum);
            sum -= nums[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        int n = candidates.size();
        solver(candidates, target, res, {}, 0, n, 0);
        return res;
    }
};