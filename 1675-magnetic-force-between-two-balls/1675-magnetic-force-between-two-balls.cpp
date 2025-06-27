class Solution {
public:
    bool check(int mid, vector<int>& nums, int m) {
        int prv = nums[0], n = nums.size(), count = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] - prv >= mid) {
                count++;
                prv = nums[i];
            }
            if(count >= m) return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int l = 1, h = position.back() - position[0], res;
        while(l <= h) {
            int mid = (l + h) >> 1;
            if(check(mid, position, m)) {
                res = mid;
                l = mid + 1;
            }
            else h = mid - 1;
        }
        return res;
    }
};