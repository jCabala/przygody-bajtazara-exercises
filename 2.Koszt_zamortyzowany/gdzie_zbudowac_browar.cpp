#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10005;
int n;
int dist[MAXN], amount[MAXN];

int main() {
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> amount[i] >> dist[i];

    return 0;
}