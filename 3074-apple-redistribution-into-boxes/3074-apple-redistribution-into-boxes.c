int minimumBoxes(int* apple, int appleSize, int* capacity, int capacitySize) {
    int i,j,a,b=0,c,d=0;
    for(i=0;i<appleSize;i++){
       b=apple[i]+b;
    }
    for(i=0;i<capacitySize;i++)
    {
        for(j=0;j<capacitySize-i-1;j++){
            if(capacity[j]<capacity[j+1]){
                a=capacity[j];
                capacity[j]=capacity[j+1];
                capacity[j+1]=a;
            }
        }
    }
   for(i=0;i<capacitySize;i++){
       c=capacity[i];
     b=b-c;
       d++;
       if(b<=0)
       {
           break;
       }
   }
    return d;
}