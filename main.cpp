#include <iostream>
#include <vector>
#include "simplex.hpp"

using namespace std;

// поиск методом ветвей и границ
void BranchesAndBorders(const vector<vector<double>> &a, const vector<double> &b, const vector<double> &c, SimplexMode mode) {
    Simplex simplex(a, b, c, mode);
    vector<SimplexSolve> solves = simplex.SolveIntegerBranchesAndBorders(); // ищем решения методом ветвей и границ
    simplex.FindBestSolve(solves); // находим лучшее решение
}

// поиск методом перебора
void Bruteforce(const vector<vector<double>> &a, const vector<double> &b, const vector<double> &c, SimplexMode mode) {
    Simplex simplex(a, b, c, mode);
    vector<SimplexSolve> solves = simplex.SolveIntegerBruteforce(25); // ищем решения перебором
    simplex.FindBestSolve(solves); // находим лучшее решение
}

int main() {
    vector<vector<double>> a = {
        { 4, 1, 1 },
        { 1, 2, 0 },
        { 0, 0.5, 1 }
    };

    vector<double> b = { 4, 3, 2 };
    vector<double> c = { 7, 5, 3 };

    SimplexMode mode = SimplexMode::Max; // режим работы

    BranchesAndBorders(a, b, c, mode); // ищем методом ветвей и границ
    Bruteforce(a, b, c, mode); // ищем переборным методом
}
