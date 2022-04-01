#include <iostream>
#include <ostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

// #define cin infile
// ifstream infile("in.txt", ios::in);


vector<vector<double>> matmul(const vector<vector<double>> & a, 
    const vector<vector<double>> & b) {
    int x = a.size(), y = b.size(), z = b[0].size();
    vector<vector<double>> result(x, vector<double>(z));
    for(int i = 0; i < x; ++i) {
        for(int j = 0; j < z; ++j) {
            double sum = 0;
            for(int k = 0; k < y; ++k) {
                sum += a[i][k] * b[k][j];
            }
            result[i][j] = sum;
        }
    }
    return result;
}

void matprint(const vector<vector<double>> & a) {
    for(int i = 0; i < a.size(); ++i) {
        for(int j = 0; j < a[0].size(); ++j) {
            if(a[i][j] < 1e-16 && a[i][j] > -1 * 1e-16) {
                cout << 0;
            }
            else {
                cout << a[i][j];
            }
            if(j < a[0].size() - 1) cout << ' ';
        }
        cout << endl;
    }
}

int main() {

    cout.precision(16);
    int t; cin >> t;

    for(int z = 0; z < t; ++z) {

        double a; cin >> a;
        vector<vector<double>> origin = {
            {0.5, 0.0, 0.0},
            {0.0, 0.5, 0.0},
            {0.0, 0.0, 0.5}
        };
        vector<vector<double>> rotation, result;
    
        // Rotate only once
        if(a < sqrt(2.0)) {
            double x = asin(a / sqrt(2.0)) - M_PI / 4.0;
            rotation = {
                {1.0, 0.0, 0.0},
                {0, cos(x), -1 * sin(x)},
                {0, sin(x), cos(x)}
            };
            result = matmul(origin, rotation);
        }

        // Rotate 45 x-axis, then rotate y axis
        else {
            // double x = M_PI / 4.0;
            double y = asin(a / sqrt(3.0)) - asin(sqrt(6.0) / 3);
            rotation = {
                {cos(y), 0, sin(y)},
                {sin(y) / sqrt(2), sqrt(2) / 2, -1 * cos(y) / sqrt(2)},
                {-1 * sin(y) / sqrt(2), sqrt(2) / 2, cos(y) / sqrt(2)}
            };
            result = matmul(origin, rotation);
        }
        cout << "Case #" << z + 1 << ':' << endl;
        matprint(result);
    }

    return 0;
}