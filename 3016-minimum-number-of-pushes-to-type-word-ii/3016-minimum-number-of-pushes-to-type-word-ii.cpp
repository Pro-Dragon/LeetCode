class Solution {
public:
    int minimumPushes(string word) {
        int multi = 1, count = 0, overcount = 0, i;
    int *c = (int*)calloc(26,sizeof(int));
    for(i=0;word[i];i++) c[word[i]-97]++;
    sort(c,c+26);
    for(i=25;i>=0;i--){
        if(c[i]){
            overcount+=c[i]*multi;
            count++;
        }
        else break;
        if(!(count%8)&&count)multi++;
    }
    return overcount;
    }
};