class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> res;
        int n = nums.size(), val;
        res.push_back(nums[0]);
        for(int i = 1; i < n; i++) {
            val = nums[i];
            while(res.size() && gcd(res.back(), val) > 1) {
                val = lcm(res.back(), val);
                res.pop_back();
            }
            res.push_back(val);
        }
        return res;
    }
};