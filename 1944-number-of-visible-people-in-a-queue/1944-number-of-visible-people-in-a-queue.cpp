class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> st;
        int n = heights.size(), count = 0;
        vector<int> res(n, 0);
        for(int i = n - 1; i >= 0; i--) {
            count = 0;
            while(!st.empty() && heights[st.top()] < heights[i]) {
                count++;
                st.pop();
            }
            if(st.size()) count++;
            res[i] = count;
            st.push(i);
        }
        return res;
    }
};