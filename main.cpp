#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;

ll T, N;
vl constraint;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> T >> N;
  for (auto i = 0; i < N; ++i) {
    ll x = 0;
    ll Z;
    cin >> Z;
    for (auto j = 0; j < Z; ++j) {
      ll a;
      cin >> a;

      x |= (1 << (a - 1));
    }

    constraint.push_back(x);
  }

  ll mx = (1 << T) - 1;
  ll ans = 0;
  for (auto i = 0; i <= mx; ++i) {
    auto good = true;
    for (const auto& x : constraint) {
      if ((i & x) == x) {
        good = false;
        break;
      }
    }

    if (good) ++ans;
  }

  cout << ans;

  return 0;
}