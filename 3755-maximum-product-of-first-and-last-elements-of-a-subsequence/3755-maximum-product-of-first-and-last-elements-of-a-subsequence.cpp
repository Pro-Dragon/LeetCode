class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        long long n = nums.size(), res = nums[n - 1], maxi = nums[0], mini = nums[0], temp1, temp2;
        res = res * maxi;
        for(int j = m - 1; j < n; j++) {
            int i = j - m + 1;
            if(maxi < nums[i]) maxi = nums[i];
            if(mini > nums[i]) mini = nums[i];
            temp1 = maxi * nums[j];
            temp2 = mini * nums[j];
            if(res < temp1) res = temp1;
            if(res < temp2) res = temp2;
        }
        return res;
    }
};