#include <iostream>
using namespace std;

int main() {
    int n, m, t;
    cin >> n >> m >> t;

    int max_burger = 0;
    int min_coke_time = 20000;

    int max_n_burger = t / n;
    int left_time, m_burger, coke_time;

    for (int i = max_n_burger; i >= 0; i--) {
        left_time = t - n * i;
        m_burger = left_time / m;
        coke_time = left_time % m;
        
        if (min_coke_time > coke_time) {
            min_coke_time = coke_time;
            max_burger = i + m_burger;
        }
        else if (min_coke_time == coke_time && max_burger < (i + m_burger)) {
            max_burger = i + m_burger;
        }
    }

    cout << max_burger << " " << min_coke_time << "\n";

    return 0;
}