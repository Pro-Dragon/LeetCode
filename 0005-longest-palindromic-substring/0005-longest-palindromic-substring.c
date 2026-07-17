char* longestPalindrome(char* s) {
    int i=0,j=0,k=0,a=1,l=0,h=0,n=0,m=0,r=0,t=1;
    while(i<strlen(s)){
        j=strlen(s)-1;
        k=i,a=1,h=0,l=0,r=0,t=1;
        while(k<=j){
            if(k!=i&&s[i]==s[j]&&t&&!r){
                r=j;
                t=0;
            }
           if(s[j]==s[k]){
            l=i;
            if(a)h=j;
             a=0;
             k++; 
           }
           else{
            k=i;
            a=1;
            h=0;l=0;
           if(!t)j=r+1;
           else if(s[k]==s[j]){
             t=1;
             continue;
           }
            t=1;
           }
           j--;
        }
        if(m-n<h-l){
            m=h;
            n=l;
           }
           i++;
        }
        i=n,a=0;
        printf("%d %d",m,n);
   while(i<=m){
   s[a++]=s[i++];
   }
   s[a]='\0';
    return s;
}