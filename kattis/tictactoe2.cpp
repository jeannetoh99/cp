#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
#include <tuple>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cstring>

using namespace std;

int findDiagonalLines(char grid[][3], char p) {

    int lines = 0;
    if (grid[0][0] == p && grid[1][1] == p && grid[2][2] == p) lines++;
    if (grid[0][2] == p && grid[1][1] == p && grid[2][0] == p) lines++;
    
    return lines;
}

int findVerticallLines(char grid[][3], char p) {

    int lines = 0;
    for (int i = 0; i < 3; i++) {
        bool line = true;
        for (int j = 0; j < 3; j++) {
            if (grid[j][i] != p) line = false;
        }
        if (line) lines++;
    }
    return lines;

}

int findHorizontalLines(char grid[][3], char p) {

    int lines = 0;
    for (int i = 0; i < 3; i++) {
        bool line = true;
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] != p) line = false;
        }
        if (line) lines++;
    }
    return lines;

}

bool checkValidity(char grid[][3], int x, int o) {

    // invalid if o > x (since x starts first)
    if (o > x) return false;
    
    // invalid if o and x has diff greater than 1
    if (x - o > 1) return false;

    // from here on number of Xs and Os are valid, check positions
    int xlines = findHorizontalLines(grid, 'X') + findVerticallLines(grid, 'X')
        + findDiagonalLines(grid, 'X');

    int olines = findHorizontalLines(grid, 'O') + findVerticallLines(grid, 'O')
        + findDiagonalLines(grid, 'O');

    // invalid if both have lines
    if (xlines > 0 && olines > 0) return false;

    // invalid if o has 2 lines (requires 5 tokens but o has max 4 turns)
    // this should be checked by above o > x check

    // invalid if o wins but x > o
    if (olines > 0 && x > o) return false; 

    // invalid if x wins but o == x
    if (xlines > 0 && x == o) return false;

    // invalid if x and o has > 2 lines (above checks sufficient -- since this requires min 6 tokens)
    
    // x with 2 lines if valid given above (guaranteed 5x and 4o) 
    
    // valid otherwise
    return true;
}

int main() {

    int N; cin >> N;

    while (N--) {
        char grid[3][3];
        int x = 0;
        int o = 0;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                char c; cin >> c;
                grid[i][j] = c;
                if (c == 'X') x++;
                if (c == 'O') o++;
            }
        }

        if (checkValidity(grid, x, o)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

}