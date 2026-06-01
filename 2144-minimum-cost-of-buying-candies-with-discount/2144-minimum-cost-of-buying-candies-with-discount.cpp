class Solution {
public:
    int minimumCost(vector<int>& cost) {
        vector<int> freq(101, 0);
        int n = cost.size(), res = 0, count = 0;
        for(int i = 0; i < n; i++) {
            freq[cost[i]]++;
        }
        int rem=0;
        int ans=0;
        for(int i = 100; i >=1; i--) {
            // if(freq[i]) {
            //     freq[i] -= 
            // }
            // res += i * (freq[i] / 3) * 2;
            // res += i * freq[i] % 34
            if(freq[i]>0){
                int cur=rem+freq[i];
                int del=cur/3;
                int Final=(freq[i]-del)*i;
                ans+=Final;
                rem=(cur)%3;
            }
        }
        return ans;
    }
};