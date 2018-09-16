/*****************************************
 ** File:    Tquque.cpp
 ** Project: CMSC 202 Project 5 - UMBC Music Player, Fall 2017
 ** Author:  Jeremy Dixon
 ** User:    Innocent Kironji
 ** Date:    12/01/17
 ** Section: 0107
 ** E-mail:  wambugu1@umbc.edu
 **
 **   This file contains the full implementation of the Tquue class
 **    Tqueue is a queue that stores and manages songs that will be
 **    "played" using the MusicPlayer 
 ** 
 ***********************************************/
#ifndef TQUEUE_H
#define TQUEUE_H

#include <iostream>
#include <cstdlib>
using namespace std;

template <class T, int N>
class Tqueue {
public:
  //Name: Tqueue - Default Constructor
  //Precondition: None (Must be templated)
  //Postcondition: Creates a queue using dynamic array
  Tqueue(); //Default Constructor
  //Name: Copy Constructor
  //Precondition: Existing Tqueue
  //Postcondition: Copies an existing Tqueue
  Tqueue( const Tqueue<T,N>& x ); //Copy Constructor
  //Name: Destructor
  //Precondition: Existing Tqueue
  //Postcondition: Destructs existing Tqueue
  ~Tqueue(); //Destructor
  //Name: enqueue
  //Precondition: Existing Tqueue
  //Postcondition: Adds item to back of queue
  void enqueue(T data); //Adds item to queue (to back)  
  //Name: dequeue
  //Precondition: Existing Tqueue
  //Postcondition: Removes item from front of queue
  void dequeue(T &); //Removes item from queue (from front)  
  //Name: queueFront
  //Precondition: Existing Tqueue
  //Postcondition: Retrieve front (does not remove it)
  void queueFront(T &);    // Retrieve front (does not remove it)
  //Name: isEmpty
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is empty else 0
  int isEmpty(); //Returns 1 if queue is empty else 0  
  //Name: isFull
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is full else 0
  int isFull(); //Returns 1 if queue is full else 0 
  //Name: size
  //Precondition: Existing Tqueue
  //Postcondition: Returns size of queue
  int size() const; //Returns size of queue  
  //Name: Overloaded assignment operator
  //Precondition: Existing Tqueue
  //Postcondition: Sets one Tqueue to same as a second Tqueue using =
  Tqueue<T,N>& operator=( Tqueue<T,N> y); //Overloaded assignment operator for queue
  //Name: Overloaded [] operator
  //Precondition: Existing Tqueue
  //Postcondition: Returns object from Tqueue using []
  T& operator[] (int x);//Overloaded [] operator to pull data from queue
private:
  T* m_data; //Data of the queue (Must be dynamically allocated array)
  int m_front; //Front of the queue
  int m_back; //Back of the queue
};

//**** Add class definition below ****

// Tqueue - Default Constructor
// Creates a queue using dynamic array
template <class T, int N>
Tqueue<T,N>::Tqueue(){ 

  // Declaring an initializing dynamically allocated array
  m_data = new T[N];
  m_front = 0;
  m_back = 0;
}

// Copy Constructor
// Copies an existing Tqueue
template <class T, int N>
Tqueue<T,N>::Tqueue(const Tqueue<T,N> &x){

  // Declaring an initializing dynamically allocated array w/ copied variables
  m_data = new T[N];
  for (int i = 0; i < x.size(); i++)
    m_data[i] = x.m_data[i];

  // Copies positions for front and back of queue
  m_front = x.m_front;
  m_back = x.m_back;
}

// Destructor
// Destructs existing Tqueue
template <class T, int N>
Tqueue<T,N>::~Tqueue(){

  delete [] m_data;
  m_data = NULL;
}

// enqueue
// Adds item to back of queue
template <class T, int N>
void Tqueue<T,N>::enqueue(T data){

  // Checks if queue is full
  if( isFull() ) {
    cout << "[!!!!] Can't add because your queue is already full!" << endl;
  }
  // Checks if queue is empty
  else if( isEmpty() ){
    m_data[m_front] = data;
    m_back++;
  }
  // Queue has populated elements but is not full
  else{
    m_data[m_back] = data;
    m_back++;
  }
}

// dequeue
// Removes item from front of queue
template <class T, int N>
void Tqueue<T,N>::dequeue(T &data){

  // Retrives data before deleting
  queueFront(data);

  // front is only removed if queue has elements
  if( !isEmpty() ){

    // Update front
    m_front++;

    // Creating a copy of m_data with one less element
    T* temp = new T[size()];
    for(int i = 0; i < size(); i++)
      temp[i] = m_data[i + m_front];  

    // Deleting the old data    
    delete [] m_data;

    // Resetting the Tqueue with new info
    m_data = temp;
    m_back -= m_front;
    m_front = 0;
  }
}

// queueFront
// Retrieve front (does not remove it)
template <class T, int N>
void Tqueue<T,N>::queueFront(T &data){

  // Checks if queue is empty
  if ( isEmpty() ){
    cout << "Cannot complete action on front" 
	 << " because the queue is empty!" << endl;
  }else{
    data = m_data[m_front];
  }
}

// isEmpty
// Returns 1 if queue is empty else 0
template <class T, int N>
int Tqueue<T,N>::isEmpty(){

  // Uses size of queue to determine emptiness
  if (size() == 0)
    return 1;
  // When queue is populated
  else
    return 0;
}

// isFull
// Returns 1 if queue is full else 0
template <class T, int N>
int Tqueue<T,N>::isFull(){

  // When m_data has all it's positions filled
  if (m_back == N)
    return 1;
  // m_data is not completely filled
  else
    return 0;
}

// size
// Returns size of queue
template <class T, int N>
int Tqueue<T,N>::size() const{
  return m_back - m_front;
}

// Overloaded assignment operator
// Sets one Tqueue to same as a second Tqueue using =
template <class T, int N>
Tqueue<T,N>& Tqueue<T,N>::operator=( Tqueue<T,N> y){

  // Initializing dynamically allocated array w/ copied variables
  m_data = new T[N];
  for (int i = 0; i < y.size(); i++)
    m_data[i] = y.m_data[i];

  // Copying positions for front and back of queue
  m_front = y.m_front;
  m_back = y.m_back;
  return *this;
}

// Overloaded [] operator
// Returns object from Tqueue using []
template <class T, int N>
T& Tqueue<T,N>::operator[] (int x){

  // Validates that proper x is given
  if( (x >= m_front) && (x < m_back) )
    return m_data[x];

  // Returns first value if invalid element is attempted access
  else{
    cout << "You did not enter a valid position in the queue" << endl;
    return m_data[m_front];
  }
}

#endif

