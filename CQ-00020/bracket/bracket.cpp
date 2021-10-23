#include<iostream>
using namespace std;
int n,k,asw;
//int f[2][105][105][2];
//char a[501];
//bool cur;
string s;
void sou(int k,string a) {
	if(k==n) {
		int top=0,cnt=0;
		bool flag=0;
		if(a[0]!='('||a[n-1]!=')') return;
		for(int i=0; i<n; i++) {
			if(a[i]=='(') top++;
			else if(a[i]==')') {
				if(!top) return;
				top--;
			} else {
				if(flag) return;
				if(a[i-1]==')') flag=1;
				cnt++;
				if(cnt>k) return;
			}
		}
		if(top) return;
		asw++;
		if(asw>=1000000007) asw-=1000000007;
		return;
	}
	if(s[k]!='?') sou(k+1,a+s.substr(k,1));
	else {
		sou(k+1,a+"(");
		sou(k+1,a+")");
		sou(k+1,a+"*");
	}
}
int main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	cin>>s;
//	if(a[1]!='(') {
//		if(a[1]!='?') {
//			printf("0");
//			return 0;
//		} else a[1]='(';
//	}
//	if(a[n]!=')') {
//		if(a[n]!='?') {
//			printf("0");
//			return 0;
//		} else a[n]=')';
//	}
	sou(0,"");
//	f[0][1][1][0]=1;
//	for(int i=1; i<=n; i++) {
//		for(int j=0; j<=n; j++) for(int jj=0; jj<=k+1; jj++) f[!cur][j][jj][1]=f[!cur][j][jj][0]=0;
//		if(a[i]=='(') {
//			for(int j=0; j<n; j++) {
//				f[!cur][j+1][0][0]=f[cur][j][0][0];
//				f[!cur][j+1][0][1]=f[cur][j][0][1];
//			}
//		} else if(a[i]==')') {
//			for(int j=1; j<=n; j++) f[!cur][j-1][0][0]=f[cur][j][0][0]+f[cur][j][0][1];
//		} else if(a[i]=='*') {
//			for(int j=0; j<k; j++) for(int jj=1; jj<=n; jj++) {
//					f[!cur][jj][j+1][1]=f[cur][jj][j][1];
//					f[!cur][jj][j+1][0]=f[cur][jj][j][0];
//				}
//		} else {
//			for(int j=0; j<n; j++) f[!cur][j+1][0][1]=(f[cur][j][0][0]+f[cur][j][0][1])%1000000007;
//			for(int j=1; j<=n; j++) f[!cur][j-1][0][0]=(f[cur][j][0][0]+f[cur][j][0][1])%1000000007;
//			for(int j=0; j<k; j++) for(int jj=1; jj<=n; jj++) {
//					f[!cur][jj][j+1][1]=f[cur][jj][j][1];
//					f[!cur][jj][j+1][0]=f[cur][jj][j][0];
//				}
//		}
//		cur=!cur;
//	}
//	printf("%d",f[cur][1][1][0]);
	printf("%d",asw);
}
