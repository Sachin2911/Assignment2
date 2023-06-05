#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

void bestMoves(std::vector<int> head, std::vector<std::vector<int>>& matrix, std::vector<int> apple) {
    int x = head[0];
    int y = head[1];
    int xapp = apple[0];
    int yapp = apple[1];
    std::vector<int> right = { x + 1, y };
    std::vector<int> left = { x - 1, y };
    std::vector<int> up = { x, y - 1 };
    std::vector<int> down = { x, y + 1 };
    std::vector<double> distances;
    std::vector<std::string> labels;

    if (right[0] >= 0 && right[0] < matrix[0].size() && right[1] >= 0 && right[1] < matrix.size() && matrix[right[1]][right[0]] == 0) {
        double dist = std::sqrt(std::pow(xapp - right[0], 2) + std::pow(yapp - right[1], 2));
        distances.push_back(dist);
        labels.push_back("RIGHT");
    }
    if (left[0] >= 0 && left[0] < matrix[0].size() && left[1] >= 0 && left[1] < matrix.size() && matrix[left[1]][left[0]] == 0) {
        double dist = std::sqrt(std::pow(xapp - left[0], 2) + std::pow(yapp - left[1], 2));
        distances.push_back(dist);
        labels.push_back("LEFT");
    }
    if (up[0] >= 0 && up[0] < matrix[0].size() && up[1] >= 0 && up[1] < matrix.size() && matrix[up[1]][up[0]] == 0) {
        double dist = std::sqrt(std::pow(xapp - up[0], 2) + std::pow(yapp - up[1], 2));
        distances.push_back(dist);
        labels.push_back("UP");
    }
    if (down[0] >= 0 && down[0] < matrix[0].size() && down[1] >= 0 && down[1] < matrix.size() && matrix[down[1]][down[0]] == 0) {
        double dist = std::sqrt(std::pow(xapp - down[0], 2) + std::pow(yapp - down[1], 2));
        distances.push_back(dist);
        labels.push_back("DOWN");
    }

    if (distances.empty()) {
        std::cout << "No valid moves available." << std::endl;
    } else {
        double minDist = *std::min_element(distances.begin(), distances.end());
        std::vector<std::string> bestMoves;
        for (int i = 0; i < distances.size(); i++) {
            if (distances[i] == minDist) {
                bestMoves.push_back(labels[i]);
            }
        }
        std::sort(bestMoves.begin(), bestMoves.end());
        for (const std::string& move : bestMoves) {
            std::cout << move << std::endl;
        }
    }
}

int main() {
    int cols, rows;
    std::cin >> cols >> rows;

    int xapp, yapp;
    std::cin >> xapp >> yapp;
    std::vector<int> apple = { xapp, yapp };

    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols, 0));

    int numsnakes;
    std::cin >> numsnakes;
    std::vector<int> head;

    for (int i = 1; i <= numsnakes; i++) {
        int shx, shy, sbx, sby, stx, sty;
        std::cin >> shx >> shy >> sbx >> sby >> stx >> sty;

        matrix[shy][shx] = i;
        matrix[sby][sbx] = i;
        matrix[sty][stx] = i;

        if (i == 1) {
            head.push_back(shx);
            head.push_back(shy);
        }
    }

    bestMoves(head, matrix, apple);

    return 0;
}
