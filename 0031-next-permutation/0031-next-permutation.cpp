class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int i, n = arr.size() - 1;
        for(i = n; i > 0; i--) if(arr[i] > arr[i - 1]) break;
        if(i) {
            int key = i - 1;
            while(i <= n){
                if(arr[key] >= arr[i]) break;
                i++;
            }
            i--;
            swap(arr[key], arr[i]);
            i = key + 1;
        }
        int mid = (i + n) >> 1;
        while(i <= mid) swap(arr[i++], arr[n--]);
    }
};