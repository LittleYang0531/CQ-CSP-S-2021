#include<bits/stdc++.h>
using namespace std;
int t,n,m;
int k;
int a[20][20],b[20][20];
int ans;
int cnt;
int xx[55],p[55],tt[55],d[55];
int h[200005];
int blog[20005];
int smin=0x7fffffff/2;
struct work{
	int next,to,val;
}w[200005];
inline int read(){
	int sum=0,w=1;
	char ch=getchar();
	while('0'>ch||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		sum=sum*10+ch-'0';
		ch=getchar();
	}
	return sum*w;
}
inline void qxx(int x,int y,int z){
	w[++cnt].next=h[x];
	w[cnt].to=y;
	w[cnt].val=z;
	h[x]=cnt;
}
inline void dfs(int x){
	if(x==n*m+m+1){
		int sum1=0,sum2=0;
		for(int i=m+1;i<=n*m+m;i++){
			for(int j=h[i];j;j=w[j].next){
				int y=w[j].to;
				//cout<<w[j].val<<" ";
				//cout<<blog[y]<<" ";
				if(blog[i]!=blog[y])sum1+=w[j].val;
			}
			//cout<<sum1<<" ";
			//cout<<blog[i]<<" ";
			//if(i%m==0)cout<<endl;
			for(int j=1;j<=k;j++){
				if(d[j]==i){
					if(tt[j]!=blog[i])sum2+=xx[j];
					break;
				}
			}
		}
		sum1/=2;
		smin=min(smin,sum1+sum2);
		//cout<<smin<<endl;
		return;
	}
	blog[x]=0;
	dfs(x+1);
	blog[x]=1;
	dfs(x+1);
}
signed main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=read(),m=read(),t=read();
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=read();
			ans+=a[i][j];
			qxx(i*m+j,(i+1)*m+j,a[i][j]);
			qxx((i+1)*m+j,i*m+j,a[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++){
			b[i][j]=read();
			ans+=b[i][j];
			qxx(i*m+j,i*m+j+1,b[i][j]);
			qxx(i*m+j+1,i*m+j,b[i][j]);
		}
	}
	while(t--){
		k=read();
		if(n<=5){
			memset(blog,0,sizeof(blog));
			memset(d,0,sizeof(d));
			smin=0x7fffffff/2;
			for(int i=1;i<=k;i++){
				cin>>xx[i]>>p[i]>>tt[i];
				if(1<=p[i]&&p[i]<=m)d[i]=1*m+p[i];
				if(m+1<=p[i]&&p[i]<=m+n)d[i]=(p[i]-m)*m+m;
				if(m+n+1<=p[i]&&p[i]<=2*m+n)d[i]=n*m+m-(p[i]-m-n)+1;
				if(2*m+n+1<=p[i]&&p[i]<=2*m+2*n)d[i]=(n-(p[i]-2*m-n)+1)*m+1;
			}
			dfs(m+1);
			cout<<smin<<endl;
			continue;
		}
		if(k==2){
			int a,b,c;
			int a1,b1,c1;
			cin>>a>>b>>c;
			cin>>a1>>b1>>c1;
			if(c==c1){
				cout<<0<<endl;
			}else{
				cout<<ans-min(a1,a)<<endl;
			}
		}
	}
	return 0;
}
