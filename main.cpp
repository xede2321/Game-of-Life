#include <iostream>

const int n = 19, m = 20, N = n*m; bool a[N], b[N];

bool get(bool *a, int i, int j) { return a[(i + n) % n*n + (j + m) % m]; }

int neibs(bool *a, int i, int j) {
  int r = 0;
  for (int p = -1; p <= 1; p++) for (int q = -1; q <= 1; q++) r += get(a, i + p, j + q);
  return r - get(a, i, j);
}
void show(bool *a) {
  for (int k = 0; k<N; k++) std::cout << (a[k] ? '@' : '-') << ((k + 1) % n ? ' ' : '\n');
}

void go(bool *a, bool *b, int c) {
  for (int i = 0; i <= c; i++) {
    std::cout << "generation " << i << ":\n"; show(a); std::cout << '\n';
    for (int k = 0; k<N; k++) {
      int s = neibs(a, k / n, k%n);
      b[k] = !a[k] && s == 3 ? 1 : a[k] && (s<2 || s>3) ? 0 : a[k];
    }
    bool *t = a; a = b; b = t;
  }
}
int main() { for (int i = 6; i <= 13; i++) a[i*n + n / 2] = 1; go(a, b, 50); }