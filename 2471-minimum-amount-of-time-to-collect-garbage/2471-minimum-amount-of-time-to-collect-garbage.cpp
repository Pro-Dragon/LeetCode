class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int count = 0, n = garbage.size(), m = 0, p = 0, g = 0, m1 = 0, p1 = 0, g1 = 0, sum = 0;
        for(int i = 0; i < n; i++) {
            int j = garbage[i].size();
            m = 0, g = 0, p = 0;
            count += j;
            while(j--) {
                if(garbage[i][j] == 'G') g = 1;
                else if(garbage[i][j] == 'M') m = 1;
                else p = 1;
            }
            if(i) sum += travel[i - 1];
            if(m) m1 = sum;
            if(p) p1 = sum;
            if(g) g1 = sum;
        }
        return count + m1 + p1 + g1;
    }
};