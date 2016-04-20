//
//  Name: Yuya Oguchi
//  COEN 70
//  Chapter 3, Project 4
//  1/13/2016
//  Sequence class with functions to insert delete and operator overloading

#include <iostream>
#include "sequence.h"
using namespace std;

sequence::sequence() {
    data = new double [CAPACITY];
    used = 0;
    current_index = 0;
}

void sequence::start( ){
current_index = 0;
}

void sequence::advance( ){
current_index += 1;
}

void sequence::insert(const sequence::value_type& entry){
    for (int i=used; i > current_index; i--){
        data[i] = data[i-1];
    }
    data[current_index] = entry;
    used++;
}

void sequence::attach(const sequence::value_type& entry){
    for (int i=used; i > current_index + 1; i--){
        data[i] = data[i-1];
    }
    data[current_index +1] = entry;
    current_index++;
    used++;
}
void sequence::frontInsert(const sequence::value_type& entry){
    for (int i=used; i > -1; i--){
        data[i] = data[i-1];
    }
    data[0] = entry;
    used++;
}
void sequence::frontDelete(const sequence::value_type& entry){
    for (int i =0; i < used -1; i++){
        data[i] = data[i + 1];
    }
    used--;
}
void sequence::backInsert(const sequence::value_type& entry){
    data[used] = entry;
    used++;
}
void sequence::backDelete(const sequence::value_type& entry){
    data[used] = 0;
    used--;
}
void sequence::remove_current( ){
    if (current_index != 0){
        for (int i =current_index; i < used -1; i++){
            data[i] = data[i + 1];
        }
        used--;
    }
}

sequence::size_type sequence::size( ){
    return used;
}

bool sequence::is_item( ){
    if(used ==0){
        return false;
    }else {
        return true;
    }
}

sequence::value_type sequence::current( ) {
    return data[current_index];
}

void sequence::dump(){
    for(int i=0; i< used; i++){
        cout << "item: " << data[i] << endl;
    }
}

sequence sequence::operator+=(const sequence& s1){
    if(used + s1.used <= CAPACITY){
        for (int i = 1; i < s1.used; i++){
            data[used+i] = s1.data[i];
        }
        used = used + s1.used;
    }
    return s1;
}

sequence sequence::operator+(const sequence& s1)
{
    sequence temp;
    for (int i = 0; i < s1.used; i++){
        temp.data[i] = s1.data[i];
        cout << " adding" << temp.data[i] << endl;
    }
    for (int i = 0; i < s1.used; i++){
        temp.data[used+i] = s1.data[i];
        cout << " adding" << temp.data[i] << endl;
    }
    temp.used  = used + s1.used;
    return temp;
}

int main()
{
   sequence s;
   s.insert(10);
   s.insert(20);
   s.insert(30);
   cout << "s" << endl;
   s.dump();

   sequence s1;
   s1.insert(40);
   s1.insert(50);
   s1.attach(10);

   sequence s2;
   s2 = s + s1;
   cout << "s2" << endl;
   s2.dump();

}
