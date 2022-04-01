#include <iostream>
#include <vector>

using namespace std;

string solve(const string &digits) {
    int depth = 0;
    string ret;
    for (int i = 0; i < digits.length(); ++i) {
        const int d = digits[i] - '0';
        while (d > depth) {
            ret.push_back('(');
            depth++;
        }
        while (d < depth) {
            ret.push_back(')');
            depth--;
        }
        ret.push_back(d + '0');
    }
    while (depth > 0) {
        ret.push_back(')');
        depth--;
    }
    return ret;
}

int main() {
    int t; cin >> t;
    for (int z = 0; z < t; ++z) {
        string digits; cin >> digits;
        string ret = solve(digits);
        printf("Case #%d: %s\n", z + 1, ret.c_str());
    }
}