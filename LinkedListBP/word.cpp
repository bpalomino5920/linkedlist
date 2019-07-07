#include <iostream>
#include <string>
#include "word.h"
#include <list>

//*********************************************************************************************
//*********************************************************************************************
// w o r d - 3 . C P P

/*************************************************************************************
 Name: Word
 Precondition: front and count have not been initialized.
 Postcondition: front and count have been initialized to 0.
 Description: This default constructor function sets two variables to 0.
 *************************************************************************************/
WORD::WORD()
{
    head = NULL;
    count = 0;
}
/*************************************************************************************
 Name: Word
 Precondition: head and count not initialized yet, for loop is idle
 Postcondition: head is set to null and count is set to 0. For loop is active.
 Description: This function is adding a string from the formal parameter by using the for loop.
 *************************************************************************************/
WORD::WORD(string word)
{
    head = NULL;
    count = 0;
    
    for (int i = 0; i < word.length(); i++)
        add(word.at(i));
}
/*************************************************************************************
 Name: Word
 Precondition: head and count has not been initialized yet. Current pointer has not yet been set. While loop is idle.
 Postcondition: head and count has been initialized and assigned to Null and 0. The current pointer is set to b.head where the current will be going through the active while loop that will inserting or add() the symbol (data) until current hits Null
 Description: The function explains of how this is inserting (add) using a current pointer through the list until hits NULL.
 *************************************************************************************/
WORD::WORD(const WORD & B)
{
    head = NULL;
    count = 0;
    
    character* current = B.head;
    
    while (current != NULL)
    {
        add(current->symbol);
        current = current->next;
    }
}
/*************************************************************************************
 Name: ~Word
 Precondition: head is not initialized yet and count as well. Delete is not activet yet
 Postcondition: head and count has been set to NULL and 0. delete is active by deleting (deallocating) head.
 Description: This is a destructor constructor where delete will deallocate the memory.
 *************************************************************************************/
WORD::~WORD()
{
    head = NULL;
    count = 0;
    
    delete head;
}
/*************************************************************************************
 Name: operator=
 Precondition: The parameters are not yet invoked, head is not yet set NULL and count is not yet set to 0. For loop is idle, so nothing has been return.
 Postcondition: head and count has been initialized. for loop is active with using the length for the condition where it is return the current object.
 Description: This is function is adding strings for the length of the list.
 *************************************************************************************/
const WORD& WORD::operator=(const string & str)
{
    head = NULL;
    count = 0;
    
    for (int i = 0; i < str.length(); i++)
        add(str.at(i));
    
    return *this;
}
/*************************************************************************************
 Name: operator=
 Precondition: if loops are idle, head and count is not yet initialized,  current pointer is not initialized, and while loop is idle.
 Postcondition: The parameters are being invoked. if and while loops active while head and count being initialized (including the current pointer).
 Description: This functions checks if head is empty and will return. If not, it will forward to the next if statement that will make head null and count 0. Current pointer will be b.head, then current will go through condition of while loop to add the symbol until null. Then returns the current object.
 *************************************************************************************/
const WORD& WORD::operator=(const WORD & B)
{
    if (B.head == NULL)
        return *this;
    
    if (this != &B)
    {
        head = NULL;
        count = 0;
        
        character* current = B.head;
        
        while (current != NULL)
        {
            add(current->symbol);
            current = current->next;
        }
    }
    
    return *this;
}
/*************************************************************************************
 Name: operator+
 Precondition: The parameters are not yet invoked. if and while loops are idle.
 Postcondition: Parameters are invoked, if and while loops are now active, and current pointer initialized.
 Description: This functions adds in data to the list. First checks if head is null, if not, then the current pointer will go through the list until it is null, meanwhile it add symbol. Returns the current object.
 *************************************************************************************/
WORD& WORD::operator+(const WORD & B)
{
    if (B.head == NULL)
        return *this;
    
    character * current = B.head;
    
    while (current != NULL)
    {
        add(current->symbol);
        current = current->next;
    }
    
    return *this;
}
/*************************************************************************************
 Name: Remove
 Precondition: Paramters are not yet invoked. Current pointer is not yet assigned. if and while loops are idle.
 Postcondition: Loops are active, paramters are invoked, current pointer is assigned.
 Description: This functions remove an element by first checking if empty head (front), if not, then the current pointer will be assigned as the current will move through the list by selecting a symbol to be remove until hits NULL.
 *************************************************************************************/
void WORD::Remove(const WORD & B)
{
    if (B.head == NULL)
        return;
    
    character * current = B.head;
    
    while (current != NULL)
    {
        remove(current->symbol);
        current = current->next;
    }
}
/*************************************************************************************
 Name: RemoveALL
 Precondition: Paramters are not yet invoked. Current pointer is not yet assigned. if and while loops are idle.
 Postcondition: Parameters are now invoked, loops are active, current pointer is assigned.
 Description: This function removes all of the list by using the current pointer to go through the list and finds symbol and removing until hits NULL.
 *************************************************************************************/
void WORD::RemoveALL(const WORD & B)
{
    if (B.head == NULL)
        return;
    
    character * current = B.head;
    
    while (current != NULL)
    {
        while (find(current->symbol))
            remove(current->symbol);
        
        current = current->next;
    }
}
/*************************************************************************************
 Name: IsEqual
 Precondition: The parameters has not been invoked, the if and while loops are idle, and the two pointers have not been set
 Postcondition: The parameters are nnow invoked. Two pointers are being assigned.
 Description: This function focuses on checking lists if they are equal to each other or not.
 *************************************************************************************/
bool WORD::IsEqual(const WORD & B)
{
    if (count != B.count)
        return false;
    
    character * currentA = head;
    character * currentB = B.head;
    while (currentA != NULL && currentB != NULL)
    {
        if (currentA->symbol != currentB->symbol)
            return false;
        
        currentA = currentA->next;
        currentB = currentB->next;
    }
    
    return true;
}
/*************************************************************************************
 Name: IsEmpty
 Precondition: returns not yet active
 Postcondition: return is active
 Description: This functions checks if the list is empty
 *************************************************************************************/
bool WORD::IsEmpty()
{
    return (head == NULL);
}
/*************************************************************************************
 Name: Length
 Precondition: returns nothing.
 Postcondition: returning count
 Description: This function returns the amount of count.
 *************************************************************************************/
int WORD::Length()
{
    return count;
}
/*************************************************************************************
 Name: Insert
 Precondition: Parameters are not yet invoked, if statements are idle. head and count not yet assigned.
 Postcondition: Parameter are now invoked, if loops are now active, and head and count assigned.
 Description: This function inserts a value of int p where it first checks if B.head is null, if not, then checks head is not null, if not, then head and count will be assigned p goes through the conditons of if loops.
 *************************************************************************************/
void WORD::Insert(const WORD & B, int p)
{
    if (B.head == NULL)
        return;
    
    if (head == NULL)
    {
        head = B.head;
        count = B.count;
        return;
    }
    
    if (p <= 1)
    {
        character* current = B.head;
        
        while (current->next != NULL)
            current = current->next;
        
        
        current->next = head;
        head = B.head;
        count += B.count;
    }
    else if (p > count)
    {
        character* current = head;
        
        while (current->next != NULL)
            current = current->next;
        
        current->next = B.head;
        count += B.count;
    }
    else
    {
        int index = 1;
        character* currentA = head;
        
        while (currentA != NULL && index < p - 1)
        {
            currentA = currentA->next;
            index++;
        }
        
        character* currentB = B.head;
        
        while (currentB->next != NULL)
            currentB = currentB->next;
        
        
        currentB->next = currentA->next;
        currentA->next = B.head;
        
        count += B.count;
    }
}
/*************************************************************************************
 Name: ostream& operator<<
 Precondition: Parameters have not been invoked, the current pointer is not been set yet,
 the while loop is idle.
 Postcondition: Parameters have been set, the current pointer has been initialized, and the while
 loop is now active and will return out.
 Description: This function uses out for the current->symbol then continues to the current next until hits NULL.
 *************************************************************************************/
ostream& operator<<(ostream & out, const WORD & word)
{
    character* current = word.head;
    
    while (current != NULL)
    {
        out << current->symbol << " ";
        current = current->next;
    }
    
    return out;
}
/*************************************************************************************
 Name: add
 Precondition: Parameter has not been set, the current pointer has not been set, the statements are idle, and the while loop is idle.
 Postcondition: Parameter has been called, newNode has been assigned as a new character. The if statement checks if the front is equal to 0, so it can add a new node.
 Description: This function adds a newNode in the list by moving the current pointer is setting it at the position.
 *************************************************************************************/
void WORD::add(char ch)
{
    character* newNode = new character(ch);
    
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        character* current = head;
        
        while (current->next != NULL)
            current = current->next;
        
        current->next = newNode;
    }
    count++;
}
/*************************************************************************************
 Name: remove
 Precondition: Parameter is not invoked, if and while loops are idle, and pointers are not yet initialized.
 Postcondition: Parameter is invoked, loops are idle, pointers are now assigned.
 Description: This function removes ch in the list by going through the list and then decrementing count.
 *************************************************************************************/
void WORD::remove(char ch)
{
    if (head == NULL)
        return;
    
    character * current = head;
    character * prev = NULL;
    
    while (current != NULL && current->symbol != ch)
    {
        prev = current;
        current = current->next;
    }
    
    if (current == NULL)
        return;
    
    if (prev == NULL)
        head = head->next;
    else
        prev->next = current->next;
    
    count--;
}
/*************************************************************************************
 Name: find
 Precondition: Parameter is not yet invoked, current pointer is not yet assigned, loops are not active.
 Postcondition: Paramter is invoked, current pointer assigned, and loops are active.
 Description: This functions searches for char type by setting current pointer to head and then goes through while loop condition and then if statement to find that certain type of char when using symbol.
 *************************************************************************************/
bool WORD::find(char ch)
{
    character* current = head;
    
    while (current != NULL)
    {
        if (current->symbol == ch)
            return true;
        
        current = current->next;
    }
    
    return false;
}
