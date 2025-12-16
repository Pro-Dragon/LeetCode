class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), count = 0;
        for(int i = 0; i < n; i++) {
            if(!nums[i]) {
                count = (count % 2) ? (count) : count + 1;
            }
            else {
                count = (count % 2) ? (count + 1) : count;
            }
        }
        return count;
    }
};