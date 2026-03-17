class Solution {
public:
    int jump(vector<int>& nums) {
        int start = nums[0], n = nums.size(), maxi = 0, count = 1;
        for(int i = 1; i < n; i++) {
            start--;
            if(maxi + nums[maxi] < nums[i] + i) maxi = i;
            if(!start) {
                start = nums[maxi] - (i - maxi);
                if(i < n - 1) count++;
            }
        }
        return count - (n == 1);
    }
};