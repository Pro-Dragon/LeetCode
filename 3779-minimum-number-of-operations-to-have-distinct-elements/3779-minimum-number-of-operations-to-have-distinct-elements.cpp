class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mappy;
        int cnt = 0, ans = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            mappy[nums[i]]++;
            if(mappy[nums[i]] == 2) cnt++;
        }
        if(!cnt) return 0;
        for(int i = 0; i < n; i+=3) {
            mappy[nums[i]]--;
            if(mappy[nums[i]] == 1) cnt--;
            if(i < n - 2) {
                mappy[nums[i + 1]]--;
                if(mappy[nums[i + 1]] == 1) cnt--;
            }
            if(i < n - 2) {
                mappy[nums[i + 2]]--;
                if(mappy[nums[i + 2]] == 1) cnt--;
            }
            ans++;
            if(cnt <= 0) break;
        }
        return ans;
    }
};