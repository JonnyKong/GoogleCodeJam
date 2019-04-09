#include <iostream>
#include <ostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> intToVector(int n) {
    vector<int> result;
    while(n) {
        result.push_back(n % 10);
        n /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

int vectorToInt(const vector<int> &vec) {
    int result = 0;
    for (int i = 0; i < vec.size(); ++i) {
        result *= 10;
        result += vec[i];
    }
    return result;
}

// Find a combination without digit 4
pair<int, int> findCombination(int n) {
    vector<int> n_vec = intToVector(n);
    vector<int> a(n_vec.size());
    vector<int> b(n_vec.size());
    for (int i = 0; i < n_vec.size(); ++i) {
        if (n_vec[i] == 4) {
            a[i] = 2;
            b[i] = 2;
        } else {
            a[i] = n_vec[i];
        }
    }
    return make_pair<int, int>(vectorToInt(a), vectorToInt(b));
}

int main() {
    int t; cin >> t;
    for(int z = 0; z < t; ++z) {
        int n;
        cin >> n;
        std::pair<int, int> p = findCombination(n);
        cout << "Case #" << z + 1 << ": " << p.first << " " << p.second << endl;
    }
    return 0;
}