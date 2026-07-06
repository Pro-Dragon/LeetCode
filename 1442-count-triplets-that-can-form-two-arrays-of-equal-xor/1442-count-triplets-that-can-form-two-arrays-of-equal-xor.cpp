class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size(), cur = 0, res = 0, pre = 0;
        unordered_map<int, int> mp1, mp2;
        for(int i = 0; i < n; i++) {
            cur ^= arr[i];
            mp1[cur]++;
           // cout<<cur<<" ";
        }
        //cout<<endl;
        cur = 0, pre = 0;
        //res += cur;
        mp2[0] = 1;
        mp1[0]++;
        for(int i = 0; i < n; i++) { 
            pre ^= arr[i];
            mp2[pre]++;
            cur -= (mp2[pre] - 1);
            if(mp1[pre ^ arr[i]]) {
                cur += mp1[pre ^ arr[i]] - mp2[pre ^ arr[i]];
                //cout<<mp2[pre]<<endl<<endl;
            }
            res += cur;
            //cout << "Index: " << i << " | Pre: " << pre << " | Cur: " << cur << endl;
        }
        return res;
    }
};