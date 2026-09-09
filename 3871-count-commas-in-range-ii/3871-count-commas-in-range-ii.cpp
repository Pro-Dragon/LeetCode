class Solution {
public:
    long long countCommas(long long n) {
        return max(0LL, (long long)(n - 1e3) + 1) + max(0LL, (long long)(n - 1e6) + 1) + max(0LL, (long long)(n - 1e9) + 1) + max(0LL, (long long)(n - 1e12) + 1) + max(0LL, (long long)(n - 1e15) + 1);
    }
};