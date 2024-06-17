#include <iostream>
using namespace std;

int findSqrt(int n) {
  int target = n;
  int s = 0;
  int e = n;
  int mid = s + (e - s) / 2;
  int ans = -1;

  while (s <= e) {
    if (mid * mid == target)
      return mid;

    if (mid * mid > target) {
      e = mid - 1;
    } else {
      ans = mid;
      s = mid + 1;
    }
    mid = s + (e - s) / 2;
  }
  return ans;
}

int main() {
  int n;
  cout << "Enter the number " << endl;
  cin >> n;

  // int ans=findSqrt(n);
  double ans = findSqrt(n);
  cout << "ans is " << ans << endl;

  int precision;
  cout << "Enter the number of floating digits in precision " << endl;

  cin >> precision;

  double step = 0.1;
  for (int i = 0; i < precision; i++) {
    for (double j = ans; j * j <= n; j = j + step) {
      ans = j;
    }
    step = step / 10;
  }
  cout << "Final ans is: " << ans << endl;
  return 0;
}