class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size(), l = 0, h = n - 1, mid;
        while(l <= h) {
            mid = (l + h) >> 1;
            if(target == nums[mid]) return 1;
            if(nums[mid] > nums[l]) {
                if(target < nums[mid] && target >= nums[l]) h = mid - 1;
                else l = mid + 1;
            }
            else if(nums[mid] < nums[h]) {
                if(target > nums[mid] && target <= nums[h]) l = mid + 1;
                else h = mid - 1;
            }
            else {
                while(l <= h) {
                    if(nums[l] == target) return 1;
                    l++;
                }
                return 0;
            }
        }
        return 0;
    }
};