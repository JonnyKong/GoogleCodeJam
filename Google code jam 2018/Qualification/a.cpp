#include <iostream>
#include <ostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


int main() {

    int t; cin >> t;

    for(int z = 0; z < t; ++z) {

        int d; string p;
        cin >> d >> p;

        vector<int> damage(p.length(), 0);
        int current_damage = 1;
        int total_damage = 0;
        bool possible = true;
        int swap_cnt = 0;
        for(int i = 0; i < p.length(); ++i) {
            if(p[i] == 'C') current_damage <<= 1;
            else total_damage += current_damage;
            damage[i] = current_damage;
        }

        int pos = p.length() - 2;
        while(1) {
            
            // for(int i = 0; i < damage.size(); ++i) {
            //     cout << damage[i] << ' ';
            // }
            // cout << endl;

            if(total_damage <= d) break;
            else if(pos == -1) {
                possible = false;
                break;
            }

            int to_swap = -1;
            // Search back
            if(pos < p.length() - 2 && p[pos + 1] == 'C' && p[pos + 2] == 'S') {
                to_swap = ++pos;
                swap_cnt++;
            }
            // Search front
            else {
                while(pos >= 0) {
                    if(p[pos] == 'C' && p[pos + 1] == 'S') {
                        to_swap = pos;
                        swap_cnt++;
                        break;
                    }
                    pos--;
                }
            }
            if(to_swap >= 0) {
                p[to_swap] ^= p[to_swap + 1];
                p[to_swap + 1] ^= p[to_swap];
                p[to_swap] ^= p[to_swap + 1];
                damage[to_swap] >>= 1;
                total_damage -= damage[to_swap];
            }

        }

        cout << "Case #" << z + 1 << ": ";
        if(possible) {
            cout << swap_cnt << endl;
        }
        else {
            cout << "IMPOSSIBLE" << endl;
        }

    }

    return 0;
}