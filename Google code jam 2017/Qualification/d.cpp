#include <iostream>
#include <ostream>
#include <vector>
#include <set>
#include <string>
#include <fstream>
#include <cmath>
#include <queue>
//#include <algorithm>

using namespace std;

#define cin infile
#define cout outfile

int main() {
    ifstream infile("/Users/Jonnykong/Downloads/D-small-attempt2.in.txt", ios::in);
    ofstream outfile("/Users/Jonnykong/Downloads/results.txt", ios::out);

    int t; cin >> t;
    for(int z = 0; z < t; ++z) {
        int n, m; cin >> n >> m;
        vector<vector<int>> occupied(n, vector<int>(n, 0));
        vector<vector<int>> mustPlus(n, vector<int>(n, 0));
        vector<vector<int>> mustX(n, vector<int>(n, 0));

        int totalChanged = 0;
        int totalPoint = 0;
        set<pair<int, int>> updatedPlus;
        set<pair<int, int>> updatedX;
        set<pair<int, int>> updatedO;

        // Initialize boards
        for(int i = 0; i < m; ++i) {
            char temp; cin >> temp;
            int p, q; cin >> p >> q;
            --p; --q;
            if(temp == '+') occupied[p][q] = 1;
            else if(temp == 'x') occupied[p][q] = 2;
            else if(temp == 'o') occupied[p][q] = 3;
        }

        // Initialize must-be boards
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(occupied[i][j] == 2 || occupied[i][j] == 3) {
                    for(int k = 0; k < n; ++k) mustPlus[i][k] = 1;
                    for(int k = 0; k < n; ++k) mustPlus[k][j] = 1;
                }
            }
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(occupied[i][j] == 1 || occupied[i][j] == 3) {
                    int k = 1;
                    while(i + k < n && j + k < n) {
                        mustX[i + k][j + k] = 1;
                        ++k;
                    }
                    k = 1;
                    while(i - k >= 0 && j - k >= 0) {
                        mustX[i - k][j - k] = 1;
                        ++k;
                    }
                    k = 1;
                    while(i - k >= 0 && j + k < n) {
                        mustX[i - k][j + k] = 1;
                        ++k;
                    }
                    k = 1;
                    while(i + k < n && i - k >= 0) {
                        mustX[i + k][j - k] = 1;
                        ++k;
                    }
                }
            }
        }

        // Add + or x
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if (occupied[i][j] == 0) {
                    if (mustPlus[i][j] && !mustX[i][j]) {    // Add +
                        occupied[i][j] = 1;
                        ++totalChanged;
                        updatedPlus.insert(make_pair(i, j));
                        int k = 1;
                        while (i + k < n && j + k < n) {
                            mustX[i + k][j + k] = 1;
                            ++k;
                        }
                        k = 1;
                        while (i - k >= 0 && j - k >= 0) {
                            mustX[i - k][j - k] = 1;
                            ++k;
                        }
                        k = 1;
                        while (i - k >= 0 && j + k < n) {
                            mustX[i - k][j + k] = 1;
                            ++k;
                        }
                        k = 1;
                        while (i + k < n && j - k >= 0) {
                            mustX[i + k][j - k] = 1;
                            ++k;
                        }
                    } else if (!mustPlus[i][j] && mustX[i][j]) { // Add x
                        occupied[i][j] = 2;
                        ++totalChanged;
                        updatedX.insert(make_pair(i, j));
                        for (int k = 0; k < n; ++k) mustPlus[i][k] = 1;
                        for (int k = 0; k < n; ++k) mustPlus[k][j] = 1;
                    }
//                    else if (!mustPlus[i][j] && !mustX[i][j]) {
//                        occupied[i][j] = 3;
//                        ++totalChanged;
//                        updatedO.insert(make_pair(i, j));
//                        int k = 1;
//                        while (i + k < n && j + k < n) {
//                            mustX[i + k][j + k] = 1;
//                            ++k;
//                        }
//                        k = 1;
//                        while (i - k >= 0 && j - k >= 0) {
//                            mustX[i - k][j - k] = 1;
//                            ++k;
//                        }
//                        k = 1;
//                        while (i - k >= 0 && j + k < n) {
//                            mustX[i - k][j + k] = 1;
//                            ++k;
//                        }
//                        k = 1;
//                        while (i + k < n && i - k >= 0) {
//                            mustX[i + k][j - k] = 1;
//                            ++k;
//                        }
//                        for(int k = 0; k < n; ++k) mustPlus[i][k] = 1;
//                        for(int k = 0; k < n; ++k) mustPlus[k][j] = 1;
//                    }
                }
            }
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if (!mustPlus[i][j] && !mustX[i][j]) {
                    occupied[i][j] = 3;
                    ++totalChanged;
                    updatedO.insert(make_pair(i, j));
                    int k = 1;
                    while (i + k < n && j + k < n) {
                        mustX[i + k][j + k] = 1;
                        ++k;
                    }
                    k = 1;
                    while (i - k >= 0 && j - k >= 0) {
                        mustX[i - k][j - k] = 1;
                        ++k;
                    }
                    k = 1;
                    while (i - k >= 0 && j + k < n) {
                        mustX[i - k][j + k] = 1;
                        ++k;
                    }
                    k = 1;
                    while (i + k < n && i - k >= 0) {
                        mustX[i + k][j - k] = 1;
                        ++k;
                    }
                    for(int k = 0; k < n; ++k) mustPlus[i][k] = 1;
                    for(int k = 0; k < n; ++k) mustPlus[k][j] = 1;
                }
            }
        }

        // Update to o
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(occupied[i][j] == 1 && !mustPlus[i][j]) {
                    occupied[i][j] = 3;
                    ++totalChanged;
                    updatedO.insert(make_pair(i, j));
                    auto p = updatedPlus.find(make_pair(i, j));
                    if(p != updatedPlus.end()) updatedPlus.erase(p);
                    auto q = updatedX.find(make_pair(i, j));
                    if(q != updatedX.end()) updatedX.erase(p);
                }
                else if(occupied[i][j] == 2 && !mustX[i][j]) {
                    occupied[i][j] = 3;
                    ++totalChanged;
                    updatedO.insert(make_pair(i, j));
                    auto p = updatedPlus.find(make_pair(i, j));
                    if(p != updatedPlus.end()) updatedPlus.erase(p);
                    auto q = updatedX.find(make_pair(i, j));
                    if(q != updatedX.end()) updatedX.erase(p);
                }
            }
        }

        // Total points
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(occupied[i][j] == 1 || occupied[i][j] == 2) ++totalPoint;
                else if(occupied[i][j] == 3) totalPoint += 2;
            }
        }

        cout << "Case #" << z + 1 << ": " << totalPoint << ' ' << totalChanged << endl;
        for(auto p : updatedPlus) {
            cout << '+' << ' ' << p.first + 1 << ' ' << p.second + 1 << endl;
        }
        for(auto p : updatedX) {
            cout << 'x' << ' ' << p.first + 1 << ' ' << p.second + 1 << endl;
        }
        for(auto p : updatedO) {
            cout << 'o' << ' ' << p.first + 1 << ' ' << p.second + 1 << endl;
        }
    }
    return 0;
}
























