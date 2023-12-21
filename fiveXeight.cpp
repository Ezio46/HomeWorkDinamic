#include <iostream>
#include <vector>

using namespace std;

long long countNumbers(int N) {
    // dp[i][0] - количество чисел длины i, заканчивающихся на "5"
    // dp[i][1] - количество чисел длины i, заканчивающихся на "8"
    vector<vector<long long>> dp(N + 1, vector<long long>(2, 0));

    dp[1][0] = 1; // Однозначные числа, которые заканчиваются на "5"
    dp[1][1] = 1; // Однозначные числа, которые заканчиваются на "8"

    for (int i = 2; i <= N; ++i) {
        dp[i][0] = dp[i - 1][1] + dp[i - 1][0]; // Числа длины i, заканчивающиеся на "5"
        dp[i][1] = dp[i - 1][0] + dp[i - 2][1]; // Числа длины i, заканчивающиеся на "8"
    }

    return dp[N][0] + dp[N][1];
}

int main() {
    int N = 3;

    if (N < 1 || N > 88) {
        cerr << "Ошибка. N должно быть от 1 до 88." << endl;
        return 1;
    }

    long long result = countNumbers(N);
    cout << "Количество N-значных чисел: " << result << endl;

    return 0;
}
