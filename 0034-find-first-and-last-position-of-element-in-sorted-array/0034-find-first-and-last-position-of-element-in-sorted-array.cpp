class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0)return {-1, -1};
        int l = 0, h = nums.size() - 1, mid, check = 0;
        while(l <= h){
            mid = (l + h) >> 1;
            if(nums[mid] == target) check = 1;
            if(nums[mid] >= target)h = mid - 1;
            else l = mid + 1;
        }
        if(!check) return {-1, -1};
        int start = l;
        l = 0, h = nums.size() - 1;
        while(l <= h){
            mid = (l + h) >> 1;
            if(nums[mid] <= target)l = mid + 1;
            else h = mid - 1;
        }
        return {start, h};
    }
};