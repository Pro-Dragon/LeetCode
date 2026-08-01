class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map<int,int> mp1, mp2;
        vector<int> nums;
        for(int i = 0; i < planks.size(); i++){
            mp1[planks[i]]++;
            if(mp1[planks[i]] == 1) nums.push_back(planks[i]);
        }
        int n = nums.size(), maxi = 0;
        for(int i = 0; i < n; i++) {
            mp2[nums[i] + nums[i]] += (mp1[nums[i]] >> 1);
            for(int j = i + 1; j < n; j++) {
                mp2[nums[i] + nums[j]] += min(mp1[nums[i]], mp1[nums[j]]);
            }
        }
        for(int i = 0; i < planks.size(); i++) {
            mp2[planks[i]]++;
        }
        for(auto val : mp2) {
            maxi = max(val.second, maxi);
        }
        return maxi;
    }
};