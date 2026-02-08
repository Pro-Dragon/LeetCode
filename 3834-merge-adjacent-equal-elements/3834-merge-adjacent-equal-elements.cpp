class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> res;
        long long n = nums.size();
        for(int i = 0; i < n; i++) {
            if(!res.empty() && res.back() == nums[i]) {
                res[res.size() - 1] *= 2;
                while(res.size() > 1 && res.back() == res[res.size() - 2]) {
                    res.pop_back();
                    res[res.size() - 1] *= 2;
                }
            }
            else res.push_back(nums[i]);
        }
        return res;
    }
};