#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5*10;
int t,n,a[maxn+5],fir[maxn+5],sec[maxn+5],m[maxn+5],cnt,flag=0;
char ans[maxn+5];
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	while(t--) {
		scanf("%d",&n);
		int cnt=0;
		for(int i=1; i<=2*n; i++) {
			scanf("%d",&a[i]);
			if(!fir[a[i]]) {
				fir[a[i]]=i;
			} else {
				sec[a[i]]=i;
			}
		}
		ans[1]='L';
		for(int i=2,j=2,f=2*n;i<=2*n;i++) {
			if(sec[a[j]]+1==sec[a[j-1]]||sec[a[j]]-1==sec[a[j-1]]||sec[a[j]]+1==sec[a[f]]||sec[a[j]]-1==sec[a[f]]){
				j++;
				ans[i]='L';
			}else if(fir[a[f]]+1==sec[a[j]]||fir[a[f]]-1==sec[a[j]]||fir[a[f]]+1==sec[a[f+1]]||fir[a[f]]-1==sec[a[f+1]]) {
				f--;
				ans[i]='R';
			}else {
				flag=1;
				cout<<-1<<endl;
				break;
			}
		}
		if(!flag){
			for(int i=1;i<=2*n;i++){
				printf("%c",ans[i]);
			}
		}
	}
		return 0;
}
