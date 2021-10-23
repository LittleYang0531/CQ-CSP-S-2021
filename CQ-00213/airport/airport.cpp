#include<bits/stdc++.h>
#define debug1 cout<<"miku\n"
#define debug2(n) cout<<n<<" "
const int N=5005;
using namespace std;
struct node{
	int l,r;
};
node cn[N],ucn[N];
bool cmp(node x,node y){
	if(x.l>=y.l)return 0;
	return 1;
}
int cnt=-1;
inline int maxx(int a,int b){return a>b?a:b;}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2;
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&cn[i].l,&cn[i].r);
	}
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&ucn[i].l,&ucn[i].r);
	}
	sort(cn+1,cn+1+m1,cmp);
	sort(ucn+1,ucn+1+m2,cmp);
	int s1[N],s2[N];//分别记录第i个廊桥的空闲时间 
	for(int i=0;i<=n;i++){//枚举分配国内廊桥数量 
		int ans1=0,ans2=0;
		int j=n-i;//国际廊桥数量 
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
		for(int a=1;a<=m1;a++){//飞机 
			for(int b=1;b<=i;b++){//廊桥 
				if(s1[b]<=cn[a].l){
					s1[b]=cn[a].r;
					ans1++;
					//debug2(ans1); 
					break;
				}
			}
		}
		for(int a=1;a<=m2;a++){//飞机 
			for(int b=1;b<=j;b++){//廊桥 
				if(s2[b]<=ucn[a].l){
					s2[b]=ucn[a].r;
					ans2++;
					//debug2(ans2); 
					break;
				}
			}
		}
		//debug2(ans1);
		//debug1;
		//debug2(ans2); 
		cnt=maxx(cnt,ans1+ans2);
	}
	printf("%d",cnt);
	return 0;
}
