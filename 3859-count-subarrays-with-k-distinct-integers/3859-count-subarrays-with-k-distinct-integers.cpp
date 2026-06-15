class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {
        int n = nums.size(), start = 0, unique_count = 0, freq_count = 0;
        long long res = 0;
        unordered_map<int, int> mp;
        for(int i = 0, j = 0; i < n; i++) {
            if(!mp[nums[i]]) unique_count++;
            mp[nums[i]]++;
            if(mp[nums[i]] == m) freq_count++;
            if(unique_count == k && freq_count == k) {
                while(mp[nums[j]] > m) {
                    mp[nums[j]]--;
                    j++;
                }
                res += (j - start + 1);
                //cout<<res<<endl;
            }
            else if(unique_count > k) {
                start = j;
                while(start < i && unique_count > k) {
                    if(mp[nums[start]] == m) freq_count--;
                    mp[nums[start]]--;
                    if(!mp[nums[start]]) {
                        unique_count--;
                    }
                    start++;
                }
                j = start;
                if(unique_count == k && freq_count == k) {
                    while(mp[nums[j]] > m) {
                        mp[nums[j]]--;
                        j++;
                    }
                    res += (j - start + 1);
                    //cout<<res<<endl;
                }
            }
        }
        return res;
    }
};