#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class SegmentTree {
public:
  vector<long long> arr, ST;

  SegmentTree(int n) {
    this->arr.resize(n);
    this->ST.resize(4 * n);
  }

  void build(int node, int l, int r) {
    if (l == r) {
      this->ST[node] = arr[l];
      return;
    }
    int mid = (l + r) / 2;

    build(2 * node + 1, l, mid);
    build(2 * node + 2, mid + 1, r);
    this->ST[node] = min(this->ST[2 * node + 1], this->ST[2 * node + 2]);
  }

  void update(int node, int pos, int val, int l, int r) {
    if (l == r) {
      this->arr[pos] = val;
      this->ST[node] = val;
      return;
    }
    int mid = (l + r) / 2;
    if (l <= pos && pos <= mid) {
      update(2 * node + 1, pos, val, l, mid);
    } else {
      update(2 * node + 2, pos, val, mid + 1, r);
    }
    this->ST[node] = min(this->ST[2 * node + 1], this->ST[2 * node + 2]);
  }

  long long query(int node, int a, int b, int l, int r) {
    if (l > b || r < a) {
      return INT_MAX;
    }
    if (l >= a && r <= b) {
      return this->ST[node];
    }
    int mid = (l + r) / 2;
    long long leftMin = query(2 * node + 1, a, b, l, mid);
    long long rightMin = query(2 * node + 2, a, b, mid + 1, r);

    return min(leftMin, rightMin);
  }
};

int main() {
  int n, q;
  cin >> n >> q;

  vector<long long> x(n);
  for (int i = 0; i < n; i++)
    cin >> x[i];

  SegmentTree st(n);

  st.arr = x;
  st.build(0, 0, n - 1);

  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << st.query(0, a - 1, b - 1, 0, n - 1) << '\n';
  }

  return 0;
}