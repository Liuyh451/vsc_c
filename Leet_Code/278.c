#include <stdio.h>
#include <stdlib.h>
int firstBadVersion(int n) {
    int l,r,mid;
    while(l<=r){//不能等，会进入死循环
        mid=(r-l)/2+l;
    if(isBadVersion(mid)){
        r=mid;  //如果是错的，说明这个点可能是第一个错误的点，故不加一
    }
    else{
        l=mid+1;//如果是正确的，说明这个点没用，排除，加一
    }
    }
    
    return l;
}