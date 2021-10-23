#include<bits/stdc++.h>
using namespace std;

const int Maxn=510;
int N,K,ans,A[Maxn];
string S;
vector<int> S1;

bool check(){
	int stk=0,sumk=0;
	int flag=0;
	for(int i=0;i<N;i++){
		if(S1[i]==1) stk++,sumk=0;
		if(S1[i]==2){
			if(stk==0) return 0;
			stk--,sumk=0;
		}
		if(S1[i]==3){
			sumk++;
			if(sumk>K) return 0;
		}
	}
	if(S1[N-1]!=2) return 0;
	if(stk>0) return 0;
	
	return 1;
}

void DFS(int x,int ch){
	if(A[x]!=-1&&A[x]!=ch) return;
//	cout<<x<<" "<<ch<<"\n";
	S1.push_back(ch);
	if(x==N-1){
		if(check()){
			ans++;
//			for(int i=0;i<N;i++){
//				if(S1[i]==1) putchar('(');
//				if(S1[i]==2) putchar(')');
//				if(S1[i]==3) putchar('*');
//			}
//			puts("");
		}
		S1.pop_back();
		return;
	}
	if(A[x+1]!=-1) DFS(x+1,A[x+1]);
	else DFS(x+1,1),DFS(x+1,2),DFS(x+1,3);
	S1.pop_back();
}

void Sol1(){
	for(int i=0;i<N;i++){
		if(S[i]=='?') A[i]=-1;
		if(S[i]=='(') A[i]=1;
		if(S[i]==')') A[i]=2;
		if(S[i]=='*') A[i]=3;
	}
//	for(int i=0;i<N;i++) cout<<A[i]<<" ";
	if(A[0]==2||A[0]==3){
		puts("0");
		return;
	}
	DFS(0,1);
	printf("%d",ans);
}

//void Sol2(){
//	for(int i=0;i<S.size();i++){
//		
//	}
//	
//}

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d %d",&N,&K); cin>>S;
	if(N<=15) Sol1();
//	else Sol2();
	return 0;
}
