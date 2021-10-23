#include<bits/stdc++.h>
using namespace std;
const int p=1e9+7;
int n,k,ans=0;
char s[505];
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d%s",&n,&k,s);
	for(int i=0;i<strlen(s);i++){
		if(s[i]=='?'){
			ans++;
		}
	}
	ans=(ans-1)*(ans-2)-1;
	printf("%d",ans%p);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
