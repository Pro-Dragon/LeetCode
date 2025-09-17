class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(), l = 0, h = n - 1;
        if(n == 1) return nums[0];
        while(l <= h) {
            int mid = (l + h) >> 1, size = mid - l;
            if(!mid && nums[mid] != nums[mid + 1] || mid == n - 1 && nums[mid - 1] != nums[mid]) return nums[mid];
            if(mid > 0 && nums[mid - 1] != nums[mid] && mid < n - 1 && nums[mid + 1] != nums[mid]) {
                return nums[mid];
            }
            if(nums[mid] == nums[mid - 1]) {
                if(!(size % 2)) h = mid - 2;
                else l = mid + 1;
            }
            else {
                if(size % 2) h = mid - 1;
                else l = mid + 2;
            }
        }
        return -1;
    }
};