#include "Set.h"
#include <iostream>
using namespace std;

Set::Set()
{
    data = 0;
    capacity = size = 0;
}

Set::Set(int c){
    capacity = c;
    data = new int[capacity];
    size = 0;
}


Set::Set(const Set& c){
    capacity = c.capacity;
    data = new int[capacity];
    size = c.size;
    for(int i=0; i < size; i++){
        data[i] = c.data[i];
    }
}


void Set::insert(int v){
    if (data != 0 && size < capacity){
        if (find(v) == -1){
            data[size] = v;
            size++;
        }
    }
}

void Set::insert(const int a[],int s){

    for(int i=0; i < s; i++){
        insert(a[i]);
    }

}

void Set::remove(int v){
    if (data != 0 && size > 0){
        int index = find(v);
        if (index != -1){
            data[index] = data[size-1];
            size--;
        }
    }
}

void Set::print(){
    if (data != 0){
        cout << "{";
        for(int i=0; i < size-1;i++){
            cout << data[i] << ",";
        }
        cout << data[size-1];
        cout << "}" << endl;
    }
}

void Set::print(char* id){
    cout << id << ":";
    print();
}

int Set::find(int v){
    if (data != 0){
        for(int i=0; i < size; i++){
            if (data[i] == v ){
                return i;
            }
        }
    }

    return -1;
}

bool Set::contains(int v){
    return find(v) != -1 ? true : false;
}

int Set::getSize(){
    return size;
}

void Set::reset(int c){
   // increase the capacity and clear the data
}

Set Set::unionset(Set& s){
    Set r(capacity + s.capacity);
    for(int i=0; i < size; i++){
        r.insert(data[i]);
    }

    for(int i=0; i < s.size; i++){
        r.insert(s.data[i]);
    }

    return r;
}

Set Set::intersection(Set& s){
    Set r;
   // find intersection
    return r;
}

Set Set::difference(Set& s){
    Set r;
    // find difference
    return r;
}

Set::~Set()
{
    if (data != 0)
        delete [] data;
}
