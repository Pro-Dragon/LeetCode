class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(60, 0);
        queue<int> qu;
        int n = s.size(), m = t.size(), cur = 0, l = 0, h = n;
        for(int i = 0; i < m; i++) freq[t[i] - 'A']++;
        for(int i = 0; i < n; i++) if(freq[s[i] - 'A']) qu.push(i);
        for(int i = 0; i < n; i++) {
            if(freq[s[i] - 'A'] > 0) cur++;
            freq[s[i] - 'A']--;
            if(cur == m) {
                while(freq[s[qu.front()] - 'A'] < 0) {
                    freq[s[qu.front()] - 'A']++;
                    qu.pop();
                }
                if(h - l > i - qu.front()) {
                    l = qu.front();
                    h = i;
                }
                freq[s[qu.front()] - 'A']++;
                cur--;
                qu.pop();
            }
        }
        if(h == n) return "";
        return s.substr(l, h - l + 1);
    }
};