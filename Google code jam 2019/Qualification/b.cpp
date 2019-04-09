#include <iostream>
#include <ostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string getAlternatePath(const string &other) {
    string result;
    for (int i = 0; i < other.length(); ++i) {
        if (other[i] == 'E')
            result.push_back('S');
        else
            result.push_back('E');
    }
    return result;
}

int main() {
    int t; cin >> t;
    for(int z = 0; z < t; ++z) {
        int n; cin >> n;
        string p; cin >> p;
        string result = getAlternatePath(p);
        cout << "Case #" << z + 1 << ": " << result << std::endl;
    }
    return 0;
}