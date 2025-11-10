class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;
        int n = nums.size(), count = 0;
        for(int i = 0; i < n; i++) {
            while(st.size() && st.top() >= nums[i]) {
                if(nums[i] != st.top()) count++;
                st.pop();
            }
            if(nums[i]) st.push(nums[i]);
        } 
        return count + st.size();
    }
};