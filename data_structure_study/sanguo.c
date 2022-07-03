#include <stdio.h>
#include <stdlib.h>
int fun(int p,int s,int t){

    if(s+p>=t&&s+t>=p&&t+p>=s){
        return 1;
    }
    else{
        return 0;
    }
    
}
int main(){
    int n,i,j,p,cnt=0;
    scanf("%d%d",&n,&p);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(fun(p,a[i],a[j])){
                cnt++;
                
            }
        }
    }
    printf("%d",cnt);
    
    return 0;
}