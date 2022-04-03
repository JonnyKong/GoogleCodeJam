#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int z = 0; z < t; z++) {
    int n;
    cin >> n;

    vector<int> dices;
    for (int i = 0; i < n; i++) {
      int m;
      cin >> m;
      dices.push_back(m);
    }
    sort(dices.begin(), dices.end());

    // First row: this dice not used
    // Second row: this dice used or not used
    vector<vector<int>> dp(2, vector<int>(n, 0));
    dp[0][0] = 0;
    dp[1][0] = 1;

    for (int i = 1; i < n; i++) {
      dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]);
      dp[1][i] = min(dices[i], dp[0][i] + 1);
    }
    /* for (int i = 0; i < 2; i++) { */
    /*   for (int j = 0; j < n; j++) { */
    /*     cout << dp[i][j] << ", "; */
    /*   } */
    /*   cout << endl; */
    /* } */

    int ret = dp[1][n - 1];
    cout << "Case #" << z + 1 << ": " << ret << endl;
  }
}
