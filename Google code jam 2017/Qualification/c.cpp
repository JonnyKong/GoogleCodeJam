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
    ifstream infile("/Users/Jonnykong/Downloads/C-small-2-attempt0.in.txt", ios::in);
    ofstream outfile("/Users/Jonnykong/Downloads/results.txt", ios::out);
    
    int t; cin >> t;
    for(int z = 0; z < t; ++z) {
        long long n, k;
        cin >> n >> k;
        
        long long currentCounted = 1;
        long long base = (n - 1) / 2;
        
        long long l, r;
        
        if(k > 1) {
            long long numSpecial;
            if(n % 2 == 0) numSpecial = 1;
            else numSpecial = 0;
            
            long long currentLevelNum = 2;
            while(currentCounted + currentLevelNum < k) {
                currentCounted += currentLevelNum;
                currentLevelNum <<= 1;
                if(base % 2 == 1) {
                    numSpecial = numSpecial;
                }
                else {
                    numSpecial = numSpecial + (currentLevelNum >> 1);
                }
                base = (base - 1) / 2;
            }
            
            long long interval;
            if(numSpecial >= (k - currentCounted)) {
                interval = base + 1;
            }
            else {
                interval = base;
            }
            
            if(interval % 2 == 1) {
                l = (interval - 1) / 2;
                r = (interval - 1) / 2;
            }
            else {
                l = (interval - 1) / 2;
                r = (interval - 1) / 2 + 1;
            }
        }
        else {
            if(n % 2 == 1) {
                l = (n - 1) / 2;
                r = (n - 1) / 2;
            }
            else {
                l = (n - 1) / 2;
                r = (n - 1) / 2 + 1;
            }
        }
        
        cout << "Case #" << z + 1 << ": " << r << ' ' << l << endl;
    }
    return 0;
}