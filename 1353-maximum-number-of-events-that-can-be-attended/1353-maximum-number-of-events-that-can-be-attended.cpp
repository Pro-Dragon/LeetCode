class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int maxdate = 0, n = events.size(), count = 0;
        for(int i = 0; i < n; i++) {
            maxdate = max(events[i][1], maxdate);
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 1, j = 0; i <= maxdate; i++) {
            while(j < n && events[j][0] <= i) {
                pq.push(events[j][1]);
                j++;
            }
            while(!pq.empty() && pq.top() < i) pq.pop();
            if(!pq.empty()) {
                count++;
                pq.pop();
            }
        }
        return count;
    }
};