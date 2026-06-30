class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), a = -1, b = -1, c = -1, mini, count = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'a') a = i;
            if(s[i] == 'b') b = i;
            if(s[i] == 'c') c = i;
            mini = min({a, b, c});
            if(mini < 0) continue;
            count += (mini + 1);
        }
        return count;
    }
};