class Solution {
public:
    int lastRemaining(int n) {
        int diff = 1, val = 1;
        for(int i = 1; n / 2; i++) {
            if(n % 2 || i % 2) val += diff;
            diff *= 2;
            n /= 2;
        }
        return val;
    }
};