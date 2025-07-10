#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 0 ≤ sx ≤ tx ≤ 1e9, 0 ≤ sy ≤ ty ≤ 1e9
    int minMoves(int sx, int sy, int tx, int ty) {
        using int64 = long long;
        int64 X = tx, Y = ty, SX = sx, SY = sy;
        long long moves = 0;

        if (SX == X && SY == Y) return 0;

        while (X >= SX && Y >= SY) {
            if (X == SX && Y == SY)           // reached the start
                return static_cast<int>(moves);

            if (X == Y) {                     // equal-coordinate state
                /* Only possible predecessor is (0,Y) or (X,0).
                   Keep whichever is still not below (SX,SY).          */
                if (SX == 0 && Y >= SY) X = 0;          // came along +x
                else if (SY == 0 && X >= SX) Y = 0;     // came along +y
                else return -1;                         // impossible
            }
            else if (X > Y) {               // X was the max → previous step added to X
                if (X >= 2 * Y) {           // must have doubled (X = 2*(prevX))
                    if (X & 1) return -1;   // X must be even
                    X >>= 1;                // prev = (X/2, Y)
                } else {
                    X -= Y;                 // prev = (X-Y, Y)
                }
            } else {                        // Y > X
                if (Y >= 2 * X) {
                    if (Y & 1) return -1;
                    Y >>= 1;                // prev = (X, Y/2)
                } else {
                    Y -= X;                 // prev = (X, Y-X)
                }
            }
            ++moves;
        }
        return -1;                          // fell below (SX,SY) → impossible
    }
};