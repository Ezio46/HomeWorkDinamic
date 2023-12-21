#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    int n;
    inputFile >> n;

    vector<vector<int>> tree(n, vector<int>(n, 0));

    // Ввод ёлки
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            inputFile >> tree[i][j];
        }
    }

    // Динамическое программирование
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            tree[i][j] += max(tree[i + 1][j], tree[i + 1][j + 1]);
        }
    }

    // Вывод максимальной суммы
    cout << tree[0][0] << endl;

    inputFile.close();

    return 0;
}
