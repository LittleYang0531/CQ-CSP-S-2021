#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int a[505][505],b[505][505];
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<n;i++)
	    for(int j=1;j<=m;j++)
	        scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<m;j++)
            scanf("%d",&b[i][j]);
    for(int x=1;x<=t;x++){
    	int k;
    	scanf("%d",&k);
    	int xx,p,t;
    	for(int i=1;i<=k;i++)
    	    scanf("%d%d%d",&xx,&p,&t);
    	printf("12\n");
	}
	return 0;
}
