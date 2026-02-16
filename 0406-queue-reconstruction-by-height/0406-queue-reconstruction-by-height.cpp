class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](auto &a, auto &b) {
            if(a[0] > b[0] || a[0] == b[0] && a[1] < b[1]) return 1;
            return 0;
        });
        vector<vector<int>> res;
        for(int i = 0; i < people.size(); i++) {
            if(res.empty() || res.size() == people[i][1]) res.push_back(people[i]);
            else res.insert(res.begin() + people[i][1], people[i]);
        }
        return res;
    }
};