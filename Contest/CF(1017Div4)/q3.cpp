#include<iostream>
#include<vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector < vector<int> > g(n + 1, (vector <int> (n + 1, 0)));
        vector<int> res(2*n+2);

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++) {
                int val;
                cin >> val;
                g[i][j] = val;
            }
        }

        int i = 1, j = 1;
        while (i + j != 2*n) {
            res[i + j] = g[i][j];
            j++;
            if(j==n+1){
                i++;
                j = 1;
            }
        }
        res[i + j] = g[i][j];
        
        int sum = 0, vSum = 0;
        for (int i = 1; i <= 2 * n; i++){
            sum += i;
            vSum += res[i];
        }

        res[1] = (sum - vSum);

        for (int i = 1; i <= 2*n; i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}

// clang++ -o q3 q3.cpp -stdlib=libc++ -isysroot $(xcrun --sdk macosx --show-sdk-path)

// 3
// 3
// 1 6 2
// 6 2 4
// 2 4 3
// 1
// 1
// 2
// 2 3
// 3 4


// 5 1 6 2 4 3 
// 2 1 
// 1 2 3 4 
