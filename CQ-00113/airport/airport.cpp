#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,icp,ocp;
int airic[100005][2],airoc[100005][2];
int icl,ocl,cl[100005],maxx=0;
int more[100005],icm[100005],ocm[100005],mic=0,moc=0,mp;
inline void zl(){
	for(int i=1;i<=icp;i++)
		for(int j=1;j<i;j++)
			if(airic[j][0]>airic[j+1][0]){
				swap(airic[j][0],airic[j][0]);
				swap(airic[j][1],airic[j][1]);
			}
	for(int i=1;i<=ocp;i++)
		for(int j=1;j<i;j++)
			if(airoc[j][0]>airoc[j+1][0]){
				swap(airoc[j][0],airoc[j][0]);
				swap(airoc[j][1],airoc[j][1]);
			}
}
inline int sea(int arr,bool to){
	if(to){
		for(int i=1;i<=icl;i++){
			if(cl[i]<arr) return i;
		}
	}else{
		for(int i=icl+1;i<=n;i++){
			if(cl[i]<arr) return i;
		}
	}
	return 0;
}
inline void clee(){
	for(int i=1;i<=icp;i++){
		int k=sea(airic[i][0],0);
		if(k>0) mp++,cl[k]=airic[i][1];
	}
	for(int i=1;i<=ocp;i++){
		int k=sea(airoc[i][0],1);
		if(k>0) mp++,cl[k]=airoc[i][1];
	}
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d %d %d",&n,&icp,&ocp);
	for(int i=1;i<=icp;i++) scanf("%d %d",&airic[i][0],&airic[i][1]);
	for(int i=1;i<=ocp;i++) scanf("%d %d",&airoc[i][0],&airoc[i][1]);
	zl();
	for(icl=0;icl<=n;icl++){
		mp=0;
		memset(cl,0,sizeof(cl));
		ocl=n-icl;
		clee();
		maxx=max(mp,maxx);
//		printf("%d\n",mp);
	}
	printf("%d\n",maxx);
	
	return 0;
}
