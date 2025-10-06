#include "Cube.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

Cube::Cube(int s) {
    setSide(s);
}

void Cube::setSide(int s) {
    if (s > 0)
        side = s;
    else
        side = 1;  // default if invalid
}

int Cube::getSide() const {
    return side;
}

void Cube::draw() const {
    int n = side;
    if (n <= 0) return;

    // n == 1: trivial cube
    if (n == 1) {
        std::cout << "*\n";
        return;
    }

    // --- Geometry with horizontal scale = 2 ---
    int dx   = n - 1;                         // depth
    int rows = dx + n;                        // vertical size unchanged
    int cols = 2 * (dx + n - 1) + 1;          // doubled horizontal, enough to reach back-right

    std::vector<std::string> grid(rows, std::string(cols, ' '));

    auto setPix = [&](int r, int c) {
        if (r >= 0 && r < rows && c >= 0 && c < cols) grid[r][c] = '*';
    };

    // Horizontal edges: n stars with spaces (ensure spacing)
    auto drawHoriz = [&](int r, int c1, int c2) {
        if (c1 > c2) std::swap(c1, c2);
        for (int c = c1; c <= c2; c += 2) setPix(r, c);
        // ensure right endpoint is drawn (parity safety)
        setPix(r, c2);
    };

    auto drawVert = [&](int r1, int r2, int c) {
        if (r1 > r2) std::swap(r1, r2);
        for (int r = r1; r <= r2; ++r) setPix(r, c);
    };

    // Diagonals step 1 row and 2 columns (to match horizontal scaling)
    auto drawDiagDownLeft = [&](int r, int c, int len) {
        for (int k = 0; k < len; ++k) setPix(r + k, c - 2 * k);
    };
    auto drawDiagUpRight = [&](int r, int c, int len) {
        for (int k = 0; k < len; ++k) setPix(r - k, c + 2 * k);
    };

    // Key corners (row, col) with horizontal scale = 2
    int rBTL = 0,             cBTL = 2 * dx;           // Back Top Left
    int rBTR = 0,             cBTR = 2 * (dx + n - 1); // Back Top Right
    int rFTL = dx,            cFTL = 0;                // Front Top Left
    int rFTR = dx,            cFTR = 2 * (n - 1);      // Front Top Right
    int rFBL = dx + n - 1,    cFBL = 0;                // Front Bottom Left
    int rFBR = dx + n - 1,    cFBR = 2 * (n - 1);      // Front Bottom Right
    int rBBR = n - 1;                                   // Back Bottom Right (col = cBTR)

    // 1) Top back horizontal edge (spaced)
    drawHoriz(rBTL, cBTL, cBTR);

    // 2) Slanted top edges (back -> front)
    drawDiagDownLeft(rBTL, cBTL, dx + 1);  // BTL -> FTL
    drawDiagDownLeft(rBTR, cBTR, dx + 1);  // BTR -> FTR

    // 3) Front face outline (spaced top & bottom)
    drawHoriz(rFTL, cFTL, cFTR);           // front top
    drawVert(rFTL, rFBL, cFTL);            // front left
    drawVert(rFTR, rFBR, cFTR);            // front right
    drawHoriz(rFBL, cFBL, cFBR);           // front bottom

    // 4) Right face outline
    drawVert(rBTR, rBBR, cBTR);            // back-right vertical
    drawDiagUpRight(rFBR, cFBR, dx + 1);   // FBR -> BBR

    // Print the buffer
    for (const auto& line : grid) std::cout << line << '\n';
}