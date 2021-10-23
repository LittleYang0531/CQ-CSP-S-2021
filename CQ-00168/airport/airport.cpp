#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define int long long
#define inlint inline int
#define inloid inline void
#define inbool inline bool
#define MAXN 100005
using namespace std;

namespace _MAIN{
	int n, p1, p2;
	inlint read() {
		register int nega = 1, num = 0, c = getchar();
		for(;~c && !isdigit(c); c = getchar()) if(c == '-') nega = -1;
		for(;~c &&  isdigit(c); c = getchar()) num = num * 10 + c - '0';
		return nega * num;
	}
} using namespace _MAIN;

namespace _SOLV{
	struct _pla{
		int arr, lev, id;
	} inner[MAXN], outer[MAXN];
	namespace _SUBTASK1{
		//I don't wanna pianfen cuz I've passed all 3 samples
		//With a n*log^2n triple dividing
		//Hope that it'll work well.
	}
	namespace _SUBTASK2{
		int ia[MAXN], il[MAXN], oa[MAXN], ol[MAXN], ic[MAXN], oc[MAXN];
		inbool cmpia(int a, int b) {
			return inner[a].arr < inner[b].arr;
		}
		inbool cmpil(int a, int b) {
			return inner[a].lev < inner[b].lev;
		}
		inbool cmpoa(int a, int b) {
			return outer[a].arr < outer[b].arr;
		}
		inbool cmpol(int a, int b) {
			return outer[a].lev < outer[b].lev;
		}
		inloid initSeq(){
			for(int i = 1; i <= p1; i++) ia[i] = il[i] = i;
			for(int i = 1; i <= p2; i++) oa[i] = ol[i] = i;
			sort(ia + 1, ia + p1 + 1, cmpia), sort(il + 1, il + p1 + 1, cmpil);
			sort(oa + 1, oa + p2 + 1, cmpoa), sort(ol + 1, ol + p2 + 1, cmpol);
			return;
		}
		inlint calc(int inn) {
			int outt = n - inn;
			int insiz = 0, outsiz = 0;
			int inpnt = 0, outpnt = 0;
			int sum = 0, cua;
			memset(ic, 0, sizeof(ic)), memset(oc, 0, sizeof(oc));
			for(int i = 1; i <= p1; i++) {
				cua = ia[i];
				while(inner[cua].arr > inner[il[inpnt]].lev) {
					if(ic[il[inpnt]]) insiz--, ic[il[inpnt]] = 0;
					inpnt++;
				}
				if(insiz < inn) {
					ic[cua] = 1, insiz++, sum++;
				}
			}
			for(int i = 1; i <= p2; i++) {
				cua = oa[i];
				while(outer[cua].arr > outer[ol[outpnt]].lev) { // edit : more ol 
					if(oc[ol[outpnt]]) outsiz--, oc[ol[outpnt]] = 0;
					outpnt++;
				}
				if(outsiz < outt) {
					oc[cua] = 1, outsiz++, sum++;
				}
			}
			return sum;
		}
		int ans = 0;
		inloid tridiv() {
			int l = 0, r = n;
			while(r - l >= 3) {
				double mid = (l + r + 1);
				mid /= 2;
				int pl = calc(l), pr = calc(r);
				ans = max(ans, max(pl, pr));
				if(pl < pr) {
					l = mid - 0.4;
				} else {
					r = mid + 0.4;
				}
			}
			for(int i = l; i <= r; i++) {
				ans = max(ans, calc(i));
			}
			return;
		}
	}
} using namespace _SOLV;

signed main(void){
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	n = read(), p1 = read(), p2 = read();
	for(int i = 1; i <= p1; i++) inner[i].arr = read(), inner[i].lev = read(), inner[i].id = i;
	for(int i = 1; i <= p2; i++) outer[i].arr = read(), outer[i].lev = read(), outer[i].id = i;
	if(n >= p1 + p2) return cout << p1 + p2 << "\n", fclose(stdin), fclose(stdout), 0;
	_SUBTASK2::initSeq();
	_SUBTASK2::tridiv();
	cout << _SUBTASK2::ans << "\n";
	return fclose(stdin), fclose(stdout), 0;
}

