class Solution {
public:
    int convert1(string str) {
        int n = str.size(), res = 0;
        for(int i = n - 1; i >= 0; i--) {
            res += ((str[i] - '0') << (n - i - 1));
        }
        return res;
    }
    string convert2(int n, int size) {
        string str, str1;
        int i = 0;
        while(n >> i) {
            str += ((n >> i) % 2) + '0';
            i++;
        }
        n = size - str.size();
        while(n--) str1 += '0';
        n = str.size();
        for(int i = n - 1; i >= 0; i--) str1 += str[i];
        return str1;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        vector<int> freq(16, 0);
        for(int i = 0; i < n; i++) {
            int num = convert1(nums[i]);
            if(num < 16) freq[num]++;
        }
        for(int i = 0; i < 16; i++) {
            if(!freq[i]) {
                return convert2(i, n);
            }
        }
        return convert2(16, n);
    }
};