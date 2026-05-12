class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size(), res = 0, maxi = 0;
        sort(tasks.begin(), tasks.end(), [](vector<int> &a, vector<int> &b){
            return (a[1] - a[0]) > (b[1] - b[0]);
        });
        for(int i = 0; i < n; i++) {
            res += tasks[i][0];
            maxi = max(maxi, tasks[i][1]);
        }
        res = max(res, maxi);
        maxi = res;
        for(int i = 0; i < n; i++) {
            if(tasks[i][1] <= maxi) maxi -= tasks[i][0];
            else {
                res += (tasks[i][1] - maxi);
                maxi = (tasks[i][1] - tasks[i][0]);
            }
        }
        return res;
    }
};