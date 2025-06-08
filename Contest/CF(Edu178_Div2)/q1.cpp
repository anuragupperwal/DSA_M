#include<iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;
        bool flag = false;
        int low = b, high = c;
        while(low<=high) {
            int mid = low + (high - low) / 2;

            int m1 = mid - a;
            int m2 = mid - b;
            int m = c - m1 - m2;
        
            if ((m) == mid)
            {
                flag = true;
                break;
            }
            else if(m < mid){
                high = mid-1;
            }
            else if(m>mid){
                low = mid+1;
            }
        }

        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

// clang++ -o q1 q1.cpp -stdlib=libc++ -isysroot $(xcrun --sdk macosx --show-sdk-path)

// 4
// 3 5 10
// 12 20 30
// 3 5 7
// 1 5 6
