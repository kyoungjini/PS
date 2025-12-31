#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, l;
    int arr[1001];
    int res = 0;
    
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    int start_pos = arr[0];

    for (int i = 1; i < n; i++) {
        int diff = arr[i] - start_pos;
        
        if ((diff + 1 != l) && (i == n - 1)) res++;

        if (diff + 1 == l) {
            start_pos = arr[i + 1];
            res++;
        } else if (diff + 1 > l) {
            start_pos = arr[i];
            res++;
        }
    }

    cout << (n > 1 ? res : 1) << "\n";

    return 0;
}
