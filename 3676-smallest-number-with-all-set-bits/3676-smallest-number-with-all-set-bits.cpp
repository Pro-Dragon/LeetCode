class Solution {
public:
    int smallestNumber(int n) {
        int res = 0, i = 0;
        while(n >> i) {
            res += ((1 << (i)));
            i++; 
        }
        return res;
    }
};