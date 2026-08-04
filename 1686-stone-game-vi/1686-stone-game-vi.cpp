class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        vector<vector<int>> freq(201);
        int n = aliceValues.size(), a = 0, b = 0, turn = true;
        for(int i = 0; i < n; i++) {
            freq[aliceValues[i] + bobValues[i]].push_back(i);
        }
        for(int i = 200; i >= 0; i--) {
            for(int j = 0; j < freq[i].size(); j++) {
                if(!turn) {
                    b += bobValues[freq[i][j]];
                }
                else {
                    a += aliceValues[freq[i][j]];
                }
                turn = !turn;
            }
        }
        if(a > b) return 1;
        if(b > a) return -1;
        return 0;
    }
};