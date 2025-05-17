class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, h1 = *max_element(piles.begin(), piles.end()), n = piles.size(), mid, mini = h1, hours;
        while(l <= h1) {
            mid = (l + h1) >> 1;
            hours = 0;
            for(int i = 0; i < n; i++) {
                hours += (piles[i] + mid - 1) / mid;
                if(hours > h) break;
            }
            if(hours > h) l = mid + 1;
            else if(hours <= h) {
                mini = min(mini, mid);
                h1 = mid - 1;
            }
        }
        return mini;
    }
};