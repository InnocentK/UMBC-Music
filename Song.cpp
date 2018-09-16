/*****************************************
 ** File:    Song.cpp
 ** Project: CMSC 202 Project 5 - UMBC Music Player, Fall 2017
 ** Author:  Innocent Kironji
 ** Date:    12/01/17
 ** Section: 0107
 ** E-mail:  wambugu1@umbc.edu
 **
 **   This file contains the implementation of the Song class
 **
 ***********************************************/
#include "Song.h"

// For initilizations
const string EMPTY_STR = "";
const int EMPTY_INT = 0;
const int MIN_YEAR = 1983;
const int MAX_YEAR = 2013;
const int MIN_RANK = 1;
const int MAX_RANK = 3100;

// Song - Default Constructor
// Creates a default song
Song::Song(){

  setTitle(EMPTY_STR);
  setArtist(EMPTY_STR);
  setYear(EMPTY_INT);
  setRank(EMPTY_INT);
}

// Song - Overloaded Constructor
// Creates a song based on passed parameters
Song::Song(string title, string artist, int year, int rank ){

  setTitle(title);
  setArtist(artist);
  setYear(year);
  setRank(rank);
}

// Mutators and Accessors
// Sets and Gets private member variables

// Returns title
string Song::getTitle()const{
  return m_title;
}

// Returns artist
string Song::getArtist()const{
  return m_artist;
}

// Returns year
int Song::getYear()const{
  return m_year;
}

// Returns rank (1-100 from that year) 
int Song::getRank()const{
  return m_rank;
}

void Song::setTitle(string title){
  m_title = title;
}

void Song::setArtist(string artist){
  m_artist = artist;
}

void Song::setYear(int year){

  // If year given is invalid
  if( (year < MIN_YEAR) || (year > MAX_YEAR) )
    m_year = EMPTY_INT;

  // When valid year is given
  else
    m_year = year;
}

void Song::setRank(int rank){

  // If rank given is invalid
  if( (rank < MIN_RANK) || (rank > MAX_RANK) )
    m_rank = EMPTY_INT;

  // When valid rank is given
  else
    m_rank = rank;
}
