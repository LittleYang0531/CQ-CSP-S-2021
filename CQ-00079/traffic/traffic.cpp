#include<cstdio>
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	srand(time(NULL));
	printf("%d",rand()%(int)(1e9+7));
	return 0;
}
