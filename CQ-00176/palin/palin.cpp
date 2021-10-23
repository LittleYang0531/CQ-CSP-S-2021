// MDR±£””£¨M99±£””£¨Ô±µ∂±£””£¨ayame±£””£¨ø‰∏Á±£”” 
#include<bits/stdc++.h>
using namespace std;
int p1=1000000,p2=0;
char buf[1000005],wb[1000005];
int gc(){
	if(p1==1000000)fread(buf,1,1000000,stdin),p1=0;
	return buf[p1++];
}
//#define gc getchar
#define Loli true
long long getint(){
	long long ret=0;
	int c=gc();
	bool flg=0;
	while(c<48||c>57)flg=c=='-',c=gc();
	while(c>=48&&c<=57)ret=(ret<<3)+(ret<<1)+(c^48),c=gc();
	return flg?-ret:ret;
}
void pc(int x){
	if(p2==1000000)fwrite(wb,1,1000000,stdout),p2=0;
	wb[p2++]=x;
}
void wrt(long long x){
	if(x==0)pc(48);
	if(x<0)pc('-'),x=-x;
	int c[32]={0};
	while(x)c[++c[0]]=x%10,x/=10;
	while(c[0])pc(c[c[0]--]^48);
}
int n,a[2000005],pl1[2000005],pl2[2000005],id[2000005];
int l1,l2,r1,r2;
char ans[2000005];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int Ti=getint();
	while(Ti--){
		for(int i=1;i<=n;i++)pl1[i]=pl2[i]=a[i]=id[i]=0;
		l1=r1=l2=r2=0;
		n=getint();
		for(int i=1;i<=n<<1;i++){
			a[i]=getint();
			if(pl1[a[i]])pl2[a[i]]=i;
			else pl1[a[i]]=i;
		}
		
		int flg=0,L=1,R=n<<1;
		l1=2,r1=n<<1,l2=pl2[a[1]]-1,r2=pl2[a[1]]+1;
		id[1]=L++,id[pl2[a[1]]]=R--;
		int num=n-1;
		while(num){
//			cerr<<l1<<" "<<l2<<" "<<r2<<" "<<r1<<" "<<a[l1]<<" "<<a[l2]<<" "<<a[r2]<<" "<<a[r1]<<endl;
			if(l1<l2&&a[l1]==a[l2]){
				id[l1++]=L++,id[l2--]=R--,--num;
//				cerr<<num<<endl;
				continue;
			}
			if(l1<=l2&&r2<=r1&&a[l1]==a[r2]){
				id[l1++]=L++,id[r2++]=R--,--num;
//				cerr<<num<<endl;
				continue;
			}
			if(l1<=l2&&r2<=r1&&a[r1]==a[l2]){
				id[r1--]=L++,id[l2--]=R--,--num;
//				cerr<<num<<endl;
				continue;
			}
			if(r2<r1&&a[r1]==a[r2]){
				id[r1--]=L++,id[r2++]=R--,--num;
//				cerr<<num<<endl;
				continue;
			}
			flg=1;
			break;
		}
		if(!flg){
//			cerr<<l1<<" "<<l2<<" "<<r2<<" "<<r1<<" "<<a[l1]<<" "<<a[l2]<<" "<<a[r2]<<" "<<a[r1]<<endl;
//			id[l1]=L++,id[r1]=R--;
			L=1,R=n<<1;
			int tot=0;
//			for(int i=1;i<=n<<1;i++)cerr<<id[i]<<" ";
//			cerr<<endl;
//			for(int i=1;i<=n<<1;i++)cout<<a[id[i]]<<" ";
//			cout<<endl;
			while(L<=R){
				if(id[L]<=id[R]){
					ans[++tot]='L',L++;
				}else{
					ans[++tot]='R',R--;
				}
			}
			cout<<ans+1<<'\n';
			for(int i=1;i<=n<<1;i++)ans[i]=0;
			continue;
		}
		
		flg=0,L=1,R=n<<1;
		l1=1,r1=(n<<1)-1,l2=pl1[a[n<<1]]-1,r2=pl1[a[n<<1]]+1;
		id[n<<1]=L++,id[pl1[a[n<<1]]]=R--;
		num=n-1;
		while(num){
//			cerr<<l1<<" "<<l2<<" "<<r2<<" "<<r1<<" "<<a[l1]<<" "<<a[l2]<<" "<<a[r2]<<" "<<a[r1]<<endl;
			if(l1<l2&&a[l1]==a[l2]){
				id[l1++]=L++,id[l2--]=R--,--num;
//				cerr<<num<<endl;
				continue;
			}
			if(l1<=l2&&r2<=r1&&a[l1]==a[r2]){
				id[l1++]=L++,id[r2++]=R--,--num;
//				cerr<<num<<endl;
				continue;
			}
			if(l1<=l2&&r2<=r1&&a[r1]==a[l2]){
				id[r1--]=L++,id[l2--]=R--,--num;
//				cerr<<num<<endl;
				continue;
			}
			if(r2<r1&&a[r1]==a[r2]){
				id[r1--]=L++,id[r2++]=R--,--num;
//				cerr<<num<<endl;
				continue;
			}
			flg=1;
			break;
		}
		if(!flg){
//			cerr<<l1<<" "<<l2<<" "<<r2<<" "<<r1<<" "<<a[l1]<<" "<<a[l2]<<" "<<a[r2]<<" "<<a[r1]<<endl;
//			id[l1]=L++,id[r1]=R--;
			L=1,R=n<<1;
			int tot=0;
//			for(int i=1;i<=n<<1;i++)cerr<<id[i]<<" ";
//			cerr<<endl;
//			for(int i=1;i<=n<<1;i++)cout<<a[id[i]]<<" ";
//			cout<<endl;
			while(L<=R){
				if(id[L]<=id[R]){
					ans[++tot]='L',L++;
				}else{
					ans[++tot]='R',R--;
				}
			}
			cout<<ans+1<<'\n';
			for(int i=1;i<=n<<1;i++)ans[i]=0;
			continue;
		}
		puts("-1");
	}
	fwrite(wb,1,p2,stdout);
	return 0;
}
/*
1
20
17 3 16 1 9 12 19 6 8 2 20 14 18 10 5 11 15 7 13 4 4 13 7 15 11 5 10 18 17 14 20 2 8 6 19 12 9 1 16 3
*/
