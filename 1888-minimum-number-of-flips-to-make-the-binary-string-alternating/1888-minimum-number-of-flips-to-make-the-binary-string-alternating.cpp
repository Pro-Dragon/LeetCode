class Solution {
public:
    int minFlips(string s) {
        int even = 0, n = s.size(), mini = n, odd = 0;
        for(int i = 0; s[i]; i++) {
            if(i % 2 == s[i] - '0') odd++;
        }
        even = n - odd;
        for(int i = 0; i < n; i++) {
            mini = min(mini, min(odd, even));
            odd -= !(s[i] - '0');
            even -= (s[i] - '0');
            odd = ((n - 1) - odd) + ((n - 1) % 2 == s[i] - '0');
            even = n - odd;
        }
        return min(mini, min(odd, even));
    }
};