//
//  Name: Yuya Oguchi
//  COEN 70
//  Chapter 3, Project 4
//  1/13/2016
//  Sequence class with functions to insert delete and operator overloading

#include <cstdlib>  // Provides size_t
class sequence{
private:
    double *data;
    int used;
    int current_index;
public:
    typedef double value_type;
    typedef std::size_t size_type;
    static const size_type CAPACITY = 30;
    // CONSTRUCTOR
    sequence( );
    // MODIFICATION MEMBER FUNCTIONS
    void start( );
    void advance( );
    void insert(const value_type& entry);
    void attach(const value_type& entry);
    void frontInsert(const value_type& entry);
    void frontDelete(const value_type& entry);
    void backInsert(const value_type& entry);
    void backDelete(const value_type& entry);
    void remove_current( );
    // CONSTANT MEMBER FUNCTIONS
    size_type size( ) ;
    bool is_item( );
    value_type current( );
    void dump();
    sequence operator+(const sequence& s1);
    sequence operator+=(const sequence& s1);
};
