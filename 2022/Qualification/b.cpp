#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int z = 0; z < t; z++) {
    vector<vector<int>> m = vector<vector<int>>(3);
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 4; j++) {
        int n;
        cin >> n;
        m[i].push_back(n);
      }
    }

    vector<int> ret;
    int rem = 1000000;
    for (int i = 0; i < 4; i++) {
      int c = min(m[0][i], min(m[1][i], m[2][i]));
      c = min(rem, c);
      rem -= c;
      ret.push_back(c);
    }

    cout << "Case #" << z + 1 << ":";
    if (rem > 0) {
      cout << " IMPOSSIBLE";
    } else {
      for (int i = 0; i < 4; i++)
        cout << " " << ret[i];
    }
    cout << endl;
  }
}
