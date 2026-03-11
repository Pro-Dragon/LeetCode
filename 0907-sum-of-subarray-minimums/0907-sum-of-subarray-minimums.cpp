class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        long long n = arr.size(), count = 0, ind, left, right, mod = 1e9 + 7;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                ind = st.top();
                st.pop();
                right = i - ind;
                if(!st.empty()) left = ind - st.top();
                else left = ind + 1;
                long val = (long)left * right;
                count = (count + ((long)arr[ind] * val) % mod) % mod;
            }
            st.push(i);
        }
        while(!st.empty()) {
            ind = st.top();
            st.pop();
            right = n - ind;
            if(!st.empty()) left = ind - st.top();
            else left = ind + 1;
            long val = (long)left * right;
            count = (count + ((long)arr[ind] * val) % mod) % mod;
        }
        return count;
    }
};