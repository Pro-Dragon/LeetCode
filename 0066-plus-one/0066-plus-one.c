/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
     int b=1,i=i=digitsSize-1;
     int j=i+1;
     int *arr=(int *)malloc((digitsSize+1)*sizeof(int));
    while(i>=0){
       digits[i]+=1;
       if(digits[i]<10){
        *returnSize=digitsSize;
        return digits;
       }
       else{
        digits[i]=0;
       }
       arr[j--]=digits[i];
       i--;
    }
    arr[0]=1;
    *returnSize=digitsSize+1;
    return arr;
}