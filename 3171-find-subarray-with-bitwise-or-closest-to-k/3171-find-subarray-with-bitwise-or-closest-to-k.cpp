class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size(), res = INT_MAX, cur = 0, val, l, temp;
        vector<int> freq(32, 0);
        for(int i = 0, j = 0; i < n; i++) {
            cur |= nums[i];
            l = 0, val = nums[i];
            while(val) {
                if(val & 1) freq[l]++;
                val >>= 1;
                l++;
            }
            res = min(res, abs(cur - k));
            while(cur > k && j < i) { 
                l = 0;
                val = nums[j];
                while(val) {
                    if(val & 1) {
                        freq[l]--;
                        if(!freq[l]) {
                            cur -= (1 << l);
                        }
                    }
                    val >>= 1;
                    l++;
                }
                res = min(res, abs(cur - k));
                j++;
            }
        }
        return res;
    }
};