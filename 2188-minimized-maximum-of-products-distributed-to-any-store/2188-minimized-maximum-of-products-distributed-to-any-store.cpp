class Solution {
public:
    bool canwe(int val, vector<int> &nums, int n) {
        int m = nums.size(), count = 0;
        for(int i = 0; i < m; i++) {
            count += (nums[i] / val) + ((nums[i] % val) ? 1 : 0);
            if(count > n) return 1;
        }
        return 0;
    }
    int minimizedMaximum(int n, vector<int>& nums) {
        int l = 1, h = *max_element(nums.begin(), nums.end());
        while(l <= h){
            int mid = (l + h) >> 1;
            if(canwe(mid, nums, n)) {
                l = mid + 1;
            }
            else {
                h = mid - 1;
            }
        }
        return l;
    }
};