#include <bits/stdc++.h>
using namespace std;

struct flight{
	int come,leave;
	bool con;
	int nxt;
}ft[100100];

int n,ne,nw;

int nee[100100],nww[100100];

bool cmp(flight a,flight b){
	return a.come < b.come;
}

int main(){
	
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	scanf("%d%d%d",&n,&ne,&nw);
	
	int i;
	for(i=1;i<=ne;i++){
		scanf("%d%d",&ft[i].come,&ft[i].leave);
		ft[i].con = 0;
	}
	
	for(;i<=nw+ne;i++){
		scanf("%d%d",&ft[i].come,&ft[i].leave);
		ft[i].con = 1;
	}
	sort(ft+1,ft+nw+ne,cmp);
	int tot=i;
//	lv = ft[1].leave;
//	li = 1;
//	for(int i=2;i<=tot;i++){
//		if(ft[i].come > lv){
//			ft[li].nxt = i;
//			lv = ft[i].leave;
//			li = i;
//		}
//	}
	
	
	int stoped=0,ans=0;
	tot--;
	for(int i=0,j=n;i<=n&&j>=0;i++,j--){
		memset(nee,0x3f,sizeof nee);
		memset(nww,0x3f,sizeof nww);
		nee[0]=1;
		nww[0]=1;
		for(int k=1;k<=tot;k++){
			
			if(!ft[k].con){
				
				//if(nee[0] > i)continue;
				//if(ft[k].come < nee[nee[0]])continue;
				for(int l=1;l<=nee[0];l++){
					if(l == nee[0]&&nee[0] <= i){
						nee[nee[0]]=ft[k].leave,stoped++;
						nee[0]++;
						break;
					}
					else if(ft[k].come > nee[l]){
						nee[l] = ft[k].leave,stoped++;
						break;
					}
					
				}
			}
			if(ft[k].con){
				
				//if(nww[0] > j)continue;
				//if(ft[k].come < nww[nww[0]])continue;
				
				for(int l=1;l<=nww[0];l++){
					if(l == nww[0]&&nww[0] <= j){
						nww[nww[0]]=ft[k].leave,stoped++;
						nww[0]++;
						break;
					}
					else if(ft[k].come > nww[l]){
						nww[l] = ft[k].leave,stoped++;
						break;
					}
					
				}
				
			}
			
		}
		//printf("%d %d %d\n",i,j,stoped);
		ans = max(ans,stoped);
		stoped = 0;
	}
	printf("%d",ans);
	return 0;
}
