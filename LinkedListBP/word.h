#include <iostream>
#include <string>
#include <list>

using namespace std;

//*********************************************************************************************
//*********************************************************************************************
// w o r d - 3 . h

#ifndef WORD_H
#define WORD_H

class character
{
public:
    char symbol;
    character* next;
    
    character(char ch)
    {
        symbol = ch;
        next = NULL;
    }
};

class WORD
{
    friend ostream& operator<<(ostream& out, const WORD& word); //Overload the insertion operator as a friend function with chaining to print a word A;
    
public:
    WORD(); //The default constructor will initialize your state variables.
    //The front of the linked list is initially set to NULL or 0; this implies a non-header node
    //implementation of the link list.
    WORD(string word); //explicit constructor
    WORD(const WORD& B); //copy constructor
    ~WORD(); //Destructor: The destructor will de-allocate all memory allocated for the word. Put the message
    //"destructor called\n" inside the body of the destructor.
    bool IsEmpty(); // checks if it is empty
    int Length(); //Length: Determines the length of the word A; remember A is the current object;
    void Insert(const WORD& B, int p); //insert function; adding in p as key or index
    void Remove(const WORD& B); //remove function for list B
    void RemoveALL(const WORD& B); //remove all function for list B
    bool IsEqual(const WORD& B); //Returns true if two word objects are equal; otherwise false; remember A is the current
    const WORD& operator=(const WORD& B);//Overload the ‘+” operator as a member function without chaining to add word B
    //(adds the set of symbols that makep B's linked list to the back of A's linked list) to the back of word A;
    //remember A is the current object;
    const WORD& operator=(const string& s); // Overload the assignment operator as a member function to take a
    // string (C-style or C++ string, just be consistent in your implementation) as an argument and
    //assigns its value to A, the current object;
    
    WORD& operator+(const WORD&); //Overload the ‘+” operator as a member function without chaining to add word B
    //(adds the set of symbols that makep B's linked list to the back of A's linked list) to the back of word A;
    //remember A is the current object;
    
private:
    void add(char ch); //inserting a char type
    bool find(char ch); //searching a char type
    void remove(char ch); //remove a char type
    
    character* head; //front
    int count; //amount of counts
};
#endif
