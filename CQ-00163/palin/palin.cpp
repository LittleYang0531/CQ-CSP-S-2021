#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
bool flag;
int n,a[1000005],b[1000005],to,fl,x;
char c[1000005];
int re(){ int temp;scanf("%d",&temp); return temp;}
void check(){
	for(int i=1;i<=n;i++)
	 if(b[i]!=b[n*2+1-i]) {flag=false;return;}
	flag=true;
	for(int i=1;i<=n*2;i++)
  	       printf("%c",c[i]);
  	printf("\n");
}
void dfs(int bu){
	if(flag) return;
	if(to>fl) return; 
	if(bu==n*2+1) {check();return;}
	b[bu]=a[++to];c[bu]='L';	
//	printf("%d L %d %d %d\n",bu,to,fl,b[bu]);
	//scanf("%d",&x);
	dfs(bu+1);to--;
	if(flag) return;
	b[bu]=a[--fl];c[bu]='R';
	//scanf("%d",&x);
	//printf("%d R %d %d %d\n",bu,to,fl,b[bu]);
	dfs(bu+1); fl++;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T=re();

	while(T){T--;
	
	flag=false;
	memset(c,32,sizeof(c));
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	n=re();
	to=0;fl=2*n+1;
	for(int i=1;i<=n*2;i++)
 	 a[i]=re();
	dfs(1);	
	if(!flag){
	      printf("-1\n");
	}}
	return 0;
}
