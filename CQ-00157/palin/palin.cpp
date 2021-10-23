#include<cstdio>
const int maxn=5e5+5;
int a[maxn];
char ans[maxn];
int T,n,l,r,m,p,q,cnt,f;
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n); m=n<<1; f=0;
		for(int i=1;i<=m;++i)
			scanf("%d",&a[i]);
		for(int i=2;i<=m;++i){
			if(a[i]==a[1]){
				l=r=i;
				break;
			}
		}
		p=2; q=m; ans[cnt=1]='L';
		while(r-l+1<n){
			if(a[l-1]==a[p]&&p+1<=l-1){
				++p; --l; ans[++cnt]='L';
			}
			else if(a[r+1]==a[p]&&p+1<=l&&r+1<=q){
				++p; ++r; ans[++cnt]='L';
			}
			else if(a[l-1]==a[q]&&q-1>=r&&l-1>=p){
				--q; --l; ans[++cnt]='R';
			}
			else if(a[r+1]==a[q]&&r+1<=q-1){
				--q; ++r; ans[++cnt]='R';
			}
			else{ f=1; break; }
		}
		if(f){
			f=0;
			for(int i=1;i<m;++i){
				if(a[i]==a[m]){
					l=r=i;
					break;
				}
			}
			p=1; q=m-1; ans[cnt=1]='R';
			while(r-l+1<n){
				if(a[l-1]==a[p]&&p+1<=l-1){
					++p; --l; ans[++cnt]='L';
				}
				else if(a[r+1]==a[p]&&p+1<=l&&r+1<=q){
					++p; ++r; ans[++cnt]='L';
				}
				else if(a[l-1]==a[q]&&q-1>=r&&l-1>=p){
					--q; --l; ans[++cnt]='R';
				}
				else if(a[r+1]==a[q]&&r+1<=q-1){
					--q; ++r; ans[++cnt]='R';
				}
				else{ f=1; break; }
			}
			if(f) puts("-1");
			else{
				p=l-1; q=r+1;
				for(int i=n;i;--i){
					if(ans[i]=='L'){
						if(a[p]==a[l]){
							ans[++cnt]='L';
							++l;
						}
						else if(a[p]==a[r]){
							ans[++cnt]='R';
							--r;
						}
						else{ f=1; break; } --p;
					} else{
						if(a[q]==a[l]){
							ans[++cnt]='L';
							++l;
						}
						else if(a[q]==a[r]){
							ans[++cnt]='R';
							--r;
						}
						else{ f=1; break; } ++q;
					}
				}
				if(f) printf("-1");
				else for(int i=1;i<=m;++i)
					putchar(ans[i]);
				putchar('\n');
			}
		}
		else{
			p=l-1; q=r+1;
			for(int i=n;i;--i){
				if(ans[i]=='L'){
					if(a[p]==a[l]){
						ans[++cnt]='L';
						++l;
					}
					else if(a[p]==a[r]){
						ans[++cnt]='R';
						--r;
					}
					else{ f=1; break; } --p;
				} else{
					if(a[q]==a[l]){
						ans[++cnt]='L';
						++l;
					}
					else if(a[q]==a[r]){
						ans[++cnt]='R';
						--r;
					}
					else{ f=1; break; } ++q;
				}
			}
			if(f) printf("-1");
			else for(int i=1;i<=m;++i) putchar(ans[i]);
			putchar('\n');
		}
	}
	return 0;
}

