#ifndef SET_H
#define SET_H


class Set
{
    private:
        int* data;
        int capacity;
        int size;

        int find(int v);


    public:
        Set();
        Set(int c);
        Set(const Set& c);
        void insert(int v); // add an element
        void insert(const int a[],int s); // add an array of elements to set
        void remove(int v); // remove an element
        bool contains(int v); //checks if an element exists
        int getSize(); // size of set
        void reset(int c); // remove all elements and update the capacity of set

        Set unionset(Set& s); // union of two sets
        Set intersection(Set& s); // intersection of two sets
        Set difference(Set& s); // difference of two sets
        void print(); // print the content of sets
        void print(char* id); // print id and the content of sets
        ~Set();
};

#endif // SET_H
