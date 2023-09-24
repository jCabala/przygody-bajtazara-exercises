#include <bits/stdc++.h>

using namespace std;
const int PRIMES_INTERVAL_BOUNDRY = 300000;
const int MAX_NUM = 2000000000 + 10;

bool visitedNumber[PRIMES_INTERVAL_BOUNDRY];
bool isPrime[PRIMES_INTERVAL_BOUNDRY];

vector<int> primes;
int n;

void generatePrimes() {
    for (int i = 2; i < PRIMES_INTERVAL_BOUNDRY; i++) {
        if (visitedNumber[i]) continue;
        primes.push_back(i);

        isPrime[i] = true;
        for (int j = i; j < PRIMES_INTERVAL_BOUNDRY; j += i)
            visitedNumber[j] = true;
    }
}

vector<int> _solve(int m) {
    vector<int> ans;

    if(m < PRIMES_INTERVAL_BOUNDRY && isPrime[m]) {
        ans.push_back(m);
        return ans;
    }

    int it = primes.size() - 1;
    int sum = 0;
    int minIncludedPrime = 0;

    while(m - sum >= minIncludedPrime) {
        if(m - sum - primes[it] <= 2) {
            it--;
            continue;
        } 

        if(m - sum - primes[it] < 10 && isPrime[m - sum - primes[it]]) {
            ans.push_back(primes[it]);
            ans.push_back(m - sum - primes[it]);
            return ans;
        } else if (m - sum - primes[it] < 10) {
            it--;
            continue;
        }

        // now we know that m - sum - primes[it] >= 10;
        minIncludedPrime = primes[it];
        sum += primes[it];
        ans.push_back(primes[it]);
        it--;
    }

    vector<int> restOfAns = _solve(m - sum);
    for(int u : restOfAns) {
        ans.push_back(u);
    }

    return ans;
}

void solve(int m) {
    vector<int> ans = _solve(m);
    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for(int u: ans) {
        cout << u << " ";
    }

    cout << "\n";
}

int main() {
    cin >> n;
    generatePrimes();

    for(int i = 0; i < n; i++) {
        int m;
        cin >> m;
        solve(m);
    }
}