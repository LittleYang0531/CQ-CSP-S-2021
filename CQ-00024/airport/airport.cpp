#include<bits/stdc++.h>
using namespace std;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;	
}
const int N=1e5+5;
int n,m1,m2;
struct node{
	int l,r;
}a1[N],a2[N];
inline bool cmp(const node &a,const node &b){return a.l<b.l;}
int num1[N<<1],num2[N<<1],o1,o2;
int id1[N<<1],id2[N<<1],id3[N<<1],id4[N<<1];
int c1[N],c2[N];
inline void add1(int a,int b){for(int i=a;i<=n;i+=i&-i)c1[i]+=b;}
inline void add2(int a,int b){for(int i=a;i<=n;i+=i&-i)c2[i]+=b;}
inline int get1(int a){
	int sum=0;
	for(int i=a;i>=1;i-=i&-i)sum+=c1[i];
	return sum;
}
inline int get2(int a){
	int sum=0;
	for(int i=a;i>=1;i-=i&-i)sum+=c2[i];
	return sum;	
}
int p1[N],p2[N],s1[N],s2[N];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=in(),m1=in(),m2=in();
	for(int i=1;i<=m1;i++)
		a1[i].l=in(),a1[i].r=in(),num1[++o1]=a1[i].l,num1[++o1]=a1[i].r;
	for(int i=1;i<=m2;i++)
		a2[i].l=in(),a2[i].r=in(),num2[++o2]=a2[i].l,num2[++o2]=a2[i].r;
	sort(num1+1,num1+o1+1);
	sort(num2+1,num2+o2+1);
	sort(a1+1,a1+m1+1,cmp);
	sort(a2+1,a2+m2+1,cmp);
	for(int i=1;i<=m1;i++){
		a1[i].l=lower_bound(num1+1,num1+o1+1,a1[i].l)-num1;
		a1[i].r=lower_bound(num1+1,num1+o1+1,a1[i].r)-num1;
		id1[a1[i].l]=i,id2[a1[i].r]=i;
	}
	for(int i=1;i<=m2;i++){
		a2[i].l=lower_bound(num2+1,num2+o2+1,a2[i].l)-num2;
		a2[i].r=lower_bound(num2+1,num2+o2+1,a2[i].r)-num2;
		id3[a2[i].l]=i,id4[a2[i].r]=i;
	}
	for(int i=1;i<=o1;i++){
		if(id1[i]){
			int l=0,r=n,mid,res=n+1;
			while(l<=r){
				mid=l+r>>1;
				if(get1(mid)>=mid)l=mid+1;
				else r=mid-1,res=mid;
			}
			p1[id1[i]]=res;
			add1(res,1);
		}else add1(p1[id2[i]],-1);
	}
	for(int i=1;i<=o2;i++){
		if(id3[i]){
			int l=0,r=n,mid,res=n+1;
			while(l<=r){
				mid=l+r>>1;
				if(get2(mid)>=mid)l=mid+1;
				else r=mid-1,res=mid;
			}
			p2[id3[i]]=res;
			add2(res,1);
		}else add2(p2[id4[i]],-1);
	}
	for(int i=1;i<=m1;i++)s1[p1[i]]++;
	for(int i=1;i<=m2;i++)s2[p2[i]]++;
	for(int i=1;i<=n;i++)s1[i]+=s1[i-1];
	for(int i=1;i<=n;i++)s2[i]+=s2[i-1];
	int ans=0;
	for(int i=0;i<=n;i++)ans=max(ans,s1[i]+s2[n-i]);
	cout<<ans;
	return 0;
}

