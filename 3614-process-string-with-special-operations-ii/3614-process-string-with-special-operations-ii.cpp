class Solution {
public:
    char processStr(string s, long long k) {
        long long n = s.size(), n1 = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] >= 'a' && s[i] <= 'z') n1++;
            else if(s[i] == '*' && n1) n1--;
            else if(s[i] == '#') n1 *= 2;
        }
        if(!n1 || n1 <= k) return '.';
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '*') n1++;
            else if(s[i] == '#') {
                n1 /= 2;
                if(k >= n1) k -= n1;
            }
            else if(s[i] == '%') k = n1 - k - 1;
            else n1--;
            if(k == n1 && s[i] >= 'a' && s[i] <= 'z') return s[i];
        }
        return '.';
    }
};