#include<bits/stdc++.h>
#define van long long
using namespace std;

//bool ppppp;time_t st=clock();
ifstream ywhin("palin.in");
ofstream ywhout("palin.out");
const van MaxN=5e5+10;
char op[MaxN];bool fi=false;
van t,n,a[MaxN];
van l[MaxN];
//bool pppppp;

//void Output_Runner_Information() {
//	cout<<"Memory Usage: "<<(&pppppp-&ppppp)/1024.0/1024.0<<"MB"<<endl;
//	cout<<"Time Usage: "<<(clock()-st)/1000.0<<"s"<<endl;
//}
bool check() {
	van to=1,en=2*n;
	for (int i=1;i<=2*n;i++) {
		if (op[i]=='L') l[i]=a[to],to++;
		else l[i]=a[en],en--;
	}
	for (int i=1;i<=n;i++) {
		if (l[i]!=l[n*2-i+1]) return false;
	}
	return true;
}
void DFS(van now) {
	if (fi) return;
	if (now==2*n+1) {
		if (check()) {
			for (int i=1;i<=2*n;i++) ywhout<<op[i];
			ywhout<<endl;
			fi=1;
		}
		return;
	}
	op[now]='L';DFS(now+1);
	op[now]='R';DFS(now+1);
}

int main() {
	ywhin>>t;
	for (int tt=1;tt<=t;tt++) {
		ywhin>>n;fi=0;
		for (int i=1;i<=n*2;i++) ywhin>>a[i];
		DFS(1);if (!fi) ywhout<<-1<<endl;
	}
//	Output_Runner_Information();
	return 0;
}

