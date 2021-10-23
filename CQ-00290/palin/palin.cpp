#include<bits/stdc++.h>
using namespace std;
int a[10000];
int t,n;
int ll,lr,rl,rr;
int s1[10000];
int s2[10000];
int ans[10000],ansl[10000];
bool b,d;
int g;
int top;
int ff;
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=2*n;i++){
			scanf("%d",&a[i]);
			ans[i]=0;
		}
		d=0;
		for(int k=1;k<2*n;k++){
			ll=1;lr=k;rl=k+1;rr=2*n;
			top=1;g=0;
			b=0;
			while(ll<=lr&&rl<=rr){
				if(a[ll]==a[lr]&&ll<lr){
					s1[top]=1;
					s2[top]=1;			
					ll++;
					lr--;
				}else if(a[ll]==a[rl]&&ll<lr&&rl<rr){
					s1[top]=1;
					s2[top]=0;		
					ll++;
					rl++;
				}else if(a[rr]==a[lr]&&ll<lr&&rl<rr){
					s1[top]=0;
					s2[top]=1;					
					rr--;
					lr--;
				}else if(a[rr]==a[rl]&&rr>rl){
					s1[top]=0;
					s2[top]=0;				
					rr--;
					rl++;
				}else{
					b=1;
					break;
				}
				g++;
			}
			ff=0;
			if(g==n-1){
				d=1;
				for(int i=1;i<=n;i++){
					ansl[i]=s1[i];
				}
				for(int i=1;i<=n;i++){
					ansl[i+n]=s2[n-i+1];
				}
				for(int i=1;i<=n;i++){
					if(ansl[i]!=ans[i]){
						if(ansl[i]<ans[i])ff=1;
						break;
					}
				}
				if(!ff){
					for(int i=1;i<=2*n;i++){
						ans[i]=ansl[i];
					}
				}
			}
		}
		if(!d)cout<<-1;
		else for(int i=1;i<=2*n;i++){
			printf("%c",(ans[i]?'L':'R'));
		}
		printf("\n");
	}
	return 0;
} 
