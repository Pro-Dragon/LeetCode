class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](vector<int> &a, vector<int> &b){ 
            if(a[1] < b[1]) return 1;
            return 0;
        });
        int n = events.size(), res = events[0][2], cur = res, j;
        vector<int> ends(n), vals(n);
        for(int i = 1; i < n; i++) {
            cur = max(cur, events[i][2]);
            ends[i] = events[i][1];
            vals[i] = events[i][2];
            events[i][2] = cur;
        }
        for(int i = 0; i < n; i++) {
            if(events[0][1] < events[i][0]) {
                //cout<<"hi";
                auto ind = upper_bound(ends.begin(), ends.end(), events[i][0] - 1) - (ends.begin());
                if(ind != n) {
                    ind--;
                    cur = max(cur, events[ind][2] + vals[i]);
                }
            }
        }
        return cur;
    }
};