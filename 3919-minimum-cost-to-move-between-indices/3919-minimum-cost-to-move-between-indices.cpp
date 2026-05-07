class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<long> res(n, 0), right(n, 0), left(n, 0);
        vector<int> ans(queries.size(), 0);
        res[0] = 1;
        res[n - 1] = n - 2;
        for(int i = 1; i < n - 1; i++) {
            if(abs(nums[i] - nums[i - 1]) > abs(nums[i] - nums[i + 1])) {
                res[i] = i + 1;
            }
            else res[i] = i - 1;
        }
        right[0] = 1;
        for(int i = 1; i < n - 1; i++) {
            if(res[i] > i) right[i] = right[i - 1] + 1;
            else {
                right[i] = right[i - 1] + abs(nums[i + 1] - nums[i]);
            }
        }
        left[n - 1] = 1;
        for(int i = n - 2; i > 0; i--) {
            if(res[i] < i) left[i] = left[i + 1] + 1;
            else {
                left[i] = left[i + 1] + abs(nums[i - 1] - nums[i]);
            }
        }
        for(int i = 0; i < queries.size(); i++) {
            if(queries[i][0] < queries[i][1]) {
                if(!queries[i][0]) ans[i] = right[queries[i][1] - 1];
                else ans[i] = right[queries[i][1] - 1] - right[queries[i][0] - 1];
            }
            else if(queries[i][0] > queries[i][1]){
                if(queries[i][0] == n - 1) ans[i] = left[queries[i][1] + 1];
                else ans[i] = left[queries[i][1] + 1] - left[queries[i][0] + 1];
            }
        }
        return ans;
    }
};