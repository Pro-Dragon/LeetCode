class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int n = s.size(), count = 0, mod = 1e9 + 7;
        vector<int> freq(26, 0);
        for(int i = 0; i < n; i++) freq[s[i] - 'a']++;
        for(int i = 0; i < t; i++) {
            int nxt = freq[25];
            for(int j = 25; j > 0; j--) {
                freq[j] = (freq[j - 1]) % mod;
            }
            freq[0] = nxt;
            freq[1] = (freq[1] + nxt) % mod;
        }
        for(int i = 0; i < 26; i++) count = ((count + freq[i]) % mod);
        return count;
    }
};