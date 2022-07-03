#include <stdio.h>
#include <stdlib.h>
int G[99][99],r[99],f[99];
int n,ans,cnt=0;
int max(int m,int n){
    if(m>=n){
        return m;
    }else
    {return n;}
}
void fun(){
    while(1){
        int flag=0;
        for(int i=0;i<n;i++){
            if(r[i]==0){
                r[i]--;
                cnt++;
                flag=1;
                for(int j=0;j<n;j++){
                    if(G[i][j]!=-1){
                        r[j]--;
                        f[j]=max(f[j],f[i]+G[i][j]);
                        ans=max(ans,f[j]);
                        }
                    }
                }
            }
            if(!flag){break;}
        }
        if(cnt==n){
            printf("%d",ans);
        }
        else{
            printf("Impossible");
        }
    }



int main(){
    int m,s,t,v;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            G[i][j]=-1;
        }
    }
    while (m--)
    {
        scanf("%d%d%d",&s,&t,&v);
        G[s][t]=v;
        r[t]++;
    }
    fun();
    return 0;
    
}