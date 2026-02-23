class Solution {
public:
    bool hasAllCodes(string s, int k) {
        long long res = (1 << k), n = s.size(), count = 0;
        unordered_map<string, int> mp;
        string str;
        for(int i = 0; i <= n - k; i++) {
            str = s.substr(i, k);
            if(mp[str] == 0) {
                mp[str]++;
                count++;
            }
        }
        return (count == res);
    }
};