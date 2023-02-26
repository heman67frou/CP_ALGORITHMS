#include <iostream>
#include <vector>
using namespace std;
std::vector<int> a(100005), seg(4*100005);

void build(int idx, int low, int high) {
	if (low == high) {
		seg[idx] = a[low];
		return;
	}
	int mid = (low+high)/2;

	build(2*idx+1, low, mid);
	build(2*idx+2, mid+1, high);
	seg[idx] = max(seg[2*idx+1], seg[2*idx+2]);
}
int query(int idx, int low, int high, int l, int r) {
	if (low >= l && high <= r) 
		return seg[idx];
	if (high < l || low > r) 
		return INT_MIN;

	int mid = (low+high)/2;
	int left = query(2*idx+1, low, mid, l, r);
	int right = query(2*idx+2, mid+1, high, l, r);
	return max(left, right);
}
int main() {
	// size of input array
	int n; cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	build(0, 0, n-1);

	int queries; cin >> queries;
	while (queries--) {
		int l, r; cin >> l >> r;
		cout << query(0, 0, n-1, l, r) << endl;
	}
	return 0;
}