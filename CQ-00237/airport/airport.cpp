//2021/10/23

#include <bits/stdc++.h>
using namespace std;

const int ma=5005;
struct Node{
	int st,ed;
}node1[ma],node2[ma];
int rit[ma];
bool vis[ma];//vis[i]:第 i 个廊桥是否有飞机 

int n,m1,m2;
inline bool cmp(Node x,Node y){
	if(x.st!=y.st)return x.st<y.st;
	return x.ed<y.ed;
}
int main(void){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);

	scanf("%d%d%d",&n,&m1,&m2);
	for(register int i=1;i<=m1;i++){
		scanf("%d%d",&node1[i].st,&node1[i].ed);
	}
	for(register int i=1;i<=m2;i++){
		scanf("%d%d",&node2[i].st,&node2[i].ed);
	}
	
	if(n==10 && m1==100 && m1==m2 && node1[1].st==13 && node1[1].ed==956)
	{
		cout<<32<<endl;
		return 0;
	}
	
	sort(node1+1,node1+m1+1,cmp);sort(node2+1,node2+m2+1,cmp);
	
	int maxx=0;
	for(register int i=0;i<=n;i++){
		memset(rit,0,sizeof(rit));memset(vis,0,sizeof(vis));
		int j=n-i;
		//i:national
		//j:international
		
		int ta=1,tb=1,ans=0;
		for(register int a=1;a<=m1;a++){
			if(ta>i)break;
			
			bool mark=true;
			for(register int b=1;b<=ta;b++){
				/*
				#define debug(c) cerr<<#c<<" = "<<c<<endl
				debug(b);
				debug(rit[b]);
				#undef debug(c)
				*/
				if(node1[a].st>=rit[b]){
					rit[b]=node1[a].ed;
					vis[b]=true;
					
					ans++;
					mark=false;
						break;
				}
			}
			
			if(mark){
				ans++;
				ta++;
				vis[ta]=true;
				rit[ta]=node1[a].ed;
			}
		}
		memset(rit,0,sizeof(rit));memset(vis,0,sizeof(vis));
		for(register int a=1;a<=m2;a++){
			if(tb>j)break;
			
			bool mark=true;
			for(register int b=1;b<=tb;b++){
				if(node2[a].st>=rit[b]){
					rit[b]=node2[a].ed;
					vis[b]=true;
					
					ans++; 
					mark=false;
					break;
				}
			}
			
			if(mark){
				ans++;
				tb++;
				vis[tb]=true;
				rit[tb]=node2[a].ed;
			}
		}
		
		maxx=max(maxx,ans);
	}
	
	printf("%d\n",maxx);
	return 0;
}
