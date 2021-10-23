#include<bits/stdc++.h>
using namespace std;
#define MAXN 500005
#define MAXM 1000005
typedef long long LL;
template<typename _T>
void read(_T &x){
	_T f=1;x=0;char s=getchar();
	while('0'>s||s>'9'){if(s=='-')f=-1;s=getchar();}
	while('0'<=s&&s<='9'){x=(x<<3)+(x<<1)+(s^48);s=getchar();}
	x*=f;
}
int T,n,a[MAXM],head[MAXN],cp[MAXM];
char ans[MAXM];
bool sakura(int l,int r,int al,int ar){
	if(l>al&&r<ar)return 1;int len=l-1+n+n-r;
	if(l<al&&a[l]==a[al]){ans[len+1]='L';ans[n+n-len]='L';return sakura(l+1,r,al-1,ar);}
	if(l<=al&&a[l]==a[ar]){ans[len+1]='L';ans[n+n-len]='R';return sakura(l+1,r,al,ar+1);}
	if(r>=ar&&a[r]==a[al]){ans[len+1]='R';ans[n+n-len]='L';return sakura(l,r-1,al-1,ar);}
	if(r>ar&&a[r]==a[ar]){ans[len+1]='R';ans[n+n-len]='R';return sakura(l,r-1,al,ar+1);}
	return 0;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	read(T);
	while(T--){
		read(n);
		for(int i=1;i<=n+n;i++)read(a[i]);
		for(int i=1;i<=n;i++)head[i]=0;
		for(int i=1;i<=n+n;i++)
			if(!head[a[i]])head[a[i]]=i;
			else cp[i]=head[a[i]],cp[head[a[i]]]=i;
		if(sakura(2,n+n,cp[1]-1,cp[1]+1)){
			ans[1]='L';ans[n+n]='L';
			printf("%s\n",ans+1);
		}
		else if(sakura(1,n+n-1,cp[n+n]-1,cp[n+n]+1)){
			ans[1]='R';ans[n+n]='L';
			printf("%s\n",ans+1);
		}
		else puts("-1");
		for(int i=1;i<=n+n;i++)ans[i]=0;
	}
	return 0;
}
