#include <stdio.h>
#include <stdlib.h>
int search(int* nums,int numSize,int target){
   int mid,l,r;
   l=0;r=numSize-1;
   while(l<=r){
      int mid=(r-l)/2+l;
   if(target==nums[mid]){
      return mid;
   }
   if(nums[mid]<target){
      l=mid+1;
   }
   else{
      r=mid-1;
   }
   } 
   return -1;
}
