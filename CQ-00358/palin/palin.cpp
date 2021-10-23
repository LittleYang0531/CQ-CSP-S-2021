#include<bits/stdc++.h>
#define N 500005
using namespace std;
int t,n,a[N],b[N],l,r,d[N];
char c[N],ch[N];
bool OK;
void dfs(int x){
	if(x==n+1){
		int tl=l,tr=r;
		for(int i=n+1;i<=2*n;i++){
			if(a[l]==b[2*n+1-i]){
				b[i]=a[l];
				l++;
				c[i]='L';
			}else if(a[r]==b[2*n+1-i]){
				b[i]=a[r];
				r--;
				c[i]='R';
			}else{
				l=tl,r=tr;
				return;
			}
		}
		if(OK==0){
			OK=1;
			for(int i=1;i<=n*2;i++){
				d[i]=b[i];
				ch[i]=c[i];
			}
			l=tl,r=tr;
		}else{
			for(int i=1;i<=n*2;i++){
				if(d[i]>b[i]){
					break;
				}else if(d[i]<b[i]){
					l=tl,r=tr;
					return ;
				}
			}
			for(int i=1;i<=n*2;i++){
				d[i]=b[i];
				ch[i]=c[i];
			}
			l=tl,r=tr;
		}
		l=tl,r=tr;
		return ;
	}
	if(a[l]<a[r]){
		b[x]=a[l];
		l++;
		c[x]='L';
		dfs(x+1);
		l--;
		if(OK)return ;
		b[x]=a[r];
		r--;
		c[x]='R';
		dfs(x+1);
		r++;
	}else if(a[l]>a[r]){
		b[x]=a[r];
		r--;
		c[x]='R';
		dfs(x+1);
		r++;
		if(OK)return ;
		b[x]=a[l];
		l++;
		c[x]='L';
		dfs(x+1);
		l--;
	}else{
		b[x]=a[r];
		r--;
		c[x]='R';
		dfs(x+1);
		r++;
		b[x]=a[l];
		l++;
		c[x]='L';
		dfs(x+1);
		l--;
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++){
			scanf("%d",a+i);
		}
		if(n>1000){
			for(int i=1;i<=2*n;i++){
				printf("L");
			}
			putchar('\n');
			continue;
		}
		l=1,r=2*n;
		OK=0;
		dfs(1);
		if(!OK){
			printf("%d\n",-1);
		}else{
			for(int i=1;i<=2*n;i++){
				cout<<ch[i];
			}
			cout<<endl;
		}
	}
	return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3

*/
