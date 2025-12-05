class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        set<int> s;
        vector<int> res;
        int n = arrival.size(), maxi = 0;
        vector<int> freq(k, 0);
        for(int i = 0; i < k; i++) s.insert(i);
        for(int i = 0; i < n; i++) {
            while(!pq.empty() && pq.top().first <= arrival[i]) {
                s.insert(pq.top().second);  
                pq.pop();
            }
            if(s.empty()) continue;
            auto val = s.lower_bound(i % k);
            if (val != s.end()) {
                freq[*val]++;
                pq.push({arrival[i] + load[i], *val});
                maxi = max(maxi, freq[*val]);
                s.erase(*val);
            }
            else {
                pq.push({arrival[i] + load[i], *s.begin()});
                freq[*s.begin()]++;
                maxi = max(maxi, freq[*s.begin()]);
                s.erase(*s.begin());
            }
        }
        for(int i = 0; i < k; i++) {
           if(maxi == freq[i]) res.push_back(i);
        }
        return res;
    }
};