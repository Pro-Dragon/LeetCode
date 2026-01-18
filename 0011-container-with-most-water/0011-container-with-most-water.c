int maxArea(int* height, int heightSize) {
    int i=0,j=0,max=0,b=0,volume=1;;
    while(i!=heightSize-1){
       if(height[heightSize-1]>=height[i]){
        j=height[i]*(((heightSize-1)-i));
        i++;
       }
       else if(height[i]>height[heightSize-1]){
         j=height[heightSize-1]*(((heightSize-1)-i));
         heightSize--;
       }
       if(max<=j)max=j;
    }
    return max;
}