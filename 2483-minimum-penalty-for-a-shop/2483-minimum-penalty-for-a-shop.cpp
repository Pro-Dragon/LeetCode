class Solution {
public:
    int bestClosingTime(string customers) {
        int count1 = 0, count2 = 0, mini = customers.size(), ind = 0;
        for(int i = 0; i < customers.size(); i++) {
            if(customers[i] == 'Y') count1++;
        }
        for(int i = 0; i < customers.size(); i++) {
            if(mini > count1 + count2) {
                mini = count1 + count2;
                ind = i;
            }
            if(customers[i] == 'Y') count1--;
            else count2++;
        }
        if(mini > count1 + count2) ind = customers.size();
        return ind;
    }
};