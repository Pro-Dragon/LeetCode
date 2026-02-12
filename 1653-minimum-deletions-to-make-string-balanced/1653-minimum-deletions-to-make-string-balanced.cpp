class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size(), count = 0, a = 0, res = 0, b = 0, cur = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == 'a') {
                if(count < 0) count = 0;
                count++;
                a++;
            }
            else {
                count--;
                if(count >= 0) b++;
                else {
                    b = 0;
                    res = a;
                }
            }
        }
        return res + b;
    }
};