#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int bundle_min = 1000;
    int single_min = 1000;
    int tmp_bundle, tmp_single;
    
    for (int i = 0; i < m; i++) {
        cin >> tmp_bundle >> tmp_single;
        bundle_min = min(bundle_min, tmp_bundle);
        single_min = min(single_min, tmp_single);
    }

    int price_with_combination = bundle_min * (n / 6) + single_min * (n % 6);
    int price_only_single = single_min * n;
    int price_only_bundle = bundle_min * (n / 6 + 1);

    cout << min(price_with_combination, min(price_only_single, price_only_bundle)) << "\n";

    return 0;
}