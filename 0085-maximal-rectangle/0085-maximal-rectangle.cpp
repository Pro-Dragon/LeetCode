class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), maxi = 0, k, start = -1;
        vector<int> col(m, 0);
        vector<int>left(m, 0);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            start = -1;
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '1') {
                    if(start < 0) start = j;
                    col[j]++;
                    maxi = max(maxi, col[j]);
                    while(!st.empty() && (col[st.top()]) > col[j]) {
                        maxi = max(maxi, ((j - st.top()) + left[st.top()]) * (col[st.top()]));
                        left[st.top()] = 0;
                        st.pop();
                    }
                    if(!st.empty()) left[j] = (j - st.top()) - 1;
                    else left[j] = (j - start);
                    st.push(j);
                }
                if(matrix[i][j] == '0' || j == m - 1){
                    start = -1;
                    if(matrix[i][j] == '0') col[j] = 0;
                     while(!st.empty()) {
                        maxi = max(maxi, (((j + matrix[i][j] - '0') - (st.top())) + left[st.top()]) * (col[st.top()]));
                        left[st.top()] = 0;
                        st.pop();
                    }
                }
            }
        } 
        return maxi;
    }
};