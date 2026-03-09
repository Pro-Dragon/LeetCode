class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<int> freq(n / 2 + n % 2, 0);
        if(n > 2) count++;
        for(int i = 3; i < n; i += 2) {
            if(freq[i / 2]) continue;
            count++;
            for(long j = (long)i * i; j < n; j += i) {
                if(!(j % 2)) continue;
                freq[j / 2] = 1;
            }
        }
        return count;
    }
};