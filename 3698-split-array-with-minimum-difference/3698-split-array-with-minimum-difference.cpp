class Solution {
public:
    long long splitArray(vector<int>& nums) {
        long long n = nums.size(), leftsum = 0, rightsum = 0, left = n - 1, right = 0;
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] < nums[i + 1]) leftsum += nums[i];
            else {
                left = i;
                break;
            }
        }
        for(int i = n - 1; i > 0; i--) {
            if(nums[i] < nums[i - 1]) rightsum += nums[i];
            else {
                right = i;
                break;
            }
        }
        if(left == right) return min(abs((leftsum + nums[left]) - rightsum), abs((rightsum + nums[left]) - leftsum));
        else if(left + 1 == right) return abs(leftsum - rightsum);
        return -1;
    }
};