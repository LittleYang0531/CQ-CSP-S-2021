#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') w*=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;	
}
int T,n,l,r;
int R[N],p[N],a[2*N];
int num[N];
char ans[2*N],temp[2*N];
bool flag;
inline void Solve(int x,int y,int A,int B) //记录目前的位置 
{
	int cnt=1;
	while(A>=l||B<=r){ //选完为止 
		if(x<l&&y==r){ //只能选x 
			if(a[x]==a[B]&&B<=r) B++;
			else if(a[x]==a[A]&&A>=l) A--;
			else return; //一个都不行 
			x++;
			temp[++cnt]='L';
			continue;
		}
		if(x==l&&y>r){
			if(a[y]==a[B]&&B<=r) B++;
			else if(a[y]==a[A]&&A>=l) A--;
			else return;
			y--;
			temp[++cnt]='R';
			continue;
		}
		//理论上两边都能选
		//先选小的
		int tx=x,ty=y;
		if(a[x]==a[B]&&B<=r) B++,x++;
		else if(a[x]==a[A]&&A>=l) A--,x++;
		else if(a[y]==a[B]&&B<=r) B++,y--;
		else if(a[y]==a[A]&&A>=l) A--,y--;
		else return;
		if(tx!=x) temp[++cnt]='L';
		else temp[++cnt]='R';
	}
	flag=true; //匹配成功 
}
inline void out()
{
	int x=1,y=2*n,tot=0;
	for(register int i=1;i<=n;i++){
		if(temp[i]=='L') R[++tot]=a[x],x++;
		else R[++tot]=a[y],y--;
	}
	for(register int i=n+1;i<=2*n;i++){
		if(R[tot]==a[x]) temp[i]='L',x++;
		else temp[i]='R',y--;
		tot--;
	}
	for(register int i=1;i<=2*n;i++){
		if(ans[i]<temp[i]) return;
		if(temp[i]<ans[i]) break;
	}
	for(register int i=1;i<=2*n;i++) ans[i]=temp[i];
}
inline void update()
{
	for(register int i=l;i<=r;i++) p[a[i]]=i; //记录位置
	flag=false;
	if(l>1) temp[1]='L',Solve(2,2*n,p[a[1]]-1,p[a[1]]+1);
	if(flag) { out(); return; }
	if(r<2*n) temp[1]='R',Solve(1,2*n-1,p[a[2*n]]-1,p[a[2*n]]+1); //从两个位置出发做一遍 
	if(flag) { out(); return; }
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--){
		ans[1]='Z'; //初始值 
		n=read();
		for(register int i=1;i<=2*n;i++) a[i]=read();
		//首先要找到两个不同的区间 
		int cnt=0; //记录合法的数的数量 
		for(register int i=1;i<=n;i++){
			if(!num[a[i]]) num[a[i]]++,cnt++;
			else num[a[i]]++,cnt--; //不合法 
		}
		l=-1,r=-1;
		for(register int i=n;i<=2*n;i++){ //枚举末端 
			if(cnt==n){ //该区间合法 
				l=i-n+1,r=i;
				update();
			}
			if(i==2*n) continue;
			num[a[i-n+1]]--;
			if(num[a[i-n+1]]==1) cnt++; //合法 
			else cnt--; //不合法
			if(!num[a[i+1]]) num[a[i+1]]++,cnt++;
			else num[a[i+1]]++,cnt--;
		}
		for(register int i=1;i<=n;i++) num[i]=0;
		if(l==-1&&r==-1){ printf("-1\n"); continue; } //没有这样的区间
		if(ans[1]=='Z') printf("-1\n");
		else{
			for(register int i=1;i<=2*n;i++)
				printf("%c",ans[i]);
			printf("\n");
		}
	}
	return 0;
}
