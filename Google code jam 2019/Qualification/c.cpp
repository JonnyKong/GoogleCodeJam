#include <iostream>
#include <ostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>

using namespace std;

// From elsewhere
long long gcd(long long a, long long b) {
    // Everything divides 0
    if (a == 0)
       return b;
    if (b == 0)
       return a;
    // base case
    if (a == b)
        return a;
    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

// Get the list of primes in sorted order
vector<long long> getPrimes(int n, const vector<long long> &cipher) {
    // Find two different numbers in cipher for GCD
    int index = 1;
    long long a = cipher[0], b = cipher[index++];
    while (a == b && index < cipher.size())
        b = cipher[index++];
    long long prime_first = gcd(a, b);
    vector<long long> primes;
    primes.push_back(prime_first);

    // Get remaining primes
    while (primes.size() < 26) {
        vector<long long> tmp = primes;
        for (auto it = tmp.begin(); it != tmp.end(); ++it) {
            for (int i = 0; i < cipher.size(); ++i) {
                if (cipher[i] % (*it) == 0) {
                    int prime = cipher[i] / (*it);
                    auto p = find(primes.begin(), primes.end(), prime);
                    if (prime <= n && p == primes.end()) {
                        primes.push_back(prime);
                    }
                }
            }
        }
    }

    sort(primes.begin(), primes.end());
    return primes;
}

map<long long, pair<char, char>> getMapping(const vector<long long> &primes) {
    // assert(primes.size() == 26);
    map<long long, pair<char, char>> mapping;
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            long long prod = primes[i] * primes[j];
            mapping[prod] = make_pair('A' + i, 'A' + j);
        }
    }
    return mapping;
}


// Param n is the upper bound of all primes
string decipher(int n, const vector<long long> &cipher) {
    vector<long long> primes = getPrimes(n, cipher);
    map<long long, pair<char, char>> mapping = getMapping(primes);

    vector<pair<char, char>> char_pairs;
    for (int i = 0; i < cipher.size(); ++i) {
        auto char_pair = mapping[cipher[i]];
        char_pairs.push_back(char_pair);
    }

    // Choose one char from each pair to get plaintext
    string plaintext;
    if (char_pairs[0].first == char_pairs[1].first || char_pairs[0].first == char_pairs[1].second)
        plaintext.push_back(char_pairs[0].second);
    else
        plaintext.push_back(char_pairs[0].first);
    for (int i = 0; i < char_pairs.size(); ++i) {
        char c = plaintext.back();
        if (c == char_pairs[i].first)
            plaintext.push_back(char_pairs[i].second);
        else
            plaintext.push_back(char_pairs[i].first);
    }
    return plaintext;
}


int main() {
    int t; cin >> t;
    for(int z = 0; z < t; ++z) {
        int n, l;
        cin >> n >> l;
        vector<long long> ciphertext(l);
        for (int i = 0; i < l; ++i)
            cin >> ciphertext[i];

        string plaintext = decipher(n, ciphertext);
        cout << "Case #" << z + 1 << ": " << plaintext << endl;
    }
    return 0;
}