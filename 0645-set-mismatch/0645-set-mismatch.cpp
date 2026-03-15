class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size(), dup;
        vector<int> freq(n + 1, 0);
        for(int i = 0; i < n; i++) {
           freq[nums[i]]++;
           if(freq[nums[i]] > 1) dup = nums[i];
        }
        for(int i = 1; i <= n; i++) if(!freq[i]) return {dup, i};
        return {};
    }
};