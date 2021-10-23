#include<bits/stdc++.h>
using namespace std;

const int Maxn=1010;
const double down=0.992;
long long ans=1e18;
int k=100,N,M,T,num[Maxn][Maxn],clos[Maxn],point;
int col[Maxn][Maxn];
struct query{
	int col,line,val;
}Q[55];

int Sol(){
	int ret=0;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			if(col[i][j]!=col[i][j+1]) ret+=num[(i-1)*M+j][(i-1)*M+j+1];
			if(col[i+1][j]!=col[i][j]) ret+=num[(i-1)*M+j][i*M+j];
		}
	}
	for(int i=1;i<=point;i++){
		if(Q[i].col!=col[(clos[Q[i].line]-1)/M+1][(clos[Q[i].line]-1)%M+1])
			ret+=Q[i].val;
	}
	return ret;
}

void fire(){
	int tmpr=7000;
	while(tmpr>1e-12){
		int tx=rand()%(N+1),ty=rand()%(M+1);
		col[tx][ty]=1;
		int now_ans=Sol();
		if(now_ans<ans) ans=now_ans;
//		else if(exp((ans-now_ans)/tmpr)<(double)rand()/RAND_MAX) ans=now_ans;
		else col[tx][ty]=0;
		tmpr*=down;
	}
//	for(int i=1;i<=N;i++){
//		for(int j=1;j<=M;j++){
//			cout<<col[i][j]<<" ";
//		}cout<<"\n";
//	}
//	cout<<"Here "<<ans<<"\n\n";
	return;
}

int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	srand(time(0));
	scanf("%d %d %d",&N,&M,&T);
	for(int i=1;i<N;i++) for(int j=1;j<=M;j++)
		scanf("%d",&num[(i-1)*M+j][i*M+j]);
	for(int i=1;i<=N;i++) for(int j=1;j<M;j++)
		scanf("%d",&num[(i-1)*M+j][(i-1)*M+j+1]);
	for(int i=1;i<=2*N+2*M;i++){
		if(i<=M) clos[i]=i;
		else if(i<=M+N) clos[i]=(i%M)*M+M;
		else if(i<=2*M+N) clos[i]=(N-1)*M-(i%(M+N))+1;
		else clos[i]=(N-(i%(2*M+N)))*M+1;
	}
	while(T--){
		ans=1e18;
		scanf("%d",&point);
		for(int i=1;i<=point;i++){
			scanf("%d %d %d",&Q[i].val,&Q[i].line,&Q[i].col);
//		cout<<"Here "<<clos[Q[i].line]<<"\n";
		}
		while(k--) fire();
		printf("%d",ans);
	}
	return 0;
}
