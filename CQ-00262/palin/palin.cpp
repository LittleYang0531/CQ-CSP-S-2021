#include<bits/stdc++.h>
using namespace std;
int t,n,a[1000005],head,tail,b[1000005],flag,opt[1000005];
bool dfs(bool check){
	if(flag==n)check=1;
	if(head>tail)return 1;
	if(!check){
		b[++flag]=a[head++];opt[++opt[0]]=0;if(dfs(check))return 1;
		head--,opt[0]--;
		b[flag]=a[tail--];opt[++opt[0]]=1;if(dfs(check))return 1;
		tail++,opt[0]--,flag--;
		return 0;
	}
	else{
		if(a[head]==b[flag]){
			head++,flag--;opt[++opt[0]]=0;if(dfs(check))return 1;
			head--,flag++,opt[0]--;
		}
		if(a[tail]==b[flag]){
			tail--,flag--;opt[++opt[0]]=1;if(dfs(check))return 1;
			tail++,flag++,opt[0]--;
		}
		return 0;
	}
}
int main(){
	freopen("palin.in","r",stdin);freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)scanf("%d",&a[i]);head=1,tail=2*n,flag=0,opt[0]=0;
		if(!dfs(0))printf("-1");
		else for(int i=1;i<=opt[0];i++)putchar(opt[i]?'R':'L');putchar('\n');
	}
	return 0;
}
