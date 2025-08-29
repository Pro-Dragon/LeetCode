class Solution {
public:
    long long flowerGame(int n, int m) {
        long res = (n / 2 + (n % 2));
        res *= (m / 2);
        long res1 = (n / 2);
        res1 *= (m / 2 + (m % 2));
        res += res1;
        return res;
    }
};