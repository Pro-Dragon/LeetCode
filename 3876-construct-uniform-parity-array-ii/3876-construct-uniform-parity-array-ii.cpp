class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd = 0, even = 0, n = nums1.size(), mini = nums1[0];
        for(int i = 0; i < n; i++) {
            if(nums1[i] % 2) odd++;
            else even++;
            mini = min(mini, nums1[i]);
        }
        return (mini % 2 == 0 && odd) ? 0 : 1;
    }
};