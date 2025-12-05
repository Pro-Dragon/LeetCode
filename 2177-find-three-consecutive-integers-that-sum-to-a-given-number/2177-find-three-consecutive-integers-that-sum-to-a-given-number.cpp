class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if((num - 3) % 3 == 0) {
            long long val = ((num - 3) / 3);
            return {val, val + 1, val + 2};
        }
        return {};
    }
};