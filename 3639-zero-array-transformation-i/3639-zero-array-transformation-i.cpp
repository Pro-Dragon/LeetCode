class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m  = queries.size();
        vector<int> pre(n + 1);
        for(int i = 0; i < m; i++) {
            pre[queries[i][0]]++;
            pre[queries[i][1] + 1]--;
        }
        for(int i = 0; i < n; i++) {
            if(i) pre[i] += pre[i - 1];
            nums[i] -= pre[i];
            if(nums[i] > 0) return 0;
        }
        return 1;
    }
};