class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size(), len = 0, prv = 0, k;
        for(int i = 0 ; i < n; i++) {
            vector<int> freq(26, 0);
            for(int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                k = 0, prv = -1;
                while(k < 26) {
                    if(freq[k] && prv == -1) prv = freq[k];
                    else if(freq[k] && prv != -1 && prv != freq[k]) break;
                    k++;
                }
                if(k == 26) len = max(len, j - i + 1);
            }
        }
        return len;
    }
};