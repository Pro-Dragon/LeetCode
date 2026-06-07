class Solution {
public:
    long long totalWaviness(long long num1, long long num2) {
        long long final_answer = 0;
        long long current_start = num1;

        vector<long long> pow10_arr(18, 1);
        for(int i = 1; i < 18; i++) {
            pow10_arr[i] = pow10_arr[i-1] * 10;
        }
        
        while(current_start <= num2) {
            long long current_digits = to_string(current_start).length();
            long long current_end = min(num2, pow10_arr[current_digits] - 1);
            vector<int> count(1000, 0);
            long long n1 = log10(current_end) + 1, n2 = log10(current_start) + 1, size = n1, start, end, mid, res = 0, end_window, start_window, init, midmoves, last, left, moves = 0, rightsize, diff, temp, val, flag;
            
            if(current_end >= 100) {
                for(int i = 999; i >= 0; i--) {
                    if(i < 100 && i >= 10) {
                        mid = i / 10;
                        if(mid > i % 10) count[i] = 1;
                    }
                    else if(i >= 100) {
                        mid = (i / 10) % 10;
                        if(mid > i % 10 && mid > i / 100 || mid < i % 10 && mid < i / 100) count[i] = 1;
                    }
                    if(n1 == 3 && i >= current_start && i <= current_end) res += count[i];
                }
                
                if(n1 > 3) {
                    long long orig = log10(current_end) + 1;
                    while(n1 >= 3) {
                        temp = 0;
                        start = current_start / pow10_arr[n1 - 3], end = current_end / pow10_arr[n1 - 3];
                        left = ((current_end / pow10_arr[n1]) - (current_start / pow10_arr[n1])) + 1;
                        rightsize = (pow10_arr[n1 - 3]);
                        init = current_end % rightsize + 1;
                        diff = (current_end % rightsize - current_start % rightsize) + 1;
                        midmoves = (left - 1) * rightsize;
                        last = rightsize - (current_start % rightsize);
                        start_window = start % 1000;
                        end_window = end % 1000;
                        val = (current_start / pow10_arr[n1]);
                        
                        for(int i = 0; i <= 999; i++) {
                            if (n1 == orig && i < 100) continue;
                            flag = 0;
                            if(n1 == 3) {
                                moves = left;
                                if(i <= end_window && i < start_window || i >= start_window && i > end_window) moves--;
                                else if(i < start_window && i > end_window) moves -= 2;
                            }
                            else {
                                moves = midmoves;
                                if(val == 0 && i < 100) moves--;
                                if(end_window == start_window && i == end_window) {
                                    if(start == end) moves += diff;
                                    else moves += (init + last) - rightsize;
                                }
                                else if(i == end_window) {
                                    moves += init;
                                    if(i < start_window) moves -= rightsize;
                                }
                                else if(i == start_window) {
                                    moves += last;
                                    if(i > end_window) moves -= rightsize;
                                }
                                else if(i > start_window && i < end_window) moves += rightsize;
                                else if(i < start_window && i > end_window) moves -= rightsize;
                            }
                            res += (max(0LL, moves) * count[i]);
                        }
                        n1--;
                    }
                }
            }
            final_answer += res;
            current_start = current_end + 1;
        }
        return final_answer;
    }
};