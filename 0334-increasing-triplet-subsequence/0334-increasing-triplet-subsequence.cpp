class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        res.push_back(nums[0]);
        for(int i = 1; i < n; i++) {
            if(res.back() < nums[i]) {
                res.push_back(nums[i]);
                if(res.size() == 3) return 1;
            }
            else {
                auto index = std::lower_bound(res.begin(), res.end(), nums[i]) - res.begin();
                res[index] = nums[i];
            }
        }
        return 0;
    }
};