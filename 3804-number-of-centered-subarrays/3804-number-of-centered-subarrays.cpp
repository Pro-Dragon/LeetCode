class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        unordered_map<int, int> mp;
        int sum = 0, count = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            sum = 0;
            for(int j = i; j < n; j++) {
                sum += nums[j];
                mp[nums[j]]++;
                if(mp[sum] > 0) count++;
            }
            for(int j = i; j < n; j++) {
                mp[nums[j]]--;
            }
        }
        return count;
    }
};