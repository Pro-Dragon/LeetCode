class Solution {
public:
    int minKBitFlips(vector<int>& arr, int k) {
        int n = arr.size(), count = 0, cur = 0;
        vector<int> res(n + 1, 0);
        for(int i = 0; i < n; i++) {
            if(res[i]) cur--;
            if((arr[i] + cur) % 2 == 0) {
                if(i > n - k) return -1;
                res[i + k] = 1;
                count++;
                cur++;
            }
        }
        return count;
    }
};