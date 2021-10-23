#include<bits/stdc++.h>
#define N 500002
using namespace std;
int T,n,a[N*2],b[N*2];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=2*n;i++){
			scanf("%d",&a[i]);
		}
		long long k=0;
		int fll=1;
		for(;k<(1<<(2*n));k++){
//			cout<<k;
//			for(int i=1;i<=2*n;i++){
//				if(((k>>(i-1))%2)==0)cout<<'L';
//				else cout<<'R';
//			}
//			for(int o=1;o<=100000000;o++);
//			cout<<endl;
			int fl=1;int f=1,t=n*2;
			memset(b,0,sizeof(b));
			for(int i=n*2;i>=1;i--){
				if(((k>>(i-1))%2)==0)b[++b[0]]=a[f],f++;
				else b[++b[0]]=a[t],t--;
//				cout<<b[b[0]]<<' ';
				if(b[b[0]]!=b[2*n-b[0]+1]&&b[2*n-b[0]+1]){
					fl=0;break;
				}
			}
//			cout<<endl;
			if(fl){
				for(int i=2*n;i>=1;i--){
					if(((k>>(i-1))%2)==0)cout<<'L';
					else cout<<'R';
				}
				fll=0;
				cout<<endl;
				break;
			}
		}
		if(fll){
			cout<<-1<<endl;
		}
	}
	return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
*/

