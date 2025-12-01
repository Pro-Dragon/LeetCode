class Solution {
public:
    int rev(int n) {
        int res = 0;
        while(n > 0) {
            res = res * 10 + n % 10;
            n /= 10;
        }
        return res;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size(), res = n + 1;
        for(int i = 0; i < n; i++) {
            int val = rev(nums[i]);
            if(mp.find(nums[i]) != mp.end()) {
                res = min(res, abs(mp[nums[i]] - i));
            }
            mp[val] = i;
        }
        if(res == n + 1) return -1;
        return res;
    }
};