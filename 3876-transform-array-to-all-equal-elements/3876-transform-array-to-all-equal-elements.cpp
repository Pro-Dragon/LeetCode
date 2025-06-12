class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int count = 0, n = nums.size(), count1 = 0, count2 = 0, check1 = 0, check2 = 0;
        for(int i = 0; i < n; i++) {
            if(check1) count2++;
            if(check2) count1++;
            if(nums[i] < 0) {
                count++;
                check1 = !check1;
            }
            else check2 = !check2;
        }
        if(count % 2 && (n - count) % 2) return 0;
        if(!check1 && count2 <= k || !check2 && count1 <= k) return 1;
        return 0;
    }
};