class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size(), mini = n;
        sort(nums.begin(), nums.end());
        for(int i = 0, j = 0; i < n; i++) {
            while(j < n && (long)nums[i] * k >= nums[j]) j++;
            mini = min(mini, i + (n - j));
        }
        return mini;
    }
};