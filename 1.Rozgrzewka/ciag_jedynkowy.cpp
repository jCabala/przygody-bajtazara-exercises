#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int MAXN = 10000;
int n, S;
int sequence[MAXN];

ll getDelta(int i, int curSum, int num) {
    ll delta = abs(((ll) S * (ll) (i + 1)) - (ll) (curSum + num) * (ll) n);
    return delta;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(); 
    cin >> n >> S;

    int curSum = 0;
    int lastNum = 0;
    sequence[0] = 0;

    for(int i = 1; i < n; i++) {
        int possibleNum1 = lastNum + 1;
        int possibleNum2 = lastNum - 1;

        ll delta1 = getDelta(i, curSum, possibleNum1);
        ll delta2 = getDelta(i, curSum, possibleNum2);

        int nextNum;
        if (delta1 < delta2) {
            nextNum = possibleNum1;
        } else {
            nextNum = possibleNum2;
        }
            
        curSum += nextNum;
        lastNum = nextNum;
        sequence[i] = nextNum;
    }

    if(curSum == S) {
        for(int i = 0; i < n; i++) {
            cout << sequence[i] << " ";
        }

        cout << "\n";
    } else {
        cout << "NIE\n";
    }

    return 0;
}