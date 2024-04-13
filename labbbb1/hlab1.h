#ifndef HLAB1_H
#define HLAB1_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;


class Food{
    private:
        string _name;
        int _price;
    public:
        string name() const;
        void setname(const string &name);
        int price() const;
        void setprice(const int &price);
        friend ostream &operator <<(ostream &out, const Food &r);
        friend istream &operator >>(istream &in, Food &r);
    };

void save(Food *arr, int n);
Food *load(int &n);
void create();
Food * add(Food *arr, int &n);
void remove(Food *&arr, int &n);
void edit(Food *arr, int n);
void search(Food *arr, int n);

#endif // HLAB1_H
