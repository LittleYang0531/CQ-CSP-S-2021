#include<bits/stdc++.h>
using namespace std;
int n,t;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
  /* ________
  	|       |
	| ^  ^  |
	| .  .  |
	|       |
	| \  /  |
	|  \/   |
	|_______|
	*/
	scanf("%d%d",&n,&t);
	printf("%d",time(0)%(n*t));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
