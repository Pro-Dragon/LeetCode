class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long res = 1;
        if(costBoth < cost1 + cost2) {
            res = (long)costBoth * min(need1, need2);
            if(need1 > need2) {
                res = res + (long)((costBoth < cost1) ? costBoth : cost1) * abs(need1 - need2);
            }
            else {
                res = res + (long)((costBoth < cost2) ? costBoth : cost2) * abs(need1 - need2);
            }
        }
        else {
            res = (long)cost1 * need1;
            res = res + (long) cost2 * need2;
        }
        return res;
    }
};