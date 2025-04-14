#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isArrSorted(vector<int>& arr){
    for (int i = 0; i<arr.size()-1; i++){
        if(arr[i] > arr[i+1])
            return 0;
    }
    return 1;
}

void reverse(vector<int>& arr, int s, int e) {
    int mid = s + (e - s) / 2;
        for (int i = s, j=e; i<j; i++, j--)
        {
            arr[i] = arr[i] + arr[j];
            arr[j] = arr[i] - arr[j];
            arr[i] = arr[i] - arr[j];
        }
}
string solve() {
    int n, k;
    cin >> n >> k;
    if(n==1)
        return "YES\n";

    vector<int> arr;

    for (int i = 0; i < n; i++){
        int val;
        cin >> val;
        arr.push_back(val);
    }

    if(k>1){
        for (int k = 0; k < n; k++){
            for (int i = 0; i < n - 1;)
            {
                int j = i;
                int count = 1;
                int sIdx = j, eIdx = j;
                while (arr[j] > arr[j + 1] && count <= k && j < n - 1)
                {
                    eIdx = j + 1;
                    j++;
                    count++;
                }

                if (i != j)
                    reverse(arr, sIdx, eIdx);
                else
                    eIdx++;
                i = eIdx;
            }
        }
    }
    if (isArrSorted(arr))
        return "YES\n";
    return "NO\n";
}

int main() {
    int t;
    cin >> t;
    while(t--){
        string res = solve();
        cout << res;
    }
    return 0;
}

// clang++ -o HalloumiBoxes HalloumiBoxes.cpp -stdlib=libc++ -isysroot $(xcrun --sdk macosx --show-sdk-path)
