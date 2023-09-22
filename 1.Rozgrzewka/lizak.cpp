#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;
int n, k;
int loli[MAXN];
pair<int, int> valueToSegment[2 * MAXN + 5];

void writeAllSegments(int l, int r, int initialVal) {
    int curVal = initialVal;

    while(curVal > 0) {
        valueToSegment[curVal] = make_pair(l, r);
        
        if (loli[l] == 1 && loli[r] == 1) {
            l++;
            r--;
        } else if (loli[l] == 2) {
            l++;
        } else {
            r--;
        }

        curVal -= 2;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(); 
    cin >> n >> k;

    int totalValue = 0;

    int leftMostOne = -1;
    int rightMostOne = -1;

    for(int i = 0; i < n; i++) {
        char c;
        cin >> c;

        loli[i] = c == 'T' ? 2 : 1;
        totalValue += loli[i];
    
        if (loli[i] == 1) {
            rightMostOne = i;
            
            if(leftMostOne == -1) {
                leftMostOne = i;
            }
        }
    }

    // Let's write all possible values of the same parity as totalValue
    writeAllSegments(0, n-1, totalValue);

    // Now let's find longest segment of different parity and write all of the possible values of this partiy
    if (rightMostOne != -1) {
        if (leftMostOne < n - 1 - rightMostOne) {
            int segVal = totalValue - 1 - 2 * leftMostOne;
            writeAllSegments(leftMostOne + 1, n - 1, segVal);
        } else {
            int segVal = totalValue - 1 - 2 * (n - 1 - rightMostOne);
            writeAllSegments(0, rightMostOne - 1, segVal);
        }
    }

    for(int i = 0; i < k; i++) {
        int a;
        cin >> a;

        pair<int, int> seg = valueToSegment[a];
        if (seg.first == 0 && seg.second == 0) {
            cout << "NIE\n";
        } else {
            cout << seg.first + 1 << " " << seg.second + 1 << "\n";
        }

    }

    return 0;
}