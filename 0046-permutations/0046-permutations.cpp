class Solution {
public:
    void creater(vector<vector<int>> &res, vector<int> ans, unordered_set<int> ust, vector<int> nums, int n){
        if(ans.size() == n){
            res.push_back(ans);
            return;
        }
        for(int i = 0; i < n; i++){
            if(ust.find(nums[i])==ust.end()) {
                ans.push_back(nums[i]);
                ust.insert(nums[i]);
                creater(res, ans, ust, nums, n);
                ans.pop_back();
                ust.erase(nums[i]);
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> ans;
        unordered_set<int>ust;
        creater(res, ans, ust, nums, n);
        return res;
    }
};