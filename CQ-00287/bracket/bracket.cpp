#include <bits/stdc++.h>
using namespace std;
const int mod=1000000007;

int n,k,que;
string str;

stack<int> stk;
int main(){
	
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	
	//printf("0");
	
	scanf("%d%d",&n,&k);
	
	cin>>str;
	
	int stars;
	for(int i=0;i<n;i++){
		if(str[i] == '(') stk.push(i),stars=0;
		else if(str[i] == ')'){
			if(stk.empty()){
				printf("0");
				return 0;
			}
			
			stk.pop();
			stars = 0;
			
		}
		if(str[i] == '*')stars++;
		
		if(str[i] == '?')que++;
		
		if(stars > k){
			printf("0");
			return 0;
		}
	}	
	int ans = 1;
	
	for(int i=1;i<=que;i++){
		ans=((ans%mod)*2)%mod;
	}
	
	printf("%d",ans%mod);
	return 0;
}
