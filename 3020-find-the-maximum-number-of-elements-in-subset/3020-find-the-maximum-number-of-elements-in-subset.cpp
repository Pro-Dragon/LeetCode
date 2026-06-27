class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long, long> freq, vis;
        int n = nums.size(), maxi = 0, cur = 0;
        long val;
        for(int i = 0; i < n; i++) {
            freq[nums[i]]++;
            if(nums[i] == 1) cur++;
        }
        maxi = cur - !(cur % 2);
        cur = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) continue;
            val = nums[i];
            cur = 0;
            while(freq[val] > 1 && !vis[val]) {
                vis[val] = 1;
                cur += 2;
                val *= val;
            }
            if(!freq[val]) cur--;
            else if(freq[val] == 1) cur++;
            else if(vis[val]) cur += vis[val];
            maxi = max(maxi, cur);
            vis[nums[i]] = cur;
        }
        return maxi;
    }
};