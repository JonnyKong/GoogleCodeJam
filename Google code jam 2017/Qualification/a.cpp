//
//  main.cpp
//  Project 1
//
//  Created by Jonny Kong on 8/14/16.
//  Copyright © 2016 Jonny Kong. All rights reserved.
//

#include <iostream>
#include <ostream>
#include <vector>
#include <set>
#include <string>
#include <fstream>
#include <cmath>
//#include <algorithm>

using namespace std;

#define cin infile
#define cout outfile

int main() {
    ifstream infile("/Users/Jonnykong/Downloads/A-large.in.txt", ios::in);
    ofstream outfile("/Users/Jonnykong/Downloads/results.txt", ios::out);
    
    int t; cin >> t;
    for(int z = 0; z < t; ++z) {
        bool flag = 1;
        int count = 0;
        string str; cin >> str;
        int k; cin >> k;
        vector<bool> a(str.length());
        for(int i = 0; i < a.size(); ++i) {
            if(str[i] == '+') a[i] = 1;
            else a[i] = 0;
        }
        
        for(int i = 0; i < a.size() - k + 1; ++i) {
            if(a[i] == 1) continue;
            else{
                for(int j = 0; j < k; ++j) {
//                    a[i + j] ^= 1;
                    if(a[i + j] == 1) a[i + j] = 0;
                    else a[i + j] = 1;
                }
                ++count;
            }
        }
        
        for(int i = a.size() - k + 1; i < a.size(); ++i) {
            if(a[i] == 0) {
                flag = 0;
                break;
            }
        }
        
        cout << "Case #" << z + 1 << ": ";
        if(flag) {
            cout << count << endl;
        }
        else {
            cout << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}

















