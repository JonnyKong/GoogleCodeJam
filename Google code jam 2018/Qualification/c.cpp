#include <iostream>
#include <ostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <assert.h>

using namespace std;


int main() {

    int t; cin >> t;

    for(int z = 0; z < t; ++z) {

        int a; cin >> a;
        // cerr << a << endl;
        assert(a == 10 || a == 20 || a == 200);
        vector<int> src_row;
        vector<int> src_col;
        if(a == 10) {
            src_row = {1};
            src_col = {1, 3};
        } else if(a == 20) {
            // 4 * 5 grid
            src_row = {1, 2};
            src_col = {1, 3};
        } else {
            // 10 * 20 grid
            src_row = {1, 4, 5, 8};
            src_col = {1, 4, 7, 9, 12, 15, 18};
        }

        int x, y;   // Input
        int row = 0, col = 0;   // Current location index
        while(1) {
            // 1-indexed grid
            cout << (src_row[row] + 1) << ' '
                << (src_col[col] + 1) << endl << flush;
            if(++col == src_col.size()) {
                col = 0; ++row;
            }
            if(row == src_row.size()) {
                row = 0;
            }

            cin >> x >> y;
            if(x == -1 || y == -1) {
                break;
            } else if (x == 0 || y == 0) {
                break;
            }
        }

    }

    return 0;
}