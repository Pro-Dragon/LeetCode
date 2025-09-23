class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.size(), n2 = version2.size();
        int i1 = 0, j1 = 0, count1 = 0, count2 = 0;
        while(i1 < n1 || j1 < n2) {
             count1 = 0, count2 = 0;
            while(i1 < n1 && version1[i1] != '.'){
                count1 = count1 * 10 + (version1[i1++] - '0');
            }
            while(j1 < n2 && version2[j1] != '.') {
                count2 = count2 * 10 + (version2[j1++] - '0');
            }
            if(count1 != count2) return (count1 < count2) ? -1 : 1; 
            i1++, j1++;
        }
        return 0;
    }
};