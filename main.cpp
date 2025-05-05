
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    // Header
    cout << "=== Simulasi Knapsack dengan Brute Force ===" << endl;
    cout << "Nama Mahasiswa : Muhammad Ibnu Pradipta" << endl;
    cout << "NIM Mahasiswa  : 23533832" << endl;
    cout << endl;

    // Data item
    vector<int> weights = {0, 10, 20, 30};   // Index 0 tidak digunakan
    vector<int> values  = {0, 60, 100, 120}; // Index 0 tidak digunakan
    int n = 3;

    cout << "Jumlah item yang tersedia: " << n << endl;
    for (int i = 1; i <= n; ++i) {
        cout << "Item ke-" << i << ":" << endl;
        cout << "  Berat = " << weights[i] << endl;
        cout << "  Nilai = " << values[i] << endl;
    }

    cout << endl;
    int capacity = 50;
    cout << "Kapasitas maksimum tas: " << capacity << endl << endl;

    int max_value = 0;
    vector<int> best_combination;

    int total_combinations = pow(2, n);
    for (int i = 0; i < total_combinations; ++i) {
        int total_weight = 0, total_value = 0;
        vector<int> combination;

        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                total_weight += weights[j + 1];
                total_value += values[j + 1];
                combination.push_back(j + 1);
            }
        }

        if (total_weight <= capacity && total_value > max_value) {
            max_value = total_value;
            best_combination = combination;
        }
    }

    cout << "Item yang diambil: ";
    for (int item : best_combination) {
        cout << "Item" << item << " ";
    }
    cout << endl;

    cout << "Total nilai maksimum yang bisa dibawa: " << max_value << endl;
    cout << endl;
    cout << "Program oleh: Muhammad Ibnu Pradipta | NIM: 23533832" << endl;

    return 0;
}
