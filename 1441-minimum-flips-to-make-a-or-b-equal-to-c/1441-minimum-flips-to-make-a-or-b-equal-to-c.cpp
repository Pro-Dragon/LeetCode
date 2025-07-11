class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res = 0;
        while(a || b || c) {
            if((c & 1) != ((a | b) & 1)) {
                if((c & 1) == 0) res += ((a & 1) + (b & 1));
                else res++;
            }
            a >>= 1;
            b >>= 1;
            c >>= 1; 
        }
        return res;
    }
};