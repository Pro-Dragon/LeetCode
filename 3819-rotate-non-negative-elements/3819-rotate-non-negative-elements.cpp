class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        for(int i = 0; i < n; i++) if(nums[i] >= 0) res.push_back(nums[i]);
        if(res.empty()) return nums;
        k = k % res.size();
        for(int i = 0; i < k / 2; i++) swap(res[i], res[k - i - 1]);
        for(int i = k, j = res.size() - 1; i < j; i++, j--) swap(res[i], res[j]);
        reverse(res.begin(), res.end());
        for(int i = 0, j = 0; i < n; i++) if(nums[i] >= 0) nums[i] = res[j++];
        return nums;
    }
};