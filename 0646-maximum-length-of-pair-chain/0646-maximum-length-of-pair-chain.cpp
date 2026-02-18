class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size(), count = 1, l = pairs[0][0], r = pairs[0][1];
        for(int i = 1; i < n; i++) {
            if(pairs[i][0] > r) {
                l = pairs[i][0], r = pairs[i][1];
                count++;
            }
            else if(r > pairs[i][1]) l = pairs[i][0], r = pairs[i][1];
        }
        return count;
    }
};