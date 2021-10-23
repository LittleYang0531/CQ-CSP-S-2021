#include<bits/stdc++.h>
using namespace std;
int T,n,a[1000005],b[1000005],num;
int h=1,t;
char ch[500005];
int cnt;
bool boo;
bool dfs(int step){
	for(int i=(n>>1);i<n;i++){
		if(num>i){
			if(b[i]!=b[n-i+1])return 0;
		}
	}
	if(step==n+1){
		bool flag=0;
		for(int i=1;i<=(n>>1);i++){
			if(b[i]!=b[n-i+1]){
				flag=1;
				break;
			}
		}
		if(!flag&&!boo){
			for(int i=1;i<=cnt;i++)cout<<ch[i];
			printf("\n");
			boo=1;
			return 1;
		}
		else return 0;
	}
	ch[++cnt]='L';
	b[++num]=a[h++];
	bool k=dfs(step+1);
	cnt--;
	num--;
	h--;
	if(k==0){
		ch[++cnt]='R';
		b[++num]=a[t--];
		dfs(step+1);
		cnt--;
		num--;
		t++;
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		boo=0;
		scanf("%d",&n);
		h=1;
		n<<=1;
		t=n;
		for(int i=1;i<=n;i++)scanf("%d",a+i);
		dfs(1);
		if(boo==0)cout<<"-1\n";
	}
	return 0;
}
