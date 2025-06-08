#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> odds, revEvens;
        for (int i = 1; i<=n; i++){
            if(i%2 ==0 )
                revEvens.push_back(i);
            else
                odds.push_back(i);
        }

        reverse(revEvens.begin(), revEvens.end());

        for(auto itr: odds){
            cout << itr << " ";
        }
        for(auto itr: revEvens){
            cout << itr << " ";
        }
        cout << endl;
    }

    return 0;
}

// clang++ -o b b.cpp -stdlib=libc++ -isysroot $(xcrun --sdk macosx --show-sdk-path)

// 2
// 3
// 6


// 1 3 2
// 2 3 6 4 5 1
