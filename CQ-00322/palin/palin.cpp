#include<bits/stdc++.h>
using namespace std;

const int N = 1000005;

int n;
int a[N] , q[N*2] , op[N] , op2[N] , pos[N] , ano[N] , tot = 0;
 
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	
	int t;
	scanf("%d",&t);
	
	for( ; t ; t--){
		tot = 0;
		scanf("%d",&n);
		
		for(int i=1;i<=2*n;i++)
			scanf("%d",&a[i]);
		
		for(int i=1;i<=2*n;i++){
			pos[i] = 0;
			op[i] = op2[i] = 0;
			ano[i] = 0;
		}
		
		for(int i=1;i<=2*n;i++){
			if( pos[ a[i] ] > 0 ){
				ano[i] = pos[ a[i] ];
				ano[ pos[ a[i] ] ] = i;
			}
			else pos[ a[i] ] = i;
		}
		
		int hd = 2 , tl = 2*n; 
		tot = 1; op[1] = 1; op[ ano[1] ] = 2*n;
		
		int fir = ano[1]-1 , sec = ano[1]+1;
		
		while(tot <= n && (hd <= fir || sec <= tl) ){
			if(a[hd] == a[ fir ] && hd <= fir && hd != fir){
				op[hd] = ++tot;
				op[fir] = 2*n - tot + 1;
				hd ++; fir --;
			}
			else if(a[hd] == a[sec] && hd <= fir && sec <= tl && hd != sec){
				op[hd] = ++tot;
				op[sec] = 2*n - tot + 1;
				hd ++; sec ++;
			}
			else if(a[tl] == a[fir] && hd <= fir && sec <= tl && tl != fir){
				op[tl] = ++tot;
				op[fir] = 2*n - tot + 1;
				tl --; fir --;
			}
			else if(a[tl] == a[sec] && sec <= tl && tl != sec){
				op[tl] = ++tot;
				op[sec] = 2*n - tot + 1;
				tl --; sec ++;
			}
			else break;
		}
		
		int hd2 = 1 , tl2 = 2*n-1; 
		int tot2 = 1; op2[2*n] = 1; op2[ ano[2*n] ] = 2*n;
		
		int fir2 = ano[2*n]-1 , sec2 = ano[2*n]+1;
		
		while(tot2 <= n && ( hd2 <= fir2 || sec2 <= tl2) ){
			if(a[hd2] == a[ fir2 ] && hd2 <= fir2 && hd2 != fir2){
				op2[hd2] = ++tot2;
				op2[fir2] = 2*n - tot2 + 1;
				hd2 ++; fir2 --;
			}
			else if(a[hd2] == a[sec2] && hd2 <= fir2 && sec2 <= tl2 && hd2 != sec2){
				op2[hd2] = ++tot2;
				op2[sec2] = 2*n - tot2 + 1;
				hd2 ++; sec2 ++;
			}
			else if(a[tl2] == a[fir2] && hd2 <= fir2 && sec2 <= tl2 && tl2 != fir2){
				op2[tl2] = ++tot2;
				op2[fir2] = 2*n - tot2 + 1;
				tl2 --; fir2 --;
			}
			else if(a[tl2] == a[sec2] && sec2 <= tl2 && tl2 != sec2){
				op2[tl2] = ++tot2;
				op2[sec2] = 2*n - tot2 + 1;
				tl2 --; sec2 ++;
			}
			else break;
		}
		
		
		if( tot < n && tot2 < n ) printf("-1\n");
		else{
			hd = 1 ; tl = 2*n;
			if(tot == n){
				while(hd <= tl){
					if(op[hd] <= op[tl]){
						printf("L");
						hd ++;
					}
					else {
						printf("R");
						tl --;
					}
				}
				printf("\n");
			}
			else {
				while(hd <= tl){
					if(op2[hd] <= op2[tl]){
						printf("L");
						hd ++;
					}
					else {
						printf("R");
						tl --;
					}
				}
				printf("\n");
			}
		}
	}
	
	return 0;
}
//1
//20
//5 13 1 3 2 16 7 19 6 18 10 4 4 10 20 18 6 19 7 8 2 14 1 11 17 9 13 5 15 3 16 12 20 12 8 14 15 11 17 9

