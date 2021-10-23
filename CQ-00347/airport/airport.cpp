#include <cstdio>
#include <algorithm>
using namespace std;
inline void read(int &t) {
	t = 0;
	int a = 1;
	char x = getchar();
	while (x < '0' || x > '9') {
		if (x == '-')
			a = -1;
		x = getchar();
	}
	while (x >= '0' && x <= '9') {
		t = t * 10 + x -'0';
		x = getchar();
	}
	t *= a;
}
const int MAXM = 1e5 + 10;
struct node {
	int begin, end;
} a[MAXM], b[MAXM];
struct node_ {
	int xx, yy;
} c[MAXM], d[MAXM];
inline bool cmp(node x, node y) {
	if (x.begin != y.begin)
		return x.begin < y.begin;
	return x.end < y.end;
}
inline int max(int a, int b) { return a > b? a : b;}
int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	int n, m1, m2, ans1, ans2, ans = 0;
	read(n);
	read(m1);
	read(m2);
	for (int i = 1; i <= m1; i++) {
		read(a[i].begin);
		read(a[i].end);
	}
	for (int i = 1; i <= m2; i++) {
		read(b[i].begin);
		read(b[i].end);
	}
	if (m1 < m2) {	
		for (int i = 0; i <= n; i++) {
			ans1 = ans2 = 0;
			for (int j = 1; j <= n + 5; j++)
				c[j].xx = c[j].yy = d[j].xx = d[j].yy = 0;
			for (int j = 1; j <= m1; j++) {
				for (int k = 1; k <= i; k++) {
					if (c[k].xx == 0 && c[k].yy == 0) {
						c[k].xx = a[j].begin, c[k].yy = a[j].end;
						ans1++;
						break;
					} else if (a[j].begin > c[k].yy) {
						ans1++;
						c[k].xx = a[j].begin, c[k].yy = a[j].end;
						break;
					}
				}
			}
			for (int j = 1; j <= m2; j++) {
				for (int k = 1; k <= n - i; k++) {
					if (d[k].xx == 0 && d[k].yy == 0) {
						d[k].xx = b[j].begin, d[k].yy = b[j].end;
						ans2++;
						break;
					} else if (b[j].begin > d[k].yy) {
						ans2++;
						d[k].xx = b[j].begin, d[k].yy = b[j].end;
						break;
					}
				}
			}
			ans = max(ans, ans1 + ans2);
			if (ans1 == m1)
				break;
		}
	} else {
		for (int i = 0; i <= n; i++) {
			ans1 = ans2 = 0;
			for (int j = 1; j <= n + 5; j++)
				c[j].xx = c[j].yy = d[j].xx = d[j].yy = 0;
			for (int j = 1; j <= m1; j++) {
				for (int k = 1; k <= n - i; k++) {
					if (c[k].xx == 0 && c[k].yy == 0) {
						c[k].xx = a[j].begin, c[k].yy = a[j].end;
						ans1++;
						break;
					} else if (a[j].begin > c[k].yy) {
						ans1++;
						c[k].xx = a[j].begin, c[k].yy = a[j].end;
						break;
					}
				}
			}
			for (int j = 1; j <= m2; j++) {
				for (int k = 1; k <= i; k++) {
					if (d[k].xx == 0 && d[k].yy == 0) {
						d[k].xx = b[j].begin, d[k].yy = b[j].end;
						ans2++;
						break;
					} else if (b[j].begin > d[k].yy) {
						ans2++;
						d[k].xx = b[j].begin, d[k].yy = b[j].end;
						break;
					}
				}
			}
			ans = max(ans, ans1 + ans2);
			if (ans2 == m2)
				break;
		}		
	}
	printf("%d", ans);
	return 0;
}
/* 
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16
*/
/* 
2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10
*/ 
/*
10 100 100
13 956
463 517
281 586
540 636
103 573
890 893
45 639
23 320
305 667
556 775
630 716
529 1000
173 741
174 276
6 51
724 763
291 663
334 401
250 511
373 710
467 696
265 449
317 432
92 955
14 707
411 860
603 643
251 874
190 705
9 310
285 539
408 615
861 951
319 413
368 714
264 688
271 670
43 353
792 872
240 770
2 348
325 687
253 750
464 509
543 704
963 989
4 998
148 198
698 899
532 929
50 149
41 168
255 802
246 768
252 656
237 363
146 151
70 119
364 477
578 936
771 809
551 952
434 903
535 609
607 948
446 828
311 313
758 937
62 122
11 614
909 947
898 918
201 862
178 421
176 269
38 420
513 754
67 175
254 360
740 912
134 225
141 922
87 111
553 751
234 331
329 452
783 810
55 162
136 322
762 977
387 856
314 815
653 935
442 817
36 212
362 949
30 637
737 832
53 999
159 531
431 796
215 385
63 718
395 647
289 298
488 545
7 438
596 876
611 628
1 699
61 278
286 367
196 220
25 645
772 914
323 328
537 984
465 501
445 672
19 709
581 953
126 550
88 326
969 994
184 245
247 346
284 660
339 407
338 584
599 703
199 224
959 974
365 826
496 519
34 980
73 835
624 712
171 209
419 466
40 934
189 476
559 646
577 804
816 821
376 435
392 572
793 852
306 495
457 593
206 340
127 512
161 260
273 855
669 897
95 892
824 849
72 524
48 86
576 585
5 927
487 561
676 819
107 734
143 781
642 674
28 129
514 695
137 294
94 978
390 957
147 261
482 652
12 403
571 941
399 961
681 789
83 181
230 853
564 764
542 732
394 654
283 827
106 790
486 993
56 480
105 931
910 991
379 469
479 689
104 414
612 800
798 850
785 799
185 337
15 973
791 807
610 728
396 923
277 884
69 79
*/
