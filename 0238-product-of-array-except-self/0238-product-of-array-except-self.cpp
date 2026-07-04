class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pro = 1;
        vector<int>res;
        res.push_back(1);
        for(int i = 0; i < nums.size() - 1; i++){
            pro *= nums[i];
            res.push_back(pro);
        }
        int n = res.size() - 1;
        pro = 1;
        for(int i = nums.size() - 1; i > 0; i--){
            pro *= nums[i];
            res[--n] *= pro;
        }
        return res;
    }
};