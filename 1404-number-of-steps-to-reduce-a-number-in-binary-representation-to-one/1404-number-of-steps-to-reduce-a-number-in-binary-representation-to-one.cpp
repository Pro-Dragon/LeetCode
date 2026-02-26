class Solution {
public:
    int numSteps(string s) {
        int n = s.size(), borrow = 0, count = 0;
        for(int i = n - 1; i > 0; i--) {
            if(borrow) s[i] = ('1' - s[i]) + '0';
            if(s[i] == '0') count++;
            else {
                count += 2;
                borrow = 1;
            }
        }
        return count + borrow;
    }
};