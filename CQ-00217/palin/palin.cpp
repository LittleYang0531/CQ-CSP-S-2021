#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
const int maxn=500003;
int n,a[maxn<<1],sum[maxn<<1],lef[maxn],rig[maxn],mb[maxn],ans[maxn<<1];
bool cmp(int x,int y){return lef[x]>lef[y];}
signed main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T; scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		for(int i=1;i<=n;++i) lef[i]=rig[i]=0;
		for(int i=1;i<=2*n;++i) scanf("%lld",&a[i]),lef[a[i]]?rig[a[i]]=i:lef[a[i]]=i,sum[i]=sum[i-1]+a[i];
		int tsum=(1+n)*n/2,cnt=0,flag;
		for(int i=1;i<=n;++i) if(rig[i]-lef[i]==n&&sum[rig[i]]-sum[lef[i]]==tsum) mb[++cnt]=i;
		sort(mb+1,mb+cnt+1,cmp);
		for(int i=1,l,r,p,q,pos;pos=flag=0,l=lef[mb[i]]+1,r=rig[mb[i]]-1,p=lef[mb[i]]-1,q=rig[mb[i]]+1,i<=cnt;++i){
			ans[n]=0,ans[n+1]=1;
			while(l<=r){
				++pos;
				if(l<r){
					if(q<=2*n&&a[q]==a[r]) ans[n+pos+1]=1,ans[n-pos]=1,r--,q++;
					else if(q<=2*n&&a[q]==a[l]) ans[n+pos+1]=0,ans[n-pos]=1,l++,q++;
					else if(p>=1&&a[p]==a[l]) ans[n+pos+1]=0,ans[n-pos]=0,l++,p--;
					else if(p>=1&&a[p]==a[r]) ans[n+pos+1]=1,ans[n-pos]=0,r--,p--;
					else {flag=1;break;}
				}
				else{
					if(q<=2*n&&a[q]==a[l]) ans[n+pos+1]=0,ans[n-pos]=1,r--,q++;
					else if(p>=1&&a[p]==a[l]) ans[n+pos+1]=0,ans[n-pos]=0,l++,p--;
				}if(flag) break;
			}if(flag==1) {continue;}
			for(int j=1;j<=2*n;++j) cout<<(ans[j]?'R':'L');flag=2;break;
		}
		flag==2?puts(""):puts("-1");
	}
	return 0;
}
