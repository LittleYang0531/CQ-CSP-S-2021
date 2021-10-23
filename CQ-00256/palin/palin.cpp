#include<bits/stdc++.h>
using namespace std;

int a[1000000];
int ans[1000000];
bool f[1000000];
int pre[1000005],nxt[1000000];

void File(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
}

int main(){
	File();
//	freopen("palin2.in","r",stdin);
	int T,n;cin>>T;
	while(T--){
		scanf("%d",&n);
		n<<=1;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		
		for(int i=1;i<=n;i++) f[i]=0;
		for(int i=1;i<=n;i++) pre[i]=i-1,nxt[i]=i+1;
		pre[1]=n,nxt[n]=1;
		int s=1,t;
		for(int i=2;i<=n;i++) if(a[i]==a[1]){ t=i;break; }
		int Step=(n>>1);
		ans[1]=s,ans[n]=t;f[a[s]]=1;
//		for(int i=1;i<=n;i++) printf("%d ",ans[i]);
		for(int i=2;i<=Step;i++){
//			printf("%d %d   %d:%d %d %d:%d %d\n",i,n-i+1,s,pre[s],nxt[s],t,pre[t],nxt[t]);
			if(a[nxt[s]]==a[pre[t]]&&!f[a[nxt[s]]]&&nxt[s]!=pre[t]){
				ans[i]=nxt[s],ans[n-i+1]=pre[t];f[a[nxt[s]]]=1;
				nxt[s]=nxt[nxt[s]],pre[t]=pre[pre[t]];
			}
			else if(a[nxt[s]]==a[nxt[t]]&&!f[a[nxt[s]]]&&nxt[s]!=nxt[t]){
				ans[i]=nxt[s],ans[n-i+1]=nxt[t];f[a[nxt[s]]]=1;
				nxt[s]=nxt[nxt[s]],nxt[t]=nxt[nxt[t]];
			}
			else if(a[pre[s]]==a[pre[t]]&&!f[a[pre[s]]]&&pre[s]!=pre[t]){
				ans[i]=pre[s],ans[n-i+1]=pre[t];f[a[pre[s]]]=1;
				pre[s]=pre[pre[s]],pre[t]=pre[pre[t]];
			}
			else if(a[pre[s]]==a[nxt[t]]&&!f[a[pre[s]]]&&pre[s]!=nxt[t]){
				ans[i]=pre[s],ans[n-i+1]=nxt[t];f[a[pre[s]]]=1;
				pre[s]=pre[pre[s]],nxt[t]=nxt[nxt[t]];
			}
			else goto Fuck;	
			
		}
//		for(int i=1;i<=n;i++) printf("%d ",ans[i]);
        s=1,t=n;
		for(int i=1;i<=n;i++){
			if(ans[i]==s) printf("L"),s++;
			else printf("R"),t--;
		}
		printf("\n");
//		printf("OP:1\n");
		continue;
		Fuck:;
		
		for(int i=1;i<=n;i++) f[i]=0;
		for(int i=1;i<=n;i++) pre[i]=i-1,nxt[i]=i+1;
		pre[1]=n,nxt[n]=1;
		s=n;
		for(int i=1;i<n;i++) if(a[i]==a[n]){ t=i;break; }
		Step=(n>>1);
		ans[1]=s,ans[n]=t;f[a[s]]=1;
		for(int i=2;i<=Step;i++){
//			printf("%d:%d %d %d:%d %d\n",s,pre[s],nxt[s],t,pre[t],nxt[t]);
			if(a[nxt[s]]==a[pre[t]]&&!f[a[nxt[s]]]&&nxt[s]!=pre[t]){
				ans[i]=nxt[s],ans[n-i+1]=pre[t];f[a[nxt[s]]]=1;
				nxt[s]=nxt[nxt[s]],pre[t]=pre[pre[t]];
			}
			else if(a[nxt[s]]==a[nxt[t]]&&!f[a[nxt[s]]]&&nxt[s]!=nxt[t]){
				ans[i]=nxt[s],ans[n-i+1]=nxt[t];f[a[nxt[s]]]=1;
				nxt[s]=nxt[nxt[s]],nxt[t]=nxt[nxt[t]];
			}
			else if(a[pre[s]]==a[pre[t]]&&!f[a[pre[s]]]&&pre[s]!=pre[t]){
				ans[i]=pre[s],ans[n-i+1]=pre[t];f[a[pre[s]]]=1;
				pre[s]=pre[pre[s]],pre[t]=pre[pre[t]];
			}
			else if(a[pre[s]]==a[nxt[t]]&&!f[a[pre[s]]]&&pre[s]!=nxt[t]){
				ans[i]=pre[s],ans[n-i+1]=nxt[t];f[a[pre[s]]]=1;
				pre[s]=pre[pre[s]],nxt[t]=nxt[nxt[t]];
			}
			else goto CCF;	
			
		}
//		for(int i=1;i<=n;i++) printf("%d ",a[ans[i]]);
        s=1,t=n;
		for(int i=1;i<=n;i++){
			if(ans[i]==s) printf("L"),s++;
			else printf("R"),t--;
		}
		printf("\n");
		continue;
		CCF:;
				
		printf("-1\n");
	}
	return 0;
}
/*
1
20
3 5 13 2 19 9 20 6 11 4 10 8 7 17 15 1 18 14 16 18 15 17 7 12 8 10 4 11 6 20 9 19 2 13 3 5 1 14 16 12


 
*/
