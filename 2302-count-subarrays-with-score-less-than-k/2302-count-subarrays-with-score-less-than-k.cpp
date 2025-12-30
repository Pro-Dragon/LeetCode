class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long n = nums.size(), count = 0, j = 0, cur = 0, dis;
        for(int i = 0; i < n; i++) {
            cur += nums[i];
            dis = (i - j + 1);
            while(j <= i && (long) dis * cur >= k) {
                cur -= nums[j];
                j++;
                dis--;
            }
           if(j <= i) count += dis;
        }
        return  count;
    }
};