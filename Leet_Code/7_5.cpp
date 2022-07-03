#include<bits/stdc++.h>
using namespace std;
int lower(int i,int r,int v,long long int *a){
	int l=i+1;
	while(l<=r){
			int mid=l+(r-l)/2;
			if(a[mid]<=v){
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		return l;
}
int upper(int i,int r,int v,long long int *a){
	int l=i+1;
	while(l<=r){
			int mid=l+(r-l)/2;
			if(a[mid]<v){
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		return r;

}
int main(){
	long long int n,p;
	cin>>n>>p;
	long long int a[n];
	long long int sum=0;

	for(int i=0;i<n;i++){
		cin>>a[i];
	}
    int t,k;
	sort(a,a+n);
	for(int i=0;i<n;i++){
		int l=i+1,r=n,minn=abs(a[i]-p),maxx=a[i]+p;
		int num1,num2;
		if(l>r) break;
		num1=lower(i,r,minn,a);//找第一个大于等于的值位置
		l=i+1,r=n;
		num2=upper(i,r,maxx,a);//找到大于的值位置
		
		sum+=(num2-num1+1);
		
	}
	cout<<sum;
    		
	return 0;
}

