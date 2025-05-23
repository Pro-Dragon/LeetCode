/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i=0,j=0;
    int *arr=malloc(2*sizeof(int));
    *returnSize=2;
   for(i=0;i<numsSize;i++)
   {
       for(j=i+1;j<numsSize;j++){
           if(nums[j]+nums[i]==target){
               arr[0]=i;
               arr[1]=j;
               return arr;
           }
       }
   }
   return 0;
}