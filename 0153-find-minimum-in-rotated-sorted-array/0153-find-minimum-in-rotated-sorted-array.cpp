class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, h = n - 1, mini = INT_MAX;
        while(l <= h) {
            int mid = (l + h) >> 1;
            if(nums[mid] >= nums[l]) {
                mini = min(nums[l], mini);
                l = mid + 1;
            }
            else {
                mini = min(nums[mid], mini);
                h = mid - 1;
            }
        }
        return mini;
    }
};