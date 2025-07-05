class Solution {
public:
    bool canwe(int val, vector<int> &nums, int k) {
        int cur = 0, count = 1, n = nums.size();
        for(int i = 0; i < n; i++) {
            cur += nums[i];
            if(cur > val) {
                count++;
                cur = nums[i];
            }
        }
        return count <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int l = 0, h = 0, n = nums.size(), res;
        for(int i = 0; i < n; i++) {
            l = max(l, nums[i]);
            h += nums[i];
        }
        while(l <= h) {
            int mid = (l + h) >> 1;
            if(canwe(mid, nums, k)) {
                res = mid;
                h = mid - 1;
            }
            else l = mid + 1;
        }
        return res;
    }
};