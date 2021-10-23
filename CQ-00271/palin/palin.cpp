#include<stdio.h>
#define R register int
#define I inline
int a[1000001],pos[500001][2];
char ans[1000000];
I void Print(const int n){
	for(R i=0;i!=n;i++){
		putchar(ans[i]);
	}
	puts("");
}
I bool Check(int l1,int r1,int l2,int r2,const int n){
	for(R i=1;i!=n;i++){
		if(l1<=r1){
			if(pos[a[l1]][1]==r1){
				l1++;
				r1--;
				ans[i]='L';
				ans[(n<<1)-i-1]='L';
				continue;
			}
			if(pos[a[l1]][1]==l2){
				l1++;
				l2++;
				ans[i]='L';
				ans[(n<<1)-i-1]='R';
				continue;
			}
		}
		if(l2<=r2){
			if(pos[a[r2]][0]==r1){
				r2--;
				r1--;
				ans[i]='R';
				ans[(n<<1)-i-1]='L';
				continue;
			}
			if(pos[a[r2]][0]==l2){
				r2--;
				l2++;
				ans[i]='R';
				ans[(n<<1)-i-1]='R';
				continue;
			}
		}
		return false;
	}
	return true;
}
I void Solve(){
	int n;
	scanf("%d",&n);
	for(R i=1;i<=n;i++){
		pos[i][0]=0;
	}
	for(R i=1;i<=n<<1;i++){
		scanf("%d",a+i);
		if(pos[a[i]][0]==0){
			pos[a[i]][0]=i;
		}else{
			pos[a[i]][1]=i;
		}
	}
	if(Check(2,pos[a[1]][1]-1,pos[a[1]][1]+1,n<<1,n)==true){
		ans[0]=ans[(n<<1)-1]='L';
		Print(n<<1);
	}else if(Check(1,pos[a[n<<1]][0]-1,pos[a[n<<1]][0]+1,(n<<1)-1,n)==true){
		ans[0]='R';
		ans[(n<<1)-1]='L';
		Print(n<<1);
	}else{
		puts("-1");
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}
