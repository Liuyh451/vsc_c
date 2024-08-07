#include <stdio.h>

int n=10;
int cnt=0;
int A[5]={0};
int visit[99]={0};
void sort(int A[n],int i,int k){
    if (i == k) {
        for (int j = 0; j < k; j++) {
            printf("%d ", A[j]);
            
        }
        printf("\n");
        cnt++;
        return ;
        
    }
    else {for (int x = 1; x <= n; x++) {
        int m;
            if(i==0){
                 m=0;
            }
            else
            { m=i-1;}
            if (visit[x] == 0&&x >= A[m]) {
                A[i]=x;
                visit[x]=1;
                sort(A, i+1, k);
                visit[x]=0;
            }
        }
        
    }
}

int main() 
{
    /*  Write C code in this online editor and run it. */
    sort(A, 0, 3);
    printf("%d",cnt);
    
    return 0;
}