#include <bits/stdc++.h>

using namespace std;

char str[1024];
int n, k, starctmp[1024] = {0};
bool statetmp[1024] = {0};

//void judge(int layer, int index, int starc)
//{
//	int curc = starc, i = index, result = 0;
//	while (curc <= k && i < n) {
//		switch (str[i]) {
//			case '*':
//				curc++;
//				break;
//			case '(':
//				result += judge(layer + 1, i + 1, 0);
//				break;
//			case ')':
//				return result;
//			case '?':
//				result += judge(layer, i + 1, curc);
//				result += judge(layer + 1, i + 1, 0);
//				break;
//		}
//		i++;
//	}
//}

//int judge(int layer, int index, int starc)
//{
//	int curc = starc, i = index, result = 0;
//	while (curc <= k && i < n) {
//		switch (str[i]) {
//			case '*':
//				curc++;
//				break;
//			case '(':
//				result += judge(layer + 1, i + 1, 0);
//				break;
//			case ')':
//				return result;
//			case '?':
//				result += judge(layer, i + 1, curc);
//				result += judge(layer + 1, i + 1, 0);
//				break;
//		}
//		i++;
//	}
//}

int judge(int layer, int index, char ichar, int layerstarc[], bool layerSAstate[], int lastlayer0)
{
	if (layer < 0)
		return 0;
//	if (index > n)
//		return 0;
//	if (index == n) {
//		if (layer == 0) {
//			if (layerSAstate[0] && )
//		} else {
//			return 0;
//		}
//	}
	if (index == n)
		return layer == 0;
	cout << "index " << index << " ichar " << ichar << endl;
	int summ = 0;
	switch (ichar) {
		case '*':
			if (layerstarc[layer] == k) {
				return 0;
//			} else if (layerSAstate[layer]) {
//				return 0;
			} else {
				layerstarc[layer]++;
				return judge(layer, index + 1, str[index + 1], layerstarc, layerSAstate, lastlayer0);
			}
		case '(':
			if (layerstarc[layer] > 0) {
				layerSAstate[layer] = true;
			}
			return judge(layer + 1, index + 1, str[index + 1], layerstarc, layerSAstate, lastlayer0);
		case ')':
			layerstarc[layer] = 0;
			layerSAstate[layer] = false;
			return judge(layer - 1, index + 1, str[index + 1], layerstarc, layerSAstate, lastlayer0);
		case '?':
			summ += judge(layer, index, '(', layerstarc, layerSAstate, lastlayer0);
			summ += judge(layer, index, ')', layerstarc, layerSAstate, lastlayer0);
			summ += judge(layer, index, '*', layerstarc, layerSAstate, lastlayer0);
			cout << "layer " << layer << " index " << index << " sum result " << summ << endl;
			return summ;
	}
}

int main()
{
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	cin >> n >> k;
	scanf("%s", str);
//	int layer = 0;
//	for (int i = 0; i < n; i++) {
////		if (str[0] != '(') {
////			cout << "0" << endl;
////			return 0;
////		}
//		judge(0, 0, str[0], starctmp, statetmp);
//	}
	if (str[0] == ')' || str[0] == '*')
		cout << "0" << endl;
	else
		cout << judge(0, 0, str[0], starctmp, statetmp, 0) << endl;
	return 0;
}

