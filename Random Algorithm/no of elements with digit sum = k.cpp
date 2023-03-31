#include<bits/stdc++.h>
using namespace std;

vector<int> digitToVec(int n) {
	vector<int> a;
	while (n) {
		a.push_back(n % 10);
		n = n / 10;
	}
	reverse(a.begin(), a.end());
	return a;
}

int Y;
int dp[19][2][18 * 9 + 1];
int func(int ind, int flag, int sum, vector<int> a) {
	if (ind == a.size()) {
		if (sum == Y) return 1;
		else return 0;
	}
	if (dp[ind][flag][sum] != -1) return dp[ind][flag][sum];
	
	int limit = 9;
	if (flag == 0) limit = a[ind];

	int cnt = 0;
	for (int num = 0; num <= limit; num++) {
		if (flag == 0 && num == a[ind]) {
			cnt += func(ind + 1, 0, sum + num, a);
		}
		else {
			cnt += func(ind + 1, 1, sum + num, a);
		}
	}
	return dp[ind][flag][sum] = cnt;
}

int ans(int n) {
	vector<int> a = digitToVec(n);
	memset(dp, -1, sizeof dp);
	return func(0, 0, 0, a);
}

int main() {
	int l, r;
	cin >> l >> r >> Y;
	cout << ans(r) - ans(l - 1);
	return 0;
}
