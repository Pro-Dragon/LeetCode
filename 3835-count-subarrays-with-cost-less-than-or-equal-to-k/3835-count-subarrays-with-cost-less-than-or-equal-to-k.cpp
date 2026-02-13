class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        deque<int> dq1, dq2;
        long long n = nums.size(), count = 0;
        for(int i = 0, j = 0; i < n; i++) {
            while(!dq1.empty() && nums[i] > nums[dq1.back()]) dq1.pop_back();
            dq1.push_back(i);
            while(!dq2.empty() && nums[i] < nums[dq2.back()]) dq2.pop_back();
            dq2.push_back(i);
            while(j < i && (long)(nums[dq1.front()] - nums[dq2.front()]) * (i - j + 1) > k) {
                j++;
                while(!dq1.empty() && dq1.front() < j) dq1.pop_front();
                while(!dq2.empty() && dq2.front() < j) dq2.pop_front();
            }
            count += i - j + 1;
        }
        return count;
    }
};