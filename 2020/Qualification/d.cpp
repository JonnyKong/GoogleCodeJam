#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <unistd.h>

using namespace std;

int make_query(int index) {
    cout << index << endl;
    fflush(stdout);
    int ret; cin >> ret;
    return ret;
}

int get_next_unknown_idx(const vector<int> &arr) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == -1)
            return i;
    }
    return arr.size();  // everything known
}

int get_next_known_idx(const vector<int> &arr, int starts_from) {
    for (int i = starts_from; i < arr.size(); ++i) {
        if (arr[i] != -1)
            return i;
    }
    return arr.size();  // everything unknown, shouldn't reach here
}

void flip(vector<int> &arr) {
    for (int i = 0; i < arr.size(); ++i)
        arr[i] ^= 1;
}

void reverse(vector<int> &arr) {
    reverse(arr.begin(), arr.end());
}

// figure out what changed. hopefully this can be done in <10 times
// 0: flipped
// 1: reversed
// 2: flipped + reversed
// 3: nothing
int detect_change(const vector<int> &arr, int *query_cnt) {
    int opt1 = 1;
    int opt2 = 1;
    int opt3 = 1;
    int opt4 = 1;

    int cnt = 0;
    int known_idx = 0;
    while (opt1 + opt2 + opt3 + opt4 > 1) {
        // // give up if exceeds 10 times
        // cnt += 2;
        // if (cnt > 10)
        //     assert(false);

        known_idx = get_next_known_idx(arr, known_idx + 1);
        int q1 = make_query(known_idx + 1);
        int q2 = make_query(arr.size() - known_idx + 1);
        *query_cnt += 2;
        
        if (q1 == arr[known_idx] && q2 == arr[known_idx]) {
            opt1 = 0; opt3 = 0;
        } else if (q1 == arr[known_idx] && q2 != arr[known_idx]) {
            opt1 = 0; opt2 = 0;
        } else if (q1 != arr[known_idx] && q2 == arr[known_idx]) {
            opt3 = 0; opt4 = 0;
        } else {
            opt2 = 0; opt4 = 0;
        }
    }
    if (opt1 == 1)
        return 1;
    else if (opt2 == 1)
        return 2;
    else if (opt3 == 1)
        return 3;
    else
        return 4;
}

vector<int> solve(int b) {
    vector<int> ret(b, -1);
    int query_cnt = 0;
    while (query_cnt < 150) {
        if (get_next_unknown_idx(ret) == ret.size())
            return ret;
        if (query_cnt > 0 && query_cnt % 10 == 0) {
            // figure out what changed
            int change = detect_change(ret, &query_cnt);
            if (change == 1) {
                flip(ret);
            } else if (change == 2) {
                reverse(ret);
            } else if (change == 3) {
                flip(ret); reverse(ret);
            }
        }
        
        // regular query
        int query_idx = get_next_unknown_idx(ret);
        ret[query_idx] = make_query(query_idx + 1);
    }
    return ret;
}

int main() {
    int t, b; cin >> t >> b;
    for (int z = 0; z < t; ++z) {
        
        vector<int> ret = solve(b);
        
        // print result
        for (int i = 0; i < b; ++i) {
            if (ret[i] == 0)
                printf("0");
            else if (ret[i] == 1)
                printf("1");
            else
                assert(false);
        }
        printf("\n");
        fflush(stdout);
        string r; cin >> r;
        if (r == "N")
            break;
    }
}