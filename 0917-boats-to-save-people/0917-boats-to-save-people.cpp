class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int count = 0, n = people.size(), i = 0, j = n - 1;
        while(i < j) {
            if(limit - people[j] >= people[i]) {
                count++;
                i++;
                j--;
            }
            else j--;
        }
        return (n - (count * 2)) + count;
    }
};