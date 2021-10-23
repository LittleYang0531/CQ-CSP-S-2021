#include<cstdio>
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	srand(time(NULL));
	printf("%d",rand()%(int)(1e9+7));
	return 0;
}
