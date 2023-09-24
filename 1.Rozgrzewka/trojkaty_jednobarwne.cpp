#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
int n, m;
int _numGray[MAXN + 5];

int numBlack(int x) {
    return n - 1 - _numGray[x]; 
}

int numGray(int x) {
    return _numGray[x];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie();

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        _numGray[a]++;
        _numGray[b]++;
    }

    int numOfDifferentColorTriangles = 0;

    for(int i = 1; i <= n; i++) {
        numOfDifferentColorTriangles  += numBlack(i) * numGray(i);
    }

    numOfDifferentColorTriangles  /= 2;
    
    int ans = n * (n - 1) * (n - 2) / 6 - numOfDifferentColorTriangles;    
    cout << ans << "\n";
    return 0;
}