#include "hlab1.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    int n;
    Food *arr = NULL;
    bool work = true;
    while (work){
        int key;
        cout << "1 - create, 2 - write, 3 - add, 4 - remove, 5 - edit, 6 - search" << endl;
        cin >> key;
        switch (key) {
        case 1:
            create();
            break;
        case 2:
            arr = load(n);
            for (int i = 0; i < n; i++)
                cout << arr[i];
            break;
        case 3:
            arr = add(arr, n);
            save(arr, n);
            break;
        case 4:
            remove(arr, n);
            save(arr, n);
            break;
        case 5:
            edit(arr, n);
            break;
        case 6:
            search(arr, n);
            break;
        default:
            work = false;
            break;
        }
    }
    delete [] arr;
    return 0;
}

