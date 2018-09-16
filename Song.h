/*****************************************
 ** File:    Song.h
 ** Project: CMSC 202 Project 5 - UMBC Music Player, Fall 2017
 ** Author:  Jeremy Dixon
 ** User:    Innocent Kironji
 ** Date:    12/01/17
 ** Section: 0107
 ** E-mail:  wambugu1@umbc.edu
 **
 **   This file contains the class header of the Song class
 **   Song manages information about specific songs used in the playlist
 **
 **   This file has not been modified from Professor Dixion's
 **    version aside from these comments
 ***********************************************/

#include <iostream>
#include <string>
using namespace std;

#ifndef SONG_H
#define SONG_H

class Song{
 public:
  //Name: Song - Default Constructor
  //Precondition: None
  //Postcondition: Creates a default song
  Song();
  //Name: Song - Overloaded Constructor
  //Precondition: Requires title, artist, year and rank
  //Postcondition: Creates a song based on passed parameters
  Song(string title, string artist, int year, int rank );

  //Name: Mutators and Accessors
  //Precondition: None
  //Postcondition: Sets and Gets private member variables
  string getTitle()const; // return title
  string getArtist()const; // return artist
  int getYear()const; // return year
  int getRank()const; // return rank (1-100 from that year) 
  void setTitle(string title);
  void setArtist(string artist);
  void setYear(int year);
  void setRank(int rank);
 private:
  string m_title; //Title of song
  string m_artist; //Artist of song
  int m_year; //Year of release
  int m_rank; //Rank 1-100 from that year
};

#endif
