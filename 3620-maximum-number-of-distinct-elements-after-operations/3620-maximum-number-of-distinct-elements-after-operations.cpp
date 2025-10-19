class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size(), count = 1, prv = nums[0] - k;
        for(int i = 1; i < n; i++) {
            int val = (prv + 1) - nums[i];
            if(val >= -k && val <= k) prv++;
            else if(val < -k) prv = nums[i] - k;
            else continue;
            count++;
        }
        return count;
    }
};