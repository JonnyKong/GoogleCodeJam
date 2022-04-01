#include <iostream>
#include <ostream>
#include <vector>
#include <set>
#include <string>
#include <fstream>
//#include <algorithm>

using namespace std;

#define cin infile
#define cout outfile

int main() {
    ifstream infile("/Users/Jonnykong/Downloads/A-large-practice.in.txt", ios::in);
    ofstream outfile("/Users/Jonnykong/Downloads/results_2.txt", ios::out);
    
    int t;
    cin >> t;
    for(int z = 0; z < t; ++z) {
        int smax;
        cin >> smax;
        string str;
        cin >> str;
        vector<int> num(smax + 1);
        vector<int> accuTar(smax + 1);
        vector<int> actual(smax + 1, 0);
        int result = 0;
        for(int i = 0; i < smax + 1; ++i) {
            num[i] = str[i] - 0x30;
        }
        for(int i = 0; i < smax + 1; ++i) {
            accuTar[i] = i + 1;
        }
        actual[0] = num[0];
        if(actual[0] < accuTar[0]) {
            result += 1;
            actual[0] = 1;
        }
        for(int i = 1; i < smax + 1; ++i) {
            actual[i] = actual[i - 1] + num[i];
            if(actual[i] < accuTar[i]) {
                result += accuTar[i] - actual[i];
                actual[i] = accuTar[i];
            }
        }
        cout << "Case #" << z + 1 << ": " << result << endl;
    }
    return 0;
}
