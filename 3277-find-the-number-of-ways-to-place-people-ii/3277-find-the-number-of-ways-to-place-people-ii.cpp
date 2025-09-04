class Solution {
public:
    static bool cmp(const vector<int> &v1, const vector<int> &v2) {
        if(v1[0] != v2[0]) return v1[0] < v2[0];
        else return v1[1] > v2[1];
    } 
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int n = points.size(), count = 0;
        for(int i = 0; i < n; i++) {
            int maxi = INT_MIN;
            for(int j = i + 1; j < n; j++) {
                if(points[i][1] >= points[j][1] && maxi < points[j][1]) {
                    maxi = points[j][1];
                    count++;
                }
            }
        }
        return count;
    }
};