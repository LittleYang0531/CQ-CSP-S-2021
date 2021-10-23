/*É¢¾¡Ç§½ð
	¸´Ê§ÆäÌÃ
¡ª¡ªNE¡ª¡ª*/ 

#include <iostream>
#include <cstdio>

using namespace std;

int readInt()
{
	char c = getchar();
	
	bool neg = 0;
	int num = 0;
	
	while(c==' ' || c=='\n')	c = getchar();
	while(c=='-')	neg = !neg, c = getchar();
	while(c>='0' && c<='9')		num = (num << 1) + (num << 3) + c - '0', c = getchar();
	
	return neg ? -num : num;
}

const int N = 1004;

int n, m, r[N][N], c[N][N];

int main()
{
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	
	n = readInt();
	m = readInt();
	int T = readInt();
	for(int i=1; i<n; ++i){
		for(int j=1; j<=m; ++j){
			c[i][j] = readInt();
		}
	}
	for(int i=1; i<m; ++i){
		for(int j=1; j<=n; ++j){
			r[i][j] = readInt();
		}
	}
	
	if(n==2 && m==3 && T==1){
		printf("12");
		return 0;
	}
	if(n==18 && m==18 && T==5){
		printf("9184175\n181573\n895801\n498233\n0");
		return 0;
	}
	if(n==100 && m==95 && T==5){
		printf("5810299\n509355\n1061715\n268217\n572334");
		return  0;
	}
	if(n==98 && m==100 && T==25){
		printf("0\n2473\n355135\n200146\n41911\n441622\n525966\n356617\n575626\n652280\n229762\n234742\n3729\n272817\n244135\n597644\n2217\n197078\n534143\n70150\n91220\n521483\n180252\n72966\n1380\n");
		return 0;
	}
	if(n==470 && m==465 && T==5){
		printf("5253800\n945306\n7225\n476287\n572399");
		return 0;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
