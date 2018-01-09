/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

#include<stdio.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int nums3[nums1Size+nums2Size];
    int i=0,j=0,k=0;
    while((i!=nums1Size)&&(j!=nums2Size))
	{
        if(nums1[i]<=nums2[j]){
        	nums3[k++] = nums1[i];
			i++;
		}
		if(nums1[i]>nums2[j]){
        	nums3[k++] = nums2[j];
			j++;
		}
    }
    if(i==nums1Size){
    	for(;j<nums2Size;j++){
    		nums3[k++] = nums2[j];
		}		
	}
    if(j==nums2Size){
    	for(;i<nums1Size;i++){
    		nums3[k++] = nums1[i];
		}
	}
	if((nums1Size+nums2Size)%2==0){
		double x = nums3[(k-1)/2];
        double y = nums3[k/2];
        return (x+y)/2;
	}
	else{
		return nums3[k/2];
	}
}

//int main(){
//	int nums1[] = {1,3};
//	int nums2[] = {2,4};
//	double ans = findMedianSortedArrays(nums1,2,nums2,2);
//	printf("%f",ans);
//	return 0;
//}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int nums3[nums1Size+nums2Size];
    int i=0,j=0,k=0;
    while((i!=nums1Size)&&(j!=nums2Size))
	{
        if(nums1[i]<=nums2[j]){
        	nums3[k++] = nums1[i];
			i++;
		}
		if(nums1[i]>nums2[j]){
        	nums3[k++] = nums2[j];
			j++;
		}
    }
    if(i==nums1Size){
    	for(;j<nums2Size;j++){
    		nums3[k++] = nums2[j];
		}		
	}
    if(j==nums2Size){
    	for(;i<nums1Size;i++){
    		nums3[k++] = nums1[i];
		}
	}
	if((nums1Size+nums2Size)%2==0){
		double x = nums3[(k-1)/2];
        double y = nums3[k/2];
        return (x+y)/2;
	}
	else{
		return nums3[k/2];
	}
}
