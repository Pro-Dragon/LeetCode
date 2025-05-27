class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num, total = (n * (n + 1)) / 2;
        num = m * ((n / m) * (((n / m) + 1)) / 2);
        return total - 2 * num;
    }
};