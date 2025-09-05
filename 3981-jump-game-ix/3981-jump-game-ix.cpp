class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size(), mini = n - 1;
        vector<int> res(n);
        res[0] = nums[0];
        for(int i = 1; i < n; i++) res[i] = max(nums[i], res[i - 1]);
        deque<int> dq;
        dq.push_back(n - 1);
        for(int i = n - 2; i >= 0; i--) {
            while(mini > i && nums[mini] >= res[i]) mini--;
            while(!dq.empty() && mini < dq.front()) dq.pop_front();
            if(!dq.empty() && res[i] > nums[mini]) {
                res[i] = max(res[i], nums[dq.front()]);
                res[i] = max(res[i], res[mini]);
            }
            while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
        }
        return res;
    }
};