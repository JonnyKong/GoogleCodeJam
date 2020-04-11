#include <iostream>
#include <vector>

using namespace std;


// works only for test set 1 (Visible Verdict)
vector<pair<int, int>> solve(int n) {
    vector<pair<int, int>> ret;
    if (n > 501)
        return ret;
    if (n == 501) {
        ret.push_back(make_pair(1, 1));
        ret.push_back(make_pair(2, 2));
        ret.push_back(make_pair(3, 2));
        for (int i = 3; i <= 499; ++i)
            ret.push_back(make_pair(i, i));
    } else {
        for (int i = 1; i <= n; ++i)
            ret.push_back(make_pair(i, i));
    }
    return ret;
}

int main() {
    int t; cin >> t;
    for (int z = 0; z < t; ++z) {
        int n; cin >> n;
        vector<pair<int, int>> ret = solve(n);
        printf("Case #%d:\n", z + 1);
        for (pair<int, int> p : ret)
            printf("%d %d\n", p.first, p.second);
    }
}