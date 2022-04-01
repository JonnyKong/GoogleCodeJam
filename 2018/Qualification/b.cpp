#include <iostream>
#include <ostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main() {

    int t; cin >> t;

    for(int z = 0; z < t; ++z) {

        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // Sort odd and even separately
        vector<int> even((n + 1) / 2);
        vector<int> odd(n / 2);
        for(int i = 0; i < (n + 1) / 2; ++i) even[i] = a[2 * i];
        for(int i = 0; i < n / 2; ++i) odd[i] = a[2 * i + 1];
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());

        // Merge result into a
        int is_even = 1;
        for(int i = 0; i < n; ++i) {
            if(is_even) {
                a[i] = even[i / 2];
                is_even = 0;
            } else {
                a[i] = odd[i / 2];
                is_even = 1;
            }
        }

        // Check result
        int pos = -1;
        for(int i = 0; i < n - 1; ++i) {
            if(a[i] > a[i + 1]) {
                pos = i;
                break;
            }
        }

        // Output
        cout << "Case #" << z + 1 << ": ";
        if(pos < 0) {
            cout << "OK" << endl;
        } else {
            cout << pos << endl;
        }

    }

    return 0;
}