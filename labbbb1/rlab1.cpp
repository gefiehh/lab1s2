#include "hlab1.h"
#include <string>

using namespace std;


string Food::name() const {
    return _name;
}

void Food::setname(const string &name) {
    _name = name;
}

int Food::price() const {
    return _price;
}

void Food::setprice(const int &price) {
    _price = price;
}

ostream &operator <<(ostream &out, const Food &r) {
    out << "Name: " << r._name << ", Price: " << r._price << endl;
    return out;
}

istream &operator >>(istream &in, Food &r){
    cout << "Name: ";
    in >> r._name;
    cout << "Price: ";
    in >> r._price;
    return in;
}


void save(Food *arr, int n){
    ofstream out("a.txt");
    if (!out.is_open())
        return;
    out << n << endl;
    for (int i = 0; i < n; i++)
        out << arr[i].name() << " " << arr[i].price() << endl;
    out.close();
}

Food *load(int &n){
    ifstream in("a.txt");
    if (!in.is_open())
        return nullptr;
    in >> n;
    if ( n <= 0)
        return nullptr;
    Food *arr = new Food[n];
    for (int i = 0; i < n; i++){
        string name;
        int price;
        in >> name >> price;
        arr[i].setname(name);
        arr[i].setprice(price);
    }
    in.close();
    return arr;
}

void create(){
    int n{};
    cout << "n = ";
    cin >> n;
    if (n < 1)
        return;
    Food *arr = new Food[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    save(arr, n);
    delete [] arr;
    return;
}

Food * add(Food *arr, int &n) {
    arr = load(n);
    Food *new_arr = new Food[n + 1];
    for (int i = 0; i < n; i++) {
        new_arr[i] = arr[i];
    }
    cout << "Enter the name of the food: ";
    string name;
    cin >> name;
    cout << "Enter the price of the food: ";
    int price;
    cin >> price;
    new_arr[n].setname(name);
    new_arr[n].setprice(price);
    n++;
    delete[] arr;
    return new_arr;
}

Food * remove() {
    int n = 0;
    Food *arr = load(n);
    int index = -1;
    cout << "Enter the name of the food you want to remove: ";
    string name;
    cin >> name;
    for (int i = 0; i < n; i++){
        if (arr[i].name() == name){
            index = i;
            break;
        }
    }
    if (index == -1)
        return arr;
    Food *newarr = new Food[n - 1];
    for (int i = 0; i < index; i++)
        newarr[i] = arr[i];
    for (int i = 0; i < index + 1; i++)
        newarr[i - 1] = arr[i];
    return newarr;
    save(arr, n);
}

void edit(Food *arr, int n) {
    arr = load(n);
    cout << "Enter the name of the food you want to edit: ";
    string name;
    cin >> name;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i].name() == name) {
            cout << "Enter the new name: ";
            string new_name;
            cin >> new_name;
            cout << "Enter the new price: ";
            int new_price;
            cin >> new_price;
            arr[i].setname(new_name);
            arr[i].setprice(new_price);
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Food not found" << endl;
    }
    save(arr, n);
}

void search(Food *arr, int n) {
    arr = load(n);
    cout << "Enter the name of the food you want to search: ";
    string name;
    cin >> name;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i].name() == name) {
            cout << arr[i] << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Food not found" << endl;
    }
    save(arr, n);
}
