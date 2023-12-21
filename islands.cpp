#include <iostream>
#include <vector>
#include <random>

using namespace std;

void dfs(vector<vector<int>>& matrix, int row, int col, int N) {
    matrix[row][col] = 0;

    // Соседние ячейки
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; ++i) {
        int newRow = row + dr[i];
        int newCol = col + dc[i];

        // Проверка на выход за границы и наличие острова в соседней ячейке
        if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < N && matrix[newRow][newCol] == 1) {
            dfs(matrix, newRow, newCol, N);
        }
    }
}

int countIslands(vector<vector<int>>& matrix, int N) {
    int islandsCount = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (matrix[i][j] == 1) {
                ++islandsCount;
                dfs(matrix, i, j, N);
            }
        }
    }

    return islandsCount;
}

int main() {
    int N = 5;

    vector<vector<int>> matrix(N, vector<int>(N, 0));

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 1);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = dis(gen);
        }
    }

    // Вывод матрицы
    cout << "Сгенерированная матрица:" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }

    // Результат
    int islandsCount = countIslands(matrix, N);
    cout << "Количество островов: " << islandsCount << endl;

    return 0;
}
