class Solution {
public:
    int countCoveredBuildings(int n1, vector<vector<int>>& buildings) {
        vector<vector<int>> x(n1 + 1), y(n1 + 1);
        int n = buildings.size(), count = 0;
        for(int i = 0; i < n; i++) {
            if(x[buildings[i][0]].size() < 2) x[buildings[i][0]].push_back(buildings[i][1]);
            else {
                x[buildings[i][0]][1] = max(x[buildings[i][0]][1], buildings[i][1]);
                x[buildings[i][0]][0] = min(buildings[i][1], x[buildings[i][0]][0]);
            }
            if(x[buildings[i][0]].size() == 2 && x[buildings[i][0]][0] > x[buildings[i][0]][1]) swap(x[buildings[i][0]][0], x[buildings[i][0]][1]);
            if(y[buildings[i][1]].size() < 2) y[buildings[i][1]].push_back(buildings[i][0]);
            else {
                y[buildings[i][1]][1] = max(buildings[i][0], y[buildings[i][1]][1]);
                y[buildings[i][1]][0] = min(buildings[i][0], y[buildings[i][1]][0]);
            }
            if(y[buildings[i][1]].size() == 2 && y[buildings[i][1]][0] > y[buildings[i][1]][1]) swap(y[buildings[i][1]][0], y[buildings[i][1]][1]);
        }
        for(int i = 0; i < n; i++) {
            if(x[buildings[i][0]].size() > 1 && y[buildings[i][1]].size() > 1) {
                if(x[buildings[i][0]][1] > buildings[i][1] && x[buildings[i][0]][0] < buildings[i][1] && y[buildings[i][1]][1] > buildings[i][0] && y[buildings[i][1]][0] < buildings[i][0]) count++;
            }
        }
        return count;
    }
};