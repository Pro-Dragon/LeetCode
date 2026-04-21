class Solution {
public:
    unordered_map<int, vector<int>> mp;
    unordered_map<int, unordered_map<int, int>> freq;
    int key = 1;
    void solve(vector<int> &res, int ind, vector<int> &s) {
        int n = mp[ind].size(), val;
        for(int i = 0; i < n; i++) {
            val = mp[ind][i];
            if(!res[val]) {
                res[val] = key;
                freq[key][s[val]]++;
                solve(res, val, s);
            }
        }
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n1 = allowedSwaps.size(), n = source.size(), count = 0;
        for(int i = 0; i < n1; i++) {
            mp[allowedSwaps[i][0]].push_back(allowedSwaps[i][1]);           
            mp[allowedSwaps[i][1]].push_back(allowedSwaps[i][0]);           
        }
        vector<int> res(n, 0);
        for(int i = 0; i < n; i++) {
            if(!res[i]) {
                res[i] = key;
                freq[key][source[i]]++;
                solve(res, i, source);
            }
            if(!freq[res[i]][target[i]]) {
                count++;
            }
            if(freq[res[i]][target[i]] > 0) freq[res[i]][target[i]]--;
            key++;
        }
        return count;
    }
};