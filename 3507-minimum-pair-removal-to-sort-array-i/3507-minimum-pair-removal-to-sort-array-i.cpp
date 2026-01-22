class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size(), ind1, ind2, mini = INT_MAX, pre, i, flag = 0;
        for(i = 0; i < n; i++) {
            flag = 0, pre = -1, mini = INT_MAX;
            for(int j = 0; j < n; j++) {
                if(nums[j] == 10000) continue;
                if(pre < 0) pre = j;
                if(nums[pre] > nums[j]) flag = 1;
                if(pre != j && mini > nums[j] + nums[pre]) {
                    ind1 = j;
                    ind2 = pre;
                    mini = nums[j] + nums[pre];
                }
                pre = j;
            }
            if(!flag) return i;
            nums[ind2] = mini;
            nums[ind1] = 10000;
        }
        return i;
    }
};