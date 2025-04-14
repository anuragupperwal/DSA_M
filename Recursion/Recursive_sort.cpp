#include<iostream>
// #include<bits/stdc++.h>
#include<vector>

using namespace std;

void swap(int i, int n, vector<int>& arr){
    int temp = arr[i];
    arr[i] = arr[n];
    arr[n] = temp;
}

void insertSorted(vector<int>& arr, int n, int val) {
    if(arr.size()==0 || arr[arr.size()] <= val) {
        arr.push_back(val);
        return;
    }

    int temp = arr[arr.size()-1];
    arr.pop_back();

    insertSorted(arr, n - 1, val);
    arr.push_back(temp);

}

void funRec(vector<int>& arr, int n) {
    if(n==0)
        return;

    int val = arr[n];
    funRec(arr, n - 1);
    cout << n<<" "<<val << endl;
    insertSorted(arr, n, val);
}

// void funItr(vector<int>& arr, int n) {
//     if(n==0)
//         return;

//     funItr(arr, n - 1);

//     int val = arr[n];
//     for (int i = n - 1; i >= 0; i--)
//     {
//         if(val < arr[i]){
//             swap(i, i + 1, arr);
//         }
//     }
// }

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    funRec(arr, n-1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

}