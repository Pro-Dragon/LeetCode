class Solution {
public:
    int countBinarySubstrings(string s) {
        int prv = 0, cur = 1, n = s.size(), bit = s[0], count = 0;
        for(int i = 1; i < n; i++) {
            if(bit == s[i]) cur++;
            else {
                bit = s[i];
                prv = cur;
                cur = 1;
            }
            if(cur <= prv) {
                count++; 
            }
        }
        return count;
    }
};