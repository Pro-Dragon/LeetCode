class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        vector<int> res;
        int n = grid.size(), cur = 0, count = 0;
        for(int i = 0; i < n; i++) {
            cur = 0;
            for(int j = n - 1; j >= 0; j--) {
                if(!grid[i][j]) cur++;
                else break;
            }
            res.push_back(cur);
        }
        for(int i = 0; i < res.size(); i++) {
            for(int j = i; j < res.size(); j++) {
                if((n - i) - 1 <= res[j]) {
                    int temp = res[j];
                    res.erase(res.begin() + j);
                    res.insert(res.begin() + i, temp);
                    count += j - i;
                    break;
                }
            }
            if(res[i] < (n - i) - 1) return -1;
        }
        return count;
    }
};