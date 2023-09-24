#include <bits/stdc++.h>

using namespace std;

const int NUM_OF_PRIMES = 10;
const int HIGHEST_POWER_OF_2 = 31;

int n, primes[NUM_OF_PRIMES] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 19};
vector<pair<int, int>> antiprimeCanditates;

void _generateAntiprimeCandidates(int j, int max_pot, int cand, int num_of_divisors) {
    if(j >= NUM_OF_PRIMES) return;

    antiprimeCanditates.push_back(make_pair(cand, num_of_divisors));
    
    for(int i = 1; i <= max_pot; i++) {
        if(primes[j] > n/cand) return;

        cand *= primes[j];
        _generateAntiprimeCandidates(j + 1, i, cand, num_of_divisors * (i + 1));
    }
}

void generateAntiprimeCandidates() {
    _generateAntiprimeCandidates(0, HIGHEST_POWER_OF_2, 1, 1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> n;

    generateAntiprimeCandidates();
    sort(antiprimeCanditates.begin(), antiprimeCanditates.end());

    int biggestAntiprime = 0;
    int maxNumOfDivisors = 0;

    for(int i = 0; i < antiprimeCanditates.size(); i++) {
        if(antiprimeCanditates[i].second > maxNumOfDivisors) {
            maxNumOfDivisors = antiprimeCanditates[i].second;
            biggestAntiprime = antiprimeCanditates[i].first;
        }
    }

    cout << biggestAntiprime << "\n";
    return 0;
}