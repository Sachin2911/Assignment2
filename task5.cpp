#include <iostream>
#include <vector>

void setter(int row, int col, std::vector<std::vector<int>>& vec, int value) {
    vec[row][col] = value;
}

int main() {
    int cols;
    int rows;

    // apple
    int xapp;
    int yapp;

    std::cin >> cols >> rows;
    std::cin >> xapp >> yapp;

    std::vector<std::vector<int>> vect(rows, std::vector<int>(cols, 0));
    vect[yapp][xapp] = 5;

    int numsnakes;
    std::cin >> numsnakes;

    for (int i = 1; i <= numsnakes; i++) {
        int k;
        std::cin >> k;
        std::vector<int> snake_coords;

        for (int j = 0; j < k * 2; j++) {
            int coord;
            std::cin >> coord;
            snake_coords.push_back(coord);
        }

        for (int j = 0; j < snake_coords.size() - 2; j += 2) {
            int x1 = snake_coords[j];
            int y1 = snake_coords[j + 1];
            int x2 = snake_coords[j + 2];
            int y2 = snake_coords[j + 3];

            int dx = (x2 > x1) ? 1 : ((x2 < x1) ? -1 : 0);
            int dy = (y2 > y1) ? 1 : ((y2 < y1) ? -1 : 0);

            while (x1 != x2 || y1 != y2) {
                vect[y1][x1] = i;
                x1 += dx;
                y1 += dy;
            }
        }

        // Update the tail coordinate of the last snake
        int tx = snake_coords[snake_coords.size() - 2];
        int ty = snake_coords[snake_coords.size() - 1];
        vect[ty][tx] = i;
    }

    for (int i = 0; i < vect.size(); i++) {
        for (int j = 0; j < vect[0].size(); j++) {
            std::cout << vect[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
