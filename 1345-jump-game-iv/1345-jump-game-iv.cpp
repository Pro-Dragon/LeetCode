class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size(), m, ind;
        if(n == 1) return 0;
        vector<int> vis(n, 0);
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }
        queue<int> qu;
        qu.push(0);
        vis[0] = 1;
        int i, moves = 0;
        while(!qu.empty()) {
            moves++;
            m = qu.size();
            while(m--) {
                i = qu.front();
                while(mp[arr[i]].size()) {
                    ind = mp[arr[i]].back();
                    if(ind == n - 1) return moves;
                    if(i != ind) qu.push(ind);
                    mp[arr[i]].pop_back();
                    vis[ind] = 1;
                }
                if(i + 1 < n && !vis[i + 1]) {
                    if(i + 1 == n - 1) return moves;
                    qu.push(i + 1);
                    vis[i + 1] = 1;
                }
                if(i - 1 > 0 && !vis[i - 1]) {
                    qu.push(i - 1);
                    vis[i - 1] = 1;
                }
                qu.pop();
            }
        }
        return moves;
    }
};