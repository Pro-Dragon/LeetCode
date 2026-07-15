class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int, int> mp;
        if(groupSize == 1) return 1;
        int n = hand.size(), cur = 0, max_ele = -1;
        for(int i = 0; i < n; i++) {
            mp[hand[i]]++;
        }
        for(int i = 0; i < n; i++) {
            if(!mp[hand[i] - 1] && mp[hand[i]] > 0) {
                cur = 0;
                for(int j = hand[i]; mp[j] > 0; j++) {
                    if(cur > mp[j]) return 0;
                    mp[j] -= cur;
                    if(j - hand[i] >= groupSize - 1) {
                        cur += mp[j - (groupSize - 1)];
                    }
                    cur += mp[j];
                    mp[j] *= -1;
                }
                if(cur) return 0;
            }
        }
        return 1;
    }
};