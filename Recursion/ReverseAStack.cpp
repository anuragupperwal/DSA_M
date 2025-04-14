#include<iostream>
#include<stack>

using namespace std;

void insertEle(stack<int>& arr, int val) {
    if(arr.empty()) {
        arr.push(val);
        return;
    }

    int temp = arr.top();
    arr.pop();
    insertEle(arr, val);
    arr.push(temp);

}

void reverseStack(stack<int>& arr) {
    if(arr.size() == 0)
        return;

    int temp = arr.top();
    arr.pop();
    reverseStack(arr);
    insertEle(arr, temp); //induction step

    return;
}

int main() {
    stack<int> arr;
    for (int i = 0; i < 5; i++){
        int a;
        cin >> a;
        arr.push(a);
    }
    
    if(arr.size()==0)
        return 0;
    reverseStack(arr);

    while(!arr.empty()){
        cout << arr.top()<<" ";
        arr.pop();
    }
}