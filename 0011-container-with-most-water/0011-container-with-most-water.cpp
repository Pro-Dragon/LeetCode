class Solution {
public:
    int maxArea(vector<int>& height) {
        long long left = 0, right = height.size() - 1, maxi = 0, cur;
        while(left < right) {
            cur = min(height[left], height[right]);
            cur = cur * 1ll * (right - left);
            if(maxi < cur) maxi = cur;
            if(height[left] < height[right]) left++;
            else right--;
        }
        return maxi;
    }
};