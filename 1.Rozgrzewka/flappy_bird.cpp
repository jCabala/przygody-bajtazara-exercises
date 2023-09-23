#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500000;
int n, X;
struct obstacle {
    int x;
    int bottom;
    int top;
} obstacles[MAXN], adjustedObstacles[MAXN];

obstacle adjust(obstacle ob) {
    int x = ob.x, bottom = ob.bottom, top = ob.top;

    top -= (x + top) % 2 == 0 ? 2 : 1;
    bottom += (x + bottom) % 2 == 0 ? 2 : 1;

    return {x, bottom, top};
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(); 
    cin >> n >> X;
    for(int i = 0; i < n; i++) {
        cin >> obstacles[i].x >> obstacles[i].bottom >> obstacles[i].top;
    }

    // Corner Case
    if(n == 0) {
        cout << 0 << "\n";
        return 0;
    }

    // First we are going to adjust each obstacle so all of the latter obstacles are achievable from it
    // If there is a scenerio where they are not we will find it here
    adjustedObstacles[n-1] = adjust(obstacles[n-1]);
    if(adjustedObstacles[n-1].top < adjustedObstacles[n-1].bottom) {
        cout << "NIE\n";
        return 0;
    }

    for(int i = n - 2; i >= 0; i--) {
        int deltaX = obstacles[i + 1].x - obstacles[i].x;
        int minPreviousBottom = adjustedObstacles[i + 1].bottom -  deltaX;
        int maxPreviousTop = adjustedObstacles[i + 1].top + deltaX; 
        
        int bottom = obstacles[i].bottom;
        int top = obstacles[i].top;
        int adjustedBottom = max(minPreviousBottom, bottom + 1);
        int adjustedTop = min(maxPreviousTop, top - 1);
        
        adjustedObstacles[i] = adjust({obstacles[i].x, adjustedBottom - 1, adjustedTop + 1});
        if(adjustedObstacles[i].top < adjustedObstacles[i].bottom) {
            cout << "NIE\n";
            return 0;
        }

    }

    // Now we also need to check if we are able to go from initial point to first obstacle
    // After that we can be sure that we can finish the game

    int initialDeltaX = adjustedObstacles[0].x;

    if(initialDeltaX < adjustedObstacles[0].bottom || -initialDeltaX > adjustedObstacles[0].top) {
        cout << "NIE\n";
        return 0;
    }

    int numOfTaps = 0, curX = 0, curY = 0;
    for(int i = 0; i < n; i++) {
        int obscacleX, obscacleBottom, obscacleTop;
        obscacleX = adjustedObstacles[i].x;
        obscacleBottom = adjustedObstacles[i].bottom;

        int deltaX = obscacleX - curX;
        int achievableBottom = curY - deltaX;
 
        curX = obscacleX;
        curY = max(achievableBottom, obscacleBottom);

        int minTapsThisRound = (curY - achievableBottom) / 2; // Should always be divisible by 2
        numOfTaps += minTapsThisRound;
        //cout << i << "th obstacle. Bird's (x, y, taps) is (" << curX << ", " << curY << ", " << minTapsThisRound << ")\n";
    }

    cout << numOfTaps << "\n";
    return 0;
}