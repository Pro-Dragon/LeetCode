class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        res.push_back(nums[0]);
        for(int i = 1; i < n; i++) {
            if(res.back() < nums[i]) {
                if(res.size() == 2) return 1;
                res.push_back(nums[i]);
            }
            else {
                if(res.size() == 2) {
                    if(nums[i] > res[0]) res[1] = nums[i];
                    else res[0] = nums[i];
                }
                else {
                    res[0] = nums[i];
                }
            }
        }
        return 0;
    }
};