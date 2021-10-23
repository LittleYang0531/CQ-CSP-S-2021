#include <bits/stdc++.h>
using namespace std;

int n,m,T;

int main(){
	
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&T);
	
	srand(rand());
	
	for(int i=1;i<=T;i++)cout<<abs(rand())%5253800;
	
	return 0;
}
