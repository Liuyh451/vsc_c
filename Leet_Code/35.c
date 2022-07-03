#include <stdio.h>
#include <stdlib.h>
int searchInsert(int* nums, int numsSize, int target){
    int l,r,mid,f=0;
    l=0,r=numsSize-1;
    while(l<r){
        mid=(r-l)/2+l;
        if(target==nums[mid]){
            f=1;
            return mid;
        }
        if(nums[mid]>target){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    if(l==r&&f==0){
        printf("here");
        if(target>nums[l]){
            printf("%d",l+1);
        }
        else{
            if(l==0){
            printf("%d",l); 
            }
            else{
                printf("%d",l-1);}
            
        }
        
    }
}
int main(){
    int n,t;
    
    scanf("%d%d",&n,&t);
    int a[n];
    int i;
    for(i=0;i<n;i++){
       
        scanf("%d",&a[i]);    
    }
    searchInsert(a,n,t);
    
    
    
    return 0;


}