#include<algorithm>
#include<cstdio>
#include<deque>
int read(){
	int x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x;
}
const int maxn=1e6+5;
int nwc;
int t;
int n;
int val[maxn],tot[maxn];
int oth[maxn];
char op[maxn];
int ocnt;
struct state{
	int nl,nr;
	int llim,rlim;
};
std::deque<state>dq;
int mem[maxn],mcnt;
void go(state gave){
	int nl=gave.nl,nr=gave.nr,llim=gave.llim,rlim=gave.rlim;
	if(nr-nl+1==n){
		int lwz=1,rwz=2*n;
		for(int i=1;i<=mcnt;i++){
			if(mem[i]==lwz){
				op[++ocnt]='L';
				lwz++;
			}
			else{
				op[++ocnt]='R';
				rwz--;
			}
		}
		for(int i=1;i<=mcnt;i++)mem[i]=oth[mem[i]];
		std::reverse(mem+1,mem+mcnt+1);
		for(int i=1;i<=mcnt;i++){
			if(mem[i]==lwz){
				op[++ocnt]='L';
				lwz++;
			}
			else{
				op[++ocnt]='R';
				rwz--;
			}
		}
		return;
	}
	if(oth[llim]==nl-1&&!op[1]&&llim!=nl){
		mem[++mcnt]=llim;
		go((state){nl-1,nr,llim+1,rlim});
		mcnt--;
	}
	else if(oth[llim]==nr+1&&!op[1]&&llim!=nl){
		mem[++mcnt]=llim;
		go((state){nl,nr+1,llim+1,rlim});
		mcnt--;
	}
	if(oth[rlim]==nl-1&&!op[1]&&rlim!=nr){
		mem[++mcnt]=rlim;
		go((state){nl-1,nr,llim,rlim-1});
		mcnt--;
	}
	else if(oth[rlim]==nr+1&&!op[1]&&rlim!=nr){
		mem[++mcnt]=rlim;
		go((state){nl,nr+1,llim,rlim-1});
		mcnt--;
	}
	return;
}
char emp;
signed main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=read();
	for(int wc=1;wc<=t;wc++){
		nwc=wc;
		for(int i=1;i<=ocnt;i++)op[i]=emp;
		ocnt=0;
		for(int i=1;i<=n;i++)tot[i]=0;
		n=read();
		for(int i=1;i<=2*n;i++){
			val[i]=read();
			tot[val[i]]+=i;
		}
		for(int i=1;i<=2*n;i++)oth[i]=tot[val[i]]-i;
		mem[++mcnt]=1;
		go((state){oth[1],oth[1],2,2*n});
		mcnt--;
		if(op[1]){
			for(int i=1;i<=2*n;i++)printf("%c",op[i]);
			printf("\n");
			continue;
		}
		mem[++mcnt]=2*n;
		go((state){oth[2*n],oth[2*n],1,2*n-1});
		mcnt--;
		if(op[1]){
			for(int i=1;i<=2*n;i++)printf("%c",op[i]);
			printf("\n");
			continue;
		}
		else printf("-1\n");
	}
	return 0;
}
/*
I love you CCF.
Why is T3 a solution-making problem?
*/
/*
The to line is an adjacent line.
O(n).
*/
/*
3
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
3
1 2 3 1 2 3
*/
/*
1
20
4 18 2 9 9 19 10 6 8 7 14 20 5 4 1 13 17 18 12 15 11 2 16 3 3 16 11 15 12 19 17 10 13 1 5 6 20 14 7 8 
RRRRRRLRRRRLRRRRLLLRRRRRRRRLRRLRRRRLRRRL
*/
/*
I've done my best.
*/
