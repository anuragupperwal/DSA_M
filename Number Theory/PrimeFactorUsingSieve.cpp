#include<iostream>
#include<vector>

using namespace std;

#define n 1000001
void Sieve(vector<int> &arr) {
    // vector<int> arr(n, -1);

    for (int i = 2; i < n; i++) {
        if(arr[i] == -1){
            for (int j = i; j < n; j+=i) {
                if(arr[j] == -1)
                    arr[j] = i;
            }
        }
    }
}

void PrimeFactors(int x) {
    vector<int> arr(n, -1);
    Sieve(arr);
    while(arr[x] != -1) {
        cout << arr[x] << " ";
        x = x / arr[x];
    }
}

int main() {
    int x;
    cin >> x;
    PrimeFactors(x);
    return 0;
}