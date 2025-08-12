class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < n - 3; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1; j < n - 2; j++) {
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                int k = j + 1, l = n - 1;
                while(k < l) {
                    long sum = target;
                    sum -= nums[i];
                    sum -= nums[j];
                    sum -= nums[k];
                    sum -= nums[l];
                    if(sum > 0) k++;
                    else if(sum < 0) l--;
                    else {
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        while(k < l && nums[k] == nums[k - 1]) k++;
                    }
                }
            }
        }
        return res;
    }
};