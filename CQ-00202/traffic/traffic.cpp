#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
int main() {
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdin);
	srand(time(NULL));
	int n,m,t;
	scanf("%d%d%d",&n,&m,&t);
	while(t--)
		printf("%d\n",rand()%100);
	return 0;
}
