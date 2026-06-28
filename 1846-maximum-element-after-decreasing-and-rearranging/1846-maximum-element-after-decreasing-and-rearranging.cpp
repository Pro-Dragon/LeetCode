class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size(), emty = 0, size = 0, val = 0;
        vector<int> freq(n + 1, 0);
        for(int i = 0; i < n; i++) {
            if(arr[i] <= n) freq[arr[i]]++;
        }
        for(int i = 1; i <= n && size < n; i++) {
            if(!freq[i]) emty++;
            else {
                size += freq[i];
                if(emty >= freq[i]) {
                    val += freq[i];
                    emty -= freq[i];
                }
                else {
                    val = i;
                    emty = 0;
                }
            }
        }
        return val + (n - size);
    }
};