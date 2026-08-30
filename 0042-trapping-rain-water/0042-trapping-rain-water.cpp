class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0, j = height.size() - 1, maxi1 = 0, maxi2 = 0, res = 0;
        if(i == j) return 0;
        while(i <= j) {
            maxi1 = max(maxi1, height[i]);
            maxi2 = max(maxi2, height[j]);
            if(height[i] <= height[j]) {
                res += maxi1 - height[i];
                i++;
            }
            else {
                res += maxi2 - height[j];
                j--;
            }
        }
        return res;
    }
};