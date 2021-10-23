#include<bits/stdc++.h>
using namespace std;
long long n,t,a[500001],ans[1000001],tmp[1000001],flag;
inline void find(int s,int b,int e,int f){
	if(flag==1)return ;
	if(s>2*n){
		if(flag==1)return ;
		for(int i=1;i<=2*n;i++)
			if(tmp[i]!=tmp[2*n+1-i])return;
		for(int i=1;i<=2*n;i++)
			if(ans[i]==1)printf("L");
			else printf("R");
		flag=1;cout<<endl;
		return ;
	}
	ans[s]=f;
	if(f==1)tmp[s]=a[b],find(s+1,b+1,e,1),find(s+1,b+1,e,2);
	if(flag==1)return ;
	if(f==2)tmp[s]=a[e],find(s+1,b,e-1,1),find(s+1,b,e-1,2);
	if(flag==1)return ;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	while(t--){																				
		cin>>n;flag=0;
		for(int i=1;i<=2*n;i++)scanf("%d",&a[i]);
		find(1,1,2*n,1),find(1,1,2*n,2);
		if(flag==0)printf("-1\n");
	}
	return 0;
}
