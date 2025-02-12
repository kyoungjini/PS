#include <iostream>
#include <string>
using namespace std;

int main() {
    
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string s, p;
        cin >> s >> p;

        int cnt_for_paste = 0;

        for (int j = 0; j < s.length(); ) {
            int idx_flag = s.find(p, j);

            if (idx_flag == -1) break;

            cnt_for_paste++;
            j = idx_flag + p.length();
        }
        
        int cnt_for_enter = s.length() - (cnt_for_paste * p.length());

        cout << cnt_for_paste + cnt_for_enter << "\n";
    }

    return 0;
}