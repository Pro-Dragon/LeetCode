class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        long n = nums.size(), count = 0;
        stack<int> st;
        st.push(0);
        for(int i = 1; i < n; i++) {
            int cnt = -1;
            while(!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
                cnt++;
            }
            if(!st.empty() && i - st.top() + 1 >= 3) count++;
            st.push(i);
            if(cnt > 0) count += cnt;
        }
        return count;
    }
};