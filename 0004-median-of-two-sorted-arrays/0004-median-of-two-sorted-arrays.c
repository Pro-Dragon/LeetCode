double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  int i=0,j=0,arr[nums1Size+nums2Size],k=0;
  while(i<nums1Size||j<nums2Size){
    if(i<nums1Size&&((j>=nums2Size)||nums1[i]<=nums2[j])){
        arr[k++]=nums1[i];
        i++;
    }
    else if(j<nums2Size&&((i>=nums1Size)||nums1[i]>nums2[j])){
        arr[k++]=nums2[j];
        j++;
    }
  }
  k--;
  if((k+1)%2==0){
    return (arr[k/2]+arr[k/2+1])/2.0;
  }
  else return arr[(k/2)];
}