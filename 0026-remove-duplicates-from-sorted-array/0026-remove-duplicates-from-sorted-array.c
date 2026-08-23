int removeDuplicates(int* nums, int numsSize) {
    int i=0,j=1;
    while(i<numsSize){
      if(nums[j-1]!=nums[i])nums[j++]=nums[i];
      i++;
    }
    return j;
}