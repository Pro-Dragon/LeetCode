class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> pq;
        int n = classes.size();
        for(int i = 0; i < n; i++) {
            pq.push({((double)(classes[i][0] + 1) / (classes[i][1] + 1)) - ((double)classes[i][0] / classes[i][1]), i});
        }
        while(extraStudents--) {
            int index = pq.top().second;
            classes[index][0]++;
            classes[index][1]++;
            pq.pop();
            pq.push({((double)(classes[index][0] + 1) / (classes[index][1] + 1)) - ((double)classes[index][0] / classes[index][1]), index});
        }
        double res = 0;
        for(int i = 0; i < n; i++) {
            res += ((double)classes[i][0] / classes[i][1]);
        }
        res /= n;
        return res;
    }
};