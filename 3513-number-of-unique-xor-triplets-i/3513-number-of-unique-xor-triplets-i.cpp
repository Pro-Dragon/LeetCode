class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size(), power = (log2(n));
        if(n < 3) return n;
        if((int)pow(2, power) <= n) return pow(2, power + 1);
        return (int)pow(2, power);
    }
};