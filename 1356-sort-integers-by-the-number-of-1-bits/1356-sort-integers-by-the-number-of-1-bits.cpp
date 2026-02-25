class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int &a, int &b) {
            int count1 = __builtin_popcount(a);
            int count2 =  __builtin_popcount(b);
            if(count1 < count2) return 1;
            if(count1 == count2 && a < b) return 1;
            return 0;
        });
        return arr;
    }
};