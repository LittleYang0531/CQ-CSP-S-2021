#include<bits/stdc++.h>
using namespace std;

const int Maxn=1e6+10;
int T,N,Loc[Maxn],top,Step[Maxn],cnt;
bool Vis[Maxn],flag;
vector<int> step,A;

void Print(){
	if(flag) return;
//	cout<<"Here";
	for(int i=0;i<step.size();i++){
		if(step[i]==0) putchar('L');
		else putchar('R');
	}puts("");
	return;
}

void DFS(int x,int fx){
	if(x>=2*N||top>=2*N) return;
	if(x==2*N-1){
		step.push_back(fx);
		Print();
		step.pop_back();
		flag=true;
		return;
	}
	int tmp,f; 
	if(fx==0) tmp=A[top],top++,f=1;
	else tmp=A.back(),A.pop_back(),f=2;
//	cout<<x<<" "<<fx<<" "<<tmp<<" "<<top<<"\n";
	if(Vis[tmp]&&x+1!=2*N+1-Loc[tmp]-1){
		if(f==1) top--;
		else A.push_back(tmp);
		return;
	}
	Vis[tmp]=true; Loc[tmp]=x; 
	step.push_back(fx);
	DFS(x+1,0); DFS(x+1,1);
	Vis[tmp]=false; Loc[tmp]=0; step.pop_back();
	if(f==1) top--;
	else A.push_back(tmp);
}

int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		while(!A.empty()) A.pop_back();
		memset(Vis,0,sizeof Vis);
		memset(Loc,0,sizeof Loc);
		scanf("%d",&N); flag=false;
		for(int x,i=1;i<=2*N;i++){
			scanf("%d",&x);
			A.push_back(x);
		}
//		for(int i=0,j=N-1;i<j;i++,j--)
//			if(A[i]!=A[j]){ tag=true; break; }
//		for(int i=0;i<2*N;i++) cout<<A[i]<<" ";
//		cout<<"\n";
		if(N<=1000){
			DFS(0,0); if(!flag) DFS(0,1);
			if(!flag) puts("-1");
		}else{
			while(top<A.size()-1){
				if(A[top]==A[top+1]){
					Step[++cnt]=0; Step[2*N-cnt+1]=0;
					top+=1; 
				}else{
					if(A[top]==A.back()){
						Step[++cnt]=0; Step[2*N-cnt+1]=1;
						top++; A.pop_back();
					}else{
						Step[++cnt]=1; Step[2*N-cnt+1]=1;
						A.pop_back();
					}
				}
			}
			for(int i=1;i<=2*N;i++){
				if(Step[i]==1) putchar('R');
				else putchar('L');
			}
		}
	}
	return 0;
}
