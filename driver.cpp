/*****************************************
 ** File:    driver.cpp
 ** Project: CMSC 202 Project 5 - UMBC Music Player, Fall 2017
 ** Author:  Jeremy Dixon
 ** User:    Innocent Kironji
 ** Date:    12/01/17
 ** Section: 0107
 ** E-mail:  wambugu1@umbc.edu
 **
 **   This file contains the driver for the Music player
 **   Takes in argument from textfile and creates a MusicPlayer
 **
 **   This file has not been modified from Professor Dixion's
 **    version aside from these comments
 ***********************************************/

#include <iostream>
#include "MusicPlayer.h"
#include "Song.h"

int main (int argc, char* argv[]) {
  string musicFile;
  cout << "Welcome to UMBC Music Player"<<endl;
  if(argc > 1){
    musicFile = argv[1];
  } else{
    cout << "One music files required - try again" << endl;
    cout << "./proj5 p5_music1.txt" << endl;
    return 0;
  }
  MusicPlayer* myMusic = new MusicPlayer(musicFile);
  myMusic->MainMenu();
  delete myMusic;
  return 0;
}
