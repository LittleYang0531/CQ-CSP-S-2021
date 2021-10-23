#include<bits/stdc++.h>
using namespace std;

template <typename T> inline void read(T &n){
	n=0;T w=1;char ch=getchar();
	while(!isdigit(ch)&&ch!=EOF){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)&&ch!=EOF){n=(n<<3)+(n<<1)+(ch&15);ch=getchar();}
	n*=w;
}

int n,m1,m2,q[100005],vis[100005];
struct airport{
	int l,r;
}a[100005],b[100005];

bool cmp(airport i,airport j){
	if(i.l!=j.l) return i.l<j.l;
	return i.r<j.r;
}

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	read(n);read(m1);read(m2);
	for(int i=1;i<=m1;i++){
		read(a[i].l);
		read(a[i].r);
	}
	sort(a+1,a+1+m1,cmp);
	for(int i=1;i<=m2;i++){
		read(b[i].l);
		read(b[i].r);
	}
	sort(b+1,b+1+m2,cmp);
	int res=0;
	for(int i=0;i<=n;i++){
		int j=n-i;
		int sum1=0,ans1=0,head=1,tail=0;
		for(int x=1;x<=m1;x++){
			for(int t=head;t<=tail;t++){
				if(a[q[t]].r<=a[x].l&&vis[q[t]]==1){
				    sum1--;	
				    vis[q[t]]=0;
				    break;
				}
			}
			if(sum1<i){
				sum1++;
				ans1++;
				q[++tail]=x;
				vis[x]=1;
			}
		}
		memset(vis,0,sizeof vis);
		int sum2=0,ans2=0;
		head=1,tail=0;
		for(int x=1;x<=m2;x++){
			for(int t=head;t<=tail;t++){
				if(b[q[t]].r<=b[x].l&&vis[q[t]]==1){
				    sum2--;	
				    vis[q[t]]=0;
				    break;
				}
			}
			if(sum2<j){
				sum2++;
				ans2++;
				q[++tail]=x;
				vis[x]=1;
			}
		}
		res=max(res,ans1+ans2);
	}
	printf("%d\n",res);
	return 0;
}
