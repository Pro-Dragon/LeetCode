class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, n = nums.size(), h = n - 1, mid;
        while(l <= h) {
            mid = (l + h) >> 1;
            if(nums[mid] < nums[h]) h = mid;
            else if(nums[mid] > nums[h]) l = mid + 1;
            else h--;
        }
        return nums[l];
    }
};