#include<bits/stdc++.h>
#define cin lin
#define cout lout
using namespace std;
int T,N,top=0,flag=0;
int a[50],b[50];
bool check() {
	for (int i=1;i<=N;i++)
	    if (b[i]!=b[2*N+1-i]) return 0;
	return 1;
}
int main() {
	ifstream cin("palin.in");
	ofstream cout("palin.out");
    cin>>T;
	while (T--) {
		flag=0;
	    cin>>N;
	    for (int i=1;i<=2*N;i++) cin>>a[i];
	    for (int i=0;i<(1<<(2*N));i++) {
	    	int l=1,r=2*N;
	    	top=0;
	    	for (int j=2*N;j>0;j--) {
	    		if ((i>>j)&1) b[++top]=a[r--];
	    		else b[++top]=a[l++];
			}
			if (check()) {
				flag=1;
				for (int j=2*N;j>0;j--) {
					if ((i>>j)&1) cout<<"R";
					else cout<<"L";
				}
				break;
			}
		}
		if (!flag) cout<<-1;
		cout<<endl;
	}	
	return 0;
}
