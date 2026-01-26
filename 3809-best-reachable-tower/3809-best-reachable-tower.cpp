class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        vector<int> res;
        res = {-1, -1};
        int n = towers.size(), maxi = -1, val;
        for(int i = 0; i < n; i++) {
            val = abs(towers[i][0] - center[0]) + abs(center[1] - towers[i][1]);
            if(towers[i][2] >= maxi && val <= radius) {
                if(maxi == towers[i][2]) {
                    if(towers[i][0] < res[0] || towers[i][0] == res[0] && towers[i][1] < res[1]) res = {towers[i][0], towers[i][1]};
                }
                else res = {towers[i][0], towers[i][1]};
                maxi = towers[i][2];
            }
        }
        return res;
    }
};