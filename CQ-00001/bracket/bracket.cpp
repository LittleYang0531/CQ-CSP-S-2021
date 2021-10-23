#include<bits/stdc++.h>
using namespace std;
int n,k;
char c[500];
int fnum=0,snum=0,cnt=0;
void solve(int x){
	if(x>=n){
		if(fnum==0){
			for(int i=0;i<x;i++)
		    cnt++;
		}
		cnt=cnt%1000000007;
		return;
	}
	if(c[x]=='('){
		int t=snum;
		fnum++;
		if(fnum<0||snum>k){
			fnum--;
			return;
		}
		snum=0;
		solve(x+1);
		fnum--;
		//snum=t;
		return;
	}
	else if(c[x]==')'){
		int t=snum;
		fnum--;
		if(fnum<0||snum>k){
			fnum++;
			return;
		}
		snum=0;
		solve(x+1);
		fnum++;
		//snum=t;
		return;
	}
	else if(c[x]=='*'){
		snum++;
		if(fnum<0||snum>k){
			snum--;
			return;
		}
		solve(x+1);
		snum--;
		return;
    }
	if(fnum!=0){
		fnum--;
		c[x]=')';
		solve(x+1);
		c[x]='?';
		fnum++;
	}
	if(snum<k&&x!=0&&x!=n-1){
		snum++;
		c[x]='*';
		solve(x+1);
		c[x]='?';
		snum--;
	}
	if(fnum+1-n+x<=0){
		fnum++;
		c[x]='(';
		solve(x+1);
		c[x]='?';
		fnum--;
	}
	return;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	scanf("%s",c);
	solve(0);
	printf("%d",cnt);
	return 0;
}
