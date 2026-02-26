class Solution {
public:
    long getmax(long maxi, long val, int mini) {
        return ((long)mini * val > maxi) ? (long)mini * val : maxi;
    }
    int maximumScore(vector<int>& nums, int k) {
        long long left = k - 1, right = k + 1, maxi = nums[k], n = nums.size();
        int mini = nums[k];
        while(left >= 0 || right < n) {
            while (left >= 0 && mini < nums[left]) {
                left--;
                maxi = getmax(maxi, (right - left) - 1, mini);
            }
            while (right < n && mini < nums[right]) {
                right++;
                maxi = getmax(maxi, (right - left) - 1, mini);
            }
            if(left < 0) mini = min(mini, nums[right++]);
            else if(right >= n) mini = min(mini, nums[left--]);
            else {
                if(nums[left] < nums[right]) mini = min(mini, nums[right++]);
                else {
                    if(nums[left] == nums[right]) mini = min(mini, nums[right++]);
                    mini = min(mini, nums[left--]); 
                }               
            }
            maxi = getmax(maxi, (right - left) - 1, mini);
        }
        return maxi;
    }
};