class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp;
        int n = arr1.size(), maxi = 0, m = arr2.size(), len;
        for (int i = 0; i < n; i++) {
            while (arr1[i]) {
                mp[arr1[i]] = 1;
                arr1[i] /= 10;
            }
        }
        for (int i = 0; i < arr2.size(); i++) {
            len = log10(arr2[i]) + 1;
            while (arr2[i]) {
                if (mp[arr2[i]]) {
                    maxi = max(maxi, len);
                    break;
                }
                arr2[i] /= 10;
                len--;
            }
        }
        mp.clear();
        return maxi;
    }
};
