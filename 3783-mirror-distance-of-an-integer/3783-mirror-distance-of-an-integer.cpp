class Solution {
public:
    int mirrorDistance(int n) {
        int res = 0, ele = n;
        while(n > 0) {
            int val = n % 10;
            res = (res * 10) + val;
            n /= 10;
        }
        int ans = abs(res - ele);
        return ans;
    }
};