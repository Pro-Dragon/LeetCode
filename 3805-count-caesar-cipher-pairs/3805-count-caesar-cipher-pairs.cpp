class Solution {
public:
    long long countPairs(vector<string>& words) {
        long long n = words.size(), count = 0, m, diff;
        unordered_map<string, long long> mp;
        for(int i = 0; i < n; i++) {
            m = words[i].size();
            if(words[i][0] != 'a') {
                diff = words[i][0] - 'a';
                for(int j = 0; j < m; j++) {
                    if(words[i][j] - diff < 'a') {
                        words[i][j] = 'z' - (diff - (words[i][j] - 'a')) + 1;
                    }
                    else words[i][j] -= diff;
                }
            }
            count += mp[words[i]];
            mp[words[i]]++;
        }
        return count;
    }
};