class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size(), prv1 = 0, prv2 = -1, left = 0, maxi = 0;
        for(int i = 0; i < n; i++) {
            if(fruits[prv1] == fruits[i]) prv1 = i;
            else if(prv2 < 0 && fruits[i] != fruits[prv1] || fruits[prv2] == fruits[i]) prv2 = i;
            else {
                if(fruits[prv1] == fruits[i - 1]) {
                    left = prv2 + 1;
                    prv2 = i;
                }
                else {
                    left = prv1 + 1;
                    prv1 = i;
                }
            }
           maxi = max(i - left + 1, maxi);
        }
        return maxi;
    }
};