class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), count = 0, sum, mov1 = 0, mov2 = 0;
        unordered_map<int, int> mp1, mp2;
        unordered_set<int> res;
        for(int i = 0; i < n; i++) {
            mp1[nums1[i]]++;
            mp2[nums2[i]]++;
            res.insert(nums1[i]);
            res.insert(nums2[i]);
        }
        for(auto val : res) {
            sum = mp2[val] + mp1[val];
            if(sum % 2) return -1;
            int diff, swaps = abs((sum / 2) - mp1[val]);
            if(mp1[val] < mp2[val]) {
                diff = max(swaps - mov1, 0);
                mov1 = max(mov1 - swaps, 0);
            }
            else if(mp1[val] < mp2[val]) {
                diff = max(swaps - mov2, 0);
                mov2 = max(mov2 - swaps, 0);
            }
            else continue;
            count += diff;
            if(mp1[val] > mp2[val]) mov1 += diff;
            else if(mp1[val] < mp2[val]) mov2 += diff;
        }
        return count;
    }
};