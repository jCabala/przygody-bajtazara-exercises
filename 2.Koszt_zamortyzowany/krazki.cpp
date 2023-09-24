#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300000;
int n, m;
int sizes[MAXN], disks[MAXN]; 

int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> sizes[i];
        if(i != 0) {
            sizes[i] = min(sizes[i], sizes[i-1]);
        }
    }

    for(int i = 0; i < m; i++)
        cin >> disks[i];

    int idx = n - 1;
    for(int i = 0; i < m; i++) {
        while(idx >= 0 && sizes[idx] < disks[i]) idx--;
 
        if(idx < 0) {
            cout << "0\n";
            return 0;
        }

        idx--;
    }

    cout << idx + 2 << "\n"; 
}