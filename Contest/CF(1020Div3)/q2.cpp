#include<iostream>
#include<vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n>>x;
        vector<int> res;

        if(n==x)
            for (int i = 0; i < n ; i++)
                res.push_back(i);
        else {
            for (int i = 0; i < n - 1; i++)
            {
                if(i<x) {
                    res.push_back(i);
                }
                else {
                    res.push_back(i + 1);
                }
            }
            res.push_back(x);
        }

        for (int i = 0; i < n; i++)
            cout << res[i] << " ";
        cout << endl;
        
    }

    return 0;
}

// clang++ -o q2 q2.cpp -stdlib=libc++ -isysroot $(xcrun --sdk macosx --show-sdk-path)