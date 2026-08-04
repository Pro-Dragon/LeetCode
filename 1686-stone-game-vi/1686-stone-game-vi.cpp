class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        priority_queue<pair<int, int>> pq;
        int n = aliceValues.size(), a = 0, b = 0, turn = true;
        for(int i = 0; i < n; i++) {
            pq.push({aliceValues[i] + bobValues[i], i});
        }
        while(!pq.empty()) {
            if(turn) a += aliceValues[pq.top().second];
            else b += bobValues[pq.top().second];
            turn = !turn;
            pq.pop();
        }
        if(a > b) return 1;
        if(b > a) return -1;
        return 0;
    }
};