#include <bits/stdc++.h>
using namespace std;
int main() { srand(time(NULL));
    int t = 1; cout << t << '\n';
    while (t--) {
        int n = 10, m = 10;
        cout << n << ' ' << m << '\n';
        for (int i = 0 ; i < n ; i++) {
            set<int> app;
            int new_num = rand() % 1000;
            while (app.count(new_num)) new_num = rand() % 1000;
            app.insert(new_num);
            cout << new_num << ' ' << rand() % 10 << '\n';
        }
        for (int i = 0 ; i < m ; i++) {
            int l = rand() % 1000, r = rand() % 1000;
            cout << min(l, r) << ' ' << max(l, r) << '\n';
        }
    }
}
