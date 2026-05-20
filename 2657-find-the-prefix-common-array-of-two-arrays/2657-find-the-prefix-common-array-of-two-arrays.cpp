class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(), count = 0;
        vector<int> res(n);
        vector<int> freq(n + 1, 0);
        for(int i = 0; i < n; i++) {
            if(freq[A[i]]) count++;
            freq[A[i]]++;
            if(freq[B[i]]) count++;
            freq[B[i]]++;
            res[i] = count;
        }
        return res;
    }
};