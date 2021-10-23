#include<bits/stdc++.h>
using namespace std;

const int N = 505;

int n , k;
char s[N];
int nu[500] , a[N] , ans ;

void dfs(int step , int las , int cnt1 , int cnt2){
	if(step == n+1){
		if(cnt1 != cnt2) return ;
		int cnt11 = 0 ;
		for(int i=1;i<=n;i++){
			if(a[i] == 1){
				if(a[i-1] == 3) nu[cnt11] ++;
				cnt11 ++; nu[cnt11] = 0;
			}
			else if(a[i] == 2){
				if( nu[cnt11] > 0 ) return;
				cnt11 --;
				nu[cnt11] --;
				if(a[i+1] == 3) nu[cnt11] ++;
			}
		}
		if(a[1] == 3 || a[n] == 3) return ;
		ans ++;		
//		for(int i=1;i<=n;i++)
//			printf("%d",a[i]);
//		printf("\n");
	}
	if(s[step] != '?'){
		if(s[step] == '*' && las < k){
			a[step] = 3;
			dfs(step + 1 , las + 1 , cnt1 , cnt2 );
		}
		if(s[step] == '(' && n - step + cnt2 >= cnt1 + 1){
			a[step] = 1;
			dfs(step + 1 , 0 , cnt1 + 1 , cnt2 );
		}
		if(s[step] == ')' && cnt1 > cnt2){
			a[step] = 2;
			dfs(step + 1 , 0 , cnt1 , cnt2 + 1 );
		}
		return ;
	}
	
	if(n - step + 1 + cnt2 == cnt1 ){
		a[step] = 2;
		dfs(step + 1 , 0 , cnt1 , cnt2 + 1);
		return ;
	}
	if(cnt2 + 1 <= cnt1 ){
		a[step] = 2;
		dfs(step + 1 , 0 , cnt1 , cnt2 + 1);
	}
	if(las < k){
		a[step] = 3;
		dfs(step + 1 , las + 1 , cnt1 , cnt2 );
	}
	if(n - step + cnt2 >= cnt1 + 1){
		a[step] = 1;
		dfs(step + 1 , 0 , cnt1 + 1 , cnt2);
	}
}

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	
	scanf("%d %d",&n,&k);
	
	scanf("%s",s+1);
	
	dfs(1 , 0 , 0 , 0);
	
	printf("%d",ans);
	
	return 0;
}
//1312332
//(*()**)
