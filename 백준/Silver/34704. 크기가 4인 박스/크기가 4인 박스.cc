#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[5] = {0, };
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        arr[tmp]++;
    }

    int res = 0;

    // 4
    res += arr[4];
    
    // 1 & 3
    if (arr[3] > 0 && arr[1] > 0) {
        int min_val = min(arr[1], arr[3]);
        res += min_val;
        arr[1] -= min_val;
        arr[3] -= min_val;
    }

    // 2
    res += arr[2]/2;
    arr[2] %= 2;

    // 1 & 2
    if (arr[2] > 0 && arr[1] > 0) {
        res++;
        arr[2]--;
        (arr[1] == 1 ? arr[1]-- : (arr[1] -= 2));
    } 

    // 1
    res += arr[1]/4;
    arr[1] %= 4;

    // left
    if (arr[1] > 0) res++;
    if (arr[2] > 0) res++;
    if (arr[3] > 0) res += arr[3];

    cout << res << "\n";

    return 0;
}
