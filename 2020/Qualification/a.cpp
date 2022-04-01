#include <iostream>
#include <vector>

using namespace std;

int get_trace(const vector<vector<int>> & m) {
    int ret = 0;
    for (int i = 0; i < m.size(); ++i)
        ret += m[i][i];
    return ret;
}

vector<vector<int>> transpose(const vector<vector<int>> & a) {
    vector<vector<int>> ret(a.size(), vector<int>(a.size(), 0));
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a.size(); ++j) {
            ret[i][j] = a[j][i];
        }
    }
    return ret;
}

bool is_unique(const std::vector<int>& arr) {
    for (std::size_t i = 0; i < arr.size(); ++i) {
        for (std::size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[i] == arr[j])
                return true;
        }
    }
    return false;
}

int row_w_duplicate(const vector<vector<int>> & m) {
    int ret = 0;
    for (int i = 0; i < m.size(); ++i) {
        if (is_unique(m[i]))
            ret++;
    }
    return ret;
}

int main() {
    int t; cin >> t;
    for (int z = 0; z < t; ++z) {
        int n; cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> m[i][j];
            }
        }
        int trace = get_trace(m);
        int row_dup = row_w_duplicate(m);
        int col_dup = row_w_duplicate(transpose(m));
        printf("Case #%d: %d %d %d\n", z + 1, trace, row_dup, col_dup);
    }
}