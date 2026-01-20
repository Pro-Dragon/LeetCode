class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        unordered_map<int, int> mp;
        int count = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] != target[i]) {
                if(mp[nums[i]] > 0) continue;
                mp[nums[i]] = 1;
                count++;
            }
        }
        return count;
    }
};