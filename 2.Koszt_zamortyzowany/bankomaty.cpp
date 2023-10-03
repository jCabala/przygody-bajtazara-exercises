#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
const int MAXM = 10000;
int n;

vector<int> combinations[MAXN];
int lastIdxBefore[MAXM][11];
int lastIdxOf[11];

void clearLastIdxBefore() {
    for(int i = 0; i < MAXM; i++)
        for(int j = 0; j < 11; j++)
            lastIdxBefore[i][j] = -1;
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        int m;
        cin >> m;

        for(int j = 0; j < m; j++) {
            char c;
            cin >> c;
            combinations[i].push_back(int(c) - int('0'));
        }
    }

    clearLastIdxBefore();

    for(int combinationIdx = 0; combinationIdx < n; combinationIdx++) {
        vector<int> combination = combinations[combinationIdx];

        lastIdxBefore[1][combination[0]] = 0;
        for(int i = 1; i < combination.size() - 1; i++) {
            for(int j = 0; j <= 9; j++) {
                lastIdxBefore[i][j] = lastIdxBefore[i - 1][j];
            }
            lastIdxBefore[i][combination[i - 1]] = i - 1;

            lastIdxOf[combination[i]] = i;
        }


    }   
    
}