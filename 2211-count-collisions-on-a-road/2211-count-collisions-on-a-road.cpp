class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size(), count1 = 0, check = 0, res = 0;
        for(int i = 0; i < n; i++) {
            if(directions[i] == 'R') {
                count1++;
            }
            else if(directions[i] == 'L') {
                if(count1) {
                    res += ((count1) + 1);
                    check = 1;
                    count1 = 0;
                }
                else if(check) res++;
            }
            else {
                if(count1) {
                    res += count1;
                    count1 = 0;
                }
                check = 1;
            }
        }
        return res;
    }
};