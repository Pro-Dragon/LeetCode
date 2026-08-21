int climbStairs(int n) {
    int a=0,b=1,i=0,c;
    while(i<n){
        c=a+b;
        a=b;
        b=c;
        i++;
    }
    return c;
}