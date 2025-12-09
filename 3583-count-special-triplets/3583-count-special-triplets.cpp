class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size(), mod = 1e9 + 7;
        unordered_map<int, int> mp1, mp2;
        for(int i = n - 1; i >= 1; i--) mp2[nums[i]]++;
        mp1[nums[0]]++;
        long res = 0;
        for(int i = 1; i < n - 1; i++) {
            mp2[nums[i]]--;
            res += (long(mp1[nums[i] * 2]) * long(mp2[nums[i] * 2]));
            mp1[nums[i]]++;
            res %= mod;
        }
        return res;
    }
};