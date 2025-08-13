class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n = weight.size(), cur_maxi = weight[0], count = 0;
        for(int i = 1; i < n; i++) {
            if(cur_maxi > weight[i]){
                cur_maxi = -1;
                count++;
            }
            else cur_maxi = weight[i];
        }
        return count;
    }
};