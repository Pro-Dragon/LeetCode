void merge(int *A,int l,int m,int h)
{
  int result[h-l+1];
  int i=l,j=m+1,k=0;
  while(k<=h-l)
    {
	  	if(i<=m&&(j>h||A[i]<=A[j]))
	  	{
	  	  result[k++]=A[i++];
		  continue;
          }
		result[k++]=A[j++];
	    
	}
		k=0;
		for(i=l;i<=h;i++)
		{
			A[i]=result[k++];
        }
}
void merge_sort(int *A,int l,int h)
{                                 
	if(l<h)
	{
		int m=(l+h)/2;
		merge_sort(A,l,m);
		merge_sort(A,m+1,h);
		merge(A,l,m,h);
	}
}
int maximumProduct(int* nums, int numsSize) {
    merge_sort(nums,0,numsSize-1);
    if(nums[0]*nums[1]*nums[numsSize-1]<nums[numsSize-1]*nums[numsSize-2]*nums[numsSize-3])return nums[numsSize-1]*nums[numsSize-2]*nums[numsSize-3];
    else return nums[0]*nums[1]*nums[numsSize-1];
}