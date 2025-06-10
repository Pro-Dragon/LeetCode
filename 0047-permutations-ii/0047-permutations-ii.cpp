class Solution {
public:
    void amazon(vector<int>& nums, unordered_map<int, int> &mp, int n, vector<int> res, vector<vector<int>> &ans) {
        if(res.size() == n) {
            ans.push_back(res);
            return;
        }
        int prv = INT_MIN;
        for(int i = 0; i < n; i++) {
            if(prv != nums[i] && mp[nums[i]]) {
                mp[nums[i]]--;
                res.push_back(nums[i]);
                amazon(nums, mp, n, res, ans);
                res.pop_back();
                mp[nums[i]]++;
            }
            prv = nums[i];
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) mp[nums[i]]++;
        vector<int> res;
        vector<vector<int>> ans;
        amazon(nums, mp, n, res, ans);
        return ans;
    }
};