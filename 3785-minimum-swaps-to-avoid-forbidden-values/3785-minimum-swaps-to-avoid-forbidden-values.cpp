class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        vector<pair<int, int>> e;
        vector<int> temp;
        unordered_map<int, vector<int>> mp;
        int n = nums.size(), val = -1, count = 0, res = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == forbidden[i]) {
                e.push_back({nums[i], i});
                mp[nums[i]].push_back(i);
            }
        }
        for(auto val : mp) {
            e.push_back({val.second.size(), val.first});
        }
        sort(e.begin(), e.end());
        for(int i = e.size() - 1; i >= 0 ; i--) {
            while(mp[e[i].second].size()) {
                if(!temp.empty() && val != e[i].second) {
                    swap(nums[temp.back()], nums[mp[e[i].second].back()]);
                    temp.pop_back();
                    res++;
                }
                else if(val == e[i].second || temp.empty()){
                    temp.push_back(mp[e[i].second].back());
                    val = e[i].second;
                }
                mp[e[i].second].pop_back();
            }
            
        }
        for(int i = 0; i < n; i++) {
            if(!temp.empty() && nums[i] != forbidden[i] && forbidden[i] != val && nums[i] != val) {
                temp.pop_back();
                res++;
            }
        }
        if(!temp.empty()) return -1;
        return res;
    }
};