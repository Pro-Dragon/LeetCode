class Solution {
public:
    int lastRemaining(int n) {
        long long val = 1, diff = 1, size = n;
        for(int i = 0; val + diff <= n; i++) {
            if(!(i % 2) || (size % 2)) val = val + diff;
            diff = (long)diff * 2;
            size = (size / 2); 
        }
        return val;
    }
};