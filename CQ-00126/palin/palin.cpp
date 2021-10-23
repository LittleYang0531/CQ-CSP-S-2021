#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
int T,n,m,a[maxn],b[maxn];
string s;
char ans[maxn];
bool solve(int l,int r,int len,int ka[],string sum){
	if(l>r){
		bool flag=0;
		for(int i=1;i<=m;i++){
			if(ka[i]!=ka[m-i+1]){
				flag=1;
				break;
			}
		}
		if(flag==0){
			for(int i=1;i<=m;i++)ans[i]=sum[i-1];
			return 1;
		}
		return 0;
	}
	ka[len+1]=a[l];
	if(solve(l+1,r,len+1,ka,sum+'L'))return 1;
	ka[len+1]=a[r];
	return solve(l,r-1,len+1,ka,sum+'R');
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(n<=20){
			m=2*n;
			for(int i=1;i<=m;i++)scanf("%d",&a[i]);
			memset(b,0,sizeof(b));
			if(solve(1,m,0,b,s)){
				for(int i=1;i<=m;i++)putchar(ans[i]);
				putchar('\n');
			}
			else{
				printf("-1\n");
			}
		}
		
	}
	return 0;
}
