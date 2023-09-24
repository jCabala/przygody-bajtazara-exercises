#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

int n;
char operators[MAXN + 1];

int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> n;

    for(int i = 0; i < n - 1; i++) {
        cin >> operators[i];
    }

    operators[n - 1] = '-';

    for(int i = 0; i < n - 1; i++) {
        cout << "-";

        if(operators[i] == '-' && operators[i + 1] == '+') {
            cout << "(";
        }

        if(operators[i] == '+' && operators[i + 1] == '-') {
            cout << ")";
        }
    }
    cout << "\n";
}