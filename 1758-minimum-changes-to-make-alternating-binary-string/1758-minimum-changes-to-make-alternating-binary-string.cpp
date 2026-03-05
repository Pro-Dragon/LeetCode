class Solution {
public:
    int minOperations(string s) {
        int count = 0, n = s.size();
        for(int i = 0; s[i]; i++) {
            if(i % 2 == s[i] - '0') count++;
        }
        return min(count, n - count);
    }
};