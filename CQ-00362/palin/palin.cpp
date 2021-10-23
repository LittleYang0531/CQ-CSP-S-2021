#include<bits/stdc++.h>
using namespace std;
int n,a[1000010],b[1000010],r[200010],l[200010],sum1,sum2=1,ans;
char c[1000010],d[1000010];
bool u,o;
void find(int x){
	if(x==2*n){
		for(int i=0;i<n;i++){
			if(l[i]!=r[n-1-i]){
				u=false;
			}
		}
		if(u){
			ans+=1;
			if(ans==1){
				for(int i=0;i<2*n;i++){
					d[i]=c[i];
				}
			}
			else{
				for(int i=0;i<2*n;i++){
					if(c[i]=='L'&&d[i]=='R'){
						o=false;
						break;
					}
				}
			}
			if(!o){
				for(int i=0;i<2*n;i++){
					d[i]=c[i];
				}
			}
		}
		u=true;
		o=true;
		return;
	}
	if(x>=n){
		c[x]='L';
		r[x-n]=a[sum1];
		sum1++;
		find(x+1);
		c[x]='R';
		sum1--;
		r[x-n]=a[2*n-sum2];
		sum2++;
		find(x+1);
		sum2--;
	}
	else{
		c[x]='L';
		l[x]=a[sum1];
		sum1++;
		find(x+1);
		c[x]='R';
		sum1--;
		l[x]=a[2*n-sum2];
		sum2++;
		find(x+1);
		sum2--;
	}
	return;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int q=0;q<t;q++){
		scanf("%d",&n);
		for(int i=0;i<2*n;i++){
			scanf("%d",&a[i]);
		}
		find(0);
		if(ans){
			for(int i=0;i<2*n;i++){
				printf("%c",d[i]);
				d[i]='R';
			}
		}
		else printf("-1");
		cout<<endl;
		ans=0;
	}
	return 0;
}
