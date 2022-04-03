#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;

  for (int z = 0; z < t; z++) {
    int r, c;
    cin >> r >> c;

    cout << "Case #" << z + 1 << ":" << endl;
    for (int i = 0; i < 2 * r + 1; i++) {
      for (int j = 0; j < 2 * c + 1; j++) {
        if (i < 2 && j < 2)
          cout << '.';
        else if (i % 2 == 0 && j % 2 == 0)
          cout << '+';
        else if (i % 2 == 0)
          cout << '-';
        else if (j % 2 == 0)
          cout << '|';
        else
          cout << '.';
      }
      cout << endl;
    }
  }
}
