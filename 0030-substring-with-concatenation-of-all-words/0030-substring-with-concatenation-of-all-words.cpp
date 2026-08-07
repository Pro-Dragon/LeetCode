class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> mp;
        vector<int> res;
        int m = words.size(), n = s.size(), k = words[0].size(), start;
        for(int i = 0; i < m; i++) {
            mp[words[i]]++;
        }
        string str, cur;
        unordered_map<string, int> path_map;
        for(int i = 0; i < k; i++) {
            start = -1;
            for(int j = i; j + k <= n; j += k) {
                str = s.substr(j, k);
                if(mp[str] > 0) {
                    if(start < 0) start = j;
                    path_map[str]++;
                    while(path_map[str] > mp[str]) {
                        cur = s.substr(start, k);
                        path_map[cur]--;
                        start += k;
                    }
                }
                else if(start >= 0){
                    while(start < j) {
                        cur = s.substr(start, k);
                        path_map[cur]--;
                        start += k;
                    }
                    start = -1;
                }
                if(start >= 0 && ((j + k) - start) / k == m) res.push_back(start);
            }
            if(start >= 0){
                while(start + k <= n) {
                    cur = s.substr(start, k);
                    path_map[cur]--;
                    start += k;
                }
            }
        }
        return res;
    }
};