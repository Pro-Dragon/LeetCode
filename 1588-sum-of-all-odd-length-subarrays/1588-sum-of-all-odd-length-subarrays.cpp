class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size(), sum = 0, left, right, freq;
        for(int i = 0; i < n; i++) {
            left = (i + 1) >> 1;
            right = (n - i) >> 1;
            freq = left * right;
            if(i % 2 == 0) left++;
            if((n - i) % 2) right++;
            freq += left * right;
            sum += arr[i] * freq;
        }
        return sum;
    }
};