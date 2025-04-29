#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[9];
    int total_sum = 0;
    int exclude1, exclude2;
    bool flag = false;

    for (int i = 0; i < 9; i++) {
        cin >> arr[i];
        total_sum += arr[i];
    }

    sort(arr, arr + 9);

    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (total_sum - arr[i] - arr[j] == 100) {
                exclude1 = i;
                exclude2 = j;
                flag = true;
                break;
            }
        }

        if (flag) break;
    }

    for (int i = 0; i < 9; i++) {
        if (i == exclude1 || i == exclude2) continue;
        cout << arr[i] << "\n";
    }

    return 0;
}