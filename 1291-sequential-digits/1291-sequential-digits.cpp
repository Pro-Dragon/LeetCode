class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        long digits_size = log10(low) + 1, target = log10(high) + 1, start = 0, i = 0, cur, n = digits_size, cur_size = digits_size;
        vector<int> res;
        while(n--) start = start * 10 + (start % 10 + 1);
        cur = start;
        if(target == 10) target--;
        while(cur_size <= target) {
            if(digits_size < cur_size) {
                start = start * 10 + ((start % 10) + 1);
                cur = start;
                digits_size++;
            }
            if(cur >= low && cur <= high) res.push_back(cur);
            if((cur % 10) == 9) cur_size++;
            cur = cur * 10 + ((cur % 10) + 1);
            cur = cur % (long)pow(10, cur_size);
        }
        return res;
    }
};