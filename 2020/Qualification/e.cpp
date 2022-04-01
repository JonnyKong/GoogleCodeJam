#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;


/////// 1. find a diagnoal such that the matrix can be filled

// decompose trace into the sum of dim integers, each within [1, n].
// make sure that it's not decomposed into (n-1)x + y
bool trace_dfs(int dim, vector<int> &cur, int trace_left) {
    if (cur.size() == dim && trace_left == 0) {
        // does not decomposed into (n-1)x + y. because we made sure this function produces
        // result that is increasing, so we can do the following
        if (cur[0] < cur[1] && cur[1] == cur.back())
            return false;
        else if (cur[0] == cur[cur.size() - 2] && cur[cur.size() - 2] < cur[cur.size() - 1])
            return false;
        return true;
    } 
    else if (trace_left < 0 || cur.size() > dim) {
        return false;
    }
    else {

        for (int i = cur.size() > 0 ? cur.back() : 1; i <= dim; i++) {
            cur.push_back(i);
            if (trace_dfs(dim, cur, trace_left - i) == true)
                return true;
            cur.pop_back();
        }
    }
    return false;
}

vector<int> get_possible_diagnal(int dim, int trace) {
    vector<int> ret;
    if (trace_dfs(dim, ret, trace))
        return ret;
    else
        return vector<int>();
}


/////// 2. fill matrix
bool is_valid(const vector<vector<int>> &m, int i, int j, int val) {
    for (int k = 0; k < m.size(); ++k) {
        if (m[i][k] == val)
            return false;
    }
    for (int k = 0; k < m.size(); ++k) {
        if (m[k][j] == val)
            return false;
    }
    return true;
}

void set_next_i_j(int dim, int i, int j, int *next_i, int *next_j) {
    if (j + 1 == dim) {
        *next_i = i + 1;
        *next_j = 0;
    } else {
        *next_i = i;
        *next_j = j + 1;
    }
}

bool dfs(vector<vector<int>> &m, int i, int j) {
    // empty is -1
    int next_i, next_j;
    set_next_i_j(m.size(), i, j, &next_i, &next_j);

    if (i + 1 == m.size() && j + 1   == m.size())
        return true;
    else if (m[i][j] != -1)     // already filled
        return dfs(m, next_i, next_j);
    for (int k = 1; k <= m.size(); ++k) {
        if (is_valid(m, i, j, k)) {
            m[i][j] = k;
            if (dfs(m, next_i, next_j) == true)
                return true;
            m[i][j] = -1;
        }
    }
    return false;
}

void fill_matrix(vector<vector<int>> &m) {
    if (dfs(m, 0, 0) == true) {
        return;
    } else {
        assert(false);
    }
}

// int main() {
//     vector<vector<int>> m = {
//         { 3, -1, -1, -1},
//         {-1,  3, -1, -1},
//         {-1, -1,  1, -1},
//         {-1, -1, -1,  1},
//     };
//     fill_matrix(m);
// }

// int main() {
//     vector<int> ret = get_possible_diagnal(3, 6);
//     for (int i = 0; i < ret.size(); ++i)
//         printf("%d, ", ret[i]);
//     printf("\n");
// }

int main() {
    int t;
    cin >> t;
    for (int z = 0; z < t; ++z) {
        int n, k; cin >> n >> k;
        vector<int> diag = get_possible_diagnal(n, k);
        
        if (diag.size() == 0) {
            printf("Case #%d: IMPOSSIBLE\n", z + 1);
            continue;
        }

        vector<vector<int>> m(n, vector<int>(n, -1));
        for (int i = 0; i < n; ++i)
            m[i][i] = diag[i];
        fill_matrix(m);
        printf("Case #%d: POSSIBLE\n", z + 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                printf("%d ", m[i][j]);
            printf("\n");
        }
    }
}