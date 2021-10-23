#include <bits/stdc++.h>
using namespace std;
int T,n[100010],qq,ss=1;
vector<int> a[2002];
namespace s1{
	void out(){
		for(int ca=1;ca<=T;ca++){
			int m=1<<(n[ca]*2),b1[50],b2[22],e[50];
			string anss="";
			for(int i=0;i<n[ca]*2;i++) e[i]=a[ca][i],anss+='S';
			for(int i=0;i<m;i++){
				int ml=0,mr=0,mk=0;
				string s="";
				for(int j=0;j<2*n[ca];j++){
					if(i&(1<<j)){
						s+='R';
						b1[mr]=e[n[ca]+n[ca]-mk-1];
						mr++;mk++;
					}else{
						s+='L';
						b1[mr]=e[ml];
						mr++;ml++;
					}
				}
				int fl=1;
				for(int i=0,j=mr-1;i<=j;i++,j--){
					if(b1[i]!=b1[j]){
						fl=0;
						break;
					}
				}
				if(fl) anss=min(anss,s);
			}
			if(anss[0]=='S') anss="-1";
			cout << anss << endl;
		}
		return;
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%d",&n[i]);
		for(int j=1;j<=2*n[i];j++){
			scanf("%d",&qq);
			a[i].push_back(qq);
		}
		ss&=(n[i]<=10);
	}
	if(T<=10&&ss) s1::out();
	else if(T==1) cout << "-1";
	else{
		for(int i=1;i<=T;i++){
			while(n[i]--) putchar('L'),putchar('L');
			cout << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
