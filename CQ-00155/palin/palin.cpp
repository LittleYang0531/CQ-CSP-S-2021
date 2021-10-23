#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,a[1000005],ano[1000005],w[1000005],b[1000005];
char s[1000005];
int rd(){
	int x=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x;
}
void Clear(){
	for(int i=1;i<=2*n;i++)a[i]=ano[i]=w[i]=b[i]=s[i]=0;
}
bool Try(int isl){
	for(int i=1;i<=2*n;i++)b[i]=s[i]=0;
	int l,r,ll,rr;
	if(isl)s[1]='L',b[1]=a[1],l=ano[1],r=l,ll=1,rr=2*n+1;
	else s[1]='R',b[1]=a[2*n],l=ano[2*n],r=l,ll=0,rr=2*n;
	for(int i=2;i<=n;i++){
		if(ll+1<l-1&&a[ll+1]==a[l-1])ll++,l--,s[i]='L',b[i]=a[ll];
		else if(ll+1<l&&r+1<rr&&a[ll+1]==a[r+1])ll++,r++,s[i]='L',b[i]=a[ll];
		else if(ll<l-1&&r<rr-1&&a[rr-1]==a[l-1])rr--,l--,s[i]='R',b[i]=a[rr];
		else if(r+1<rr-1&&a[rr-1]==a[r+1])rr--,r++,s[i]='R',b[i]=a[rr];
		else return 0;
	}
	for(int i=n+1;i<=2*n;i++){
		if(a[ll+1]==b[2*n+1-i])ll++,s[i]='L';
		else if(a[rr-1]==b[2*n+1-i])rr--,s[i]='R';
		else return 0;
	}
	cout<<s+1<<'\n';
	return Clear(),1;
}
void Solve(){
	n=rd();
	for(int i=1;i<=2*n;i++){
		a[i]=rd();
		if(!w[a[i]])w[a[i]]=i;
		else ano[i]=w[a[i]],ano[w[a[i]]]=i;
	}
	if(Try(1))return ;
	if(Try(0))return ;
	puts("-1"),Clear();
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t=rd();
	while(t--)Solve();
	return 0;
}
