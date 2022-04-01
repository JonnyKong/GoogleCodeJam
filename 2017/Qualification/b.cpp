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
ifstream infile("/Users/Jonnykong/Downloads/B-large.in.txt", ios::in);
ofstream outfile("/Users/Jonnykong/Downloads/results.txt", ios::out);

int main() {
    int t; cin >> t;
    for(int z = 0; z < t; ++z) {
        string s; cin >> s;
        int i;
        while(1) {
            for(i = s.length() - 1; i > 0; --i) {
                if(s[i] < s[i - 1]) {
                    break;
                }
            }
            if(i == 0) break;   // end
            else {
                --s[i - 1];
                for(int j = i; j < s.length(); ++j) s[j] = '9';
            }
        }
        cout << "Case #" << z + 1 << ": ";
        if(s.length() == 1) {
            cout << s << endl;
        }
        else {
            i = 0;
            while(s[i] == '0') ++i;
            for(; i < s.length(); ++i) cout << s[i];
            cout << endl;
        }
    }
    return 0;
}
