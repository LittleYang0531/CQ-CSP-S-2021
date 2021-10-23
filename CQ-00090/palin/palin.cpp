#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define inf 0x7fffffff/2
using namespace std;
template <typename T> void read(T &x) {
	x=0;
	char c=getchar();
	for (; !isdigit(c); c=getchar());
	for (; isdigit(c); c=getchar()) x=x*10+c-'0';
}
int T,a[1000005],b[1000005];
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	read(T);
	for (; T; --T) {
		int n;
		read(n);
		for (int i=1; i<=2*n; i++) {
			read(a[i]);
		}
		int js=1;
		int l=1,r=n*2;
		bool bj=1;
		for (int i=1; i<=n; i++) {
			if (a[l]==a[r]) {
				cout<<"L";
				b[js]=a[l];
				a[l]=inf;
				l++,js++,bj=0;
				continue;
			}
			int sum=0,sum1=0;
			for (int j=l+1; j<=r; j++) {
				if (a[j]==a[l]) {
					sum=j-l;
					break;
				}
			}
			for (int j=r-1; j>=l; j--) {
				if (a[j]==a[r]) {
					sum1=r-j;
					break;
				}
			}
			if (sum>sum1) {
				cout<<"L";
				b[js]=a[l];
				a[l]=inf;
				l++,js++,bj=0;
			} else if (sum<sum1) {
				cout<<"R";
				b[js]=a[r];
				a[r]=inf;
				js++,r--,bj=1;
			} else if (sum==sum1) {
				if (bj==0) {
					cout<<"R";
					b[js]=a[r];
					a[r]=inf;
					js++,r--,bj=1;
				} else {
					cout<<"L";
					b[js]=a[l];
					a[l]=inf;
					l++,js++,bj=0;
				}
			}
		}
		int y=n;
		bool bj2=false;
		for (int j=n; j>=1; j--) {
			if (a[l]==b[j] || a[r]==b[j]) {
				if (a[l]==b[j]) {
					cout<<"L";
					b[js]=a[l];
					l++,js++;
				} else if (a[r]==b[j]) {
					cout<<"R";
					b[js]=a[r];
					r--,js++;
				}
				continue;
			}
			cout<<"-1";
			bj2=true;
			break;
		}
		puts("");
	}
	return 0;
}
