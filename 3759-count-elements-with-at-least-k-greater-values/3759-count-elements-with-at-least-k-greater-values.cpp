class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        if(k == 0) return nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size(), ans = 0, val = nums[k - 1];
        for(int i = 0; i < n; i++) {
            if(val > nums[i]) ans++;
        }
        return ans;
    }
};