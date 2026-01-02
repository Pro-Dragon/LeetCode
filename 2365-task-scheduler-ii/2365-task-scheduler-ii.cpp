class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<long, long> mp;
        long long n = tasks.size(), count = 0, dis;
        for(int i = 0; i < n; i++) {
            if(mp.find(tasks[i]) != mp.end()) {
                dis = (count - mp[tasks[i]]);
                if(dis < space) count += (space - dis); 
            }
            count++;
            mp[tasks[i]] = count;
        }
        return count;
    }
};