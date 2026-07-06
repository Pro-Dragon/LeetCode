class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size(), res = 0, pre = 0;
        unordered_map<int, int> mp1, mp2;
        pre = 0;
        mp2[0] = 0;
        mp1[0]++;
        for(int i = 0; i < n; i++) { 
            pre ^= arr[i];
            res += mp1[pre]++ * i - mp2[pre];
            mp2[pre] += (i + 1);
        }
        cout<<mp1[2];
        return res;
    }
};