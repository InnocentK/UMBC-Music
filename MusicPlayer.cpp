/*****************************************
 ** File:    MusicPlayer.cpp
 ** Project: CMSC 202 Project 5 - UMBC Music Player, Fall 2017
 ** Author:  Innocent Kironji
 ** Date:    12/01/17
 ** Section: 0107
 ** E-mail:  wambugu1@umbc.edu
 **
 **   This file contains the implementation of the MusicPlayer class
 **
 ***********************************************/
#include "MusicPlayer.h"

const int MIN_YEAR = 1983;
const int MAX_YEAR = 2013;
const int MAX_RANK = 3100;
const int MIN_RANK = 1;
const int LOWEST_ANNUAL_RANK = 100;
const int MAX_ANNUAL_SONGS = 99;
const char FILE_DELIM = ',';

// for initilizing variables
const string EMPTY_STR = "";
const int EMPTY_INT = 0;
const char EMPTY_CHAR = '\0'; 

// MusicPlayer - Default Constructor
// Creates a new MusicPlayer
MusicPlayer::MusicPlayer(){ 

  // Initilizes songCatalog with empty/null values
  for(vector<Song*>::iterator it = m_songCatalog.begin(); 
      it != m_songCatalog.end(); ++it)
    *it = NULL;
}

// MusicPlayer - Overloaded Constructor
// Creates a new MusicPlayer and passes the music filename
MusicPlayer::MusicPlayer(string filename){

  LoadCatalog(filename);
}

// ~MusicPlayer - Destructor
// Destroys MusicPlayer
MusicPlayer::~MusicPlayer(){

  // Itterates through songCatalog and deletes values one by one
  for(vector<Song*>::iterator it = m_songCatalog.begin(); 
      it != m_songCatalog.end(); ++it){
    delete *it;
    *it = NULL;
  }
}

// LoadCatalog(string filename)
// Loads the file into the m_songCatalog (as songs)
void MusicPlayer::LoadCatalog(string filename){
  
  string title = EMPTY_STR; 
  string artist = EMPTY_STR;
  int year = EMPTY_INT;
  int rank = EMPTY_INT;
  char comma = EMPTY_CHAR;
  ifstream songStream( filename.c_str() );

  // Checks if file opened properly
  if (songStream.is_open()){

    // Iterates through list and saves song info
    while (songStream >> rank) {

      // Deals with the comma that follows the rank
      songStream >> comma;

      // Sets other variables for the song
      getline(songStream, title, FILE_DELIM);
      getline(songStream, artist, FILE_DELIM);
      songStream >> year;

      // Updates rank to match year
      rank = rank + ( (year - MIN_YEAR) * LOWEST_ANNUAL_RANK );

      // Fills vector with all songs in catalog
      Song *temp = new Song(title, artist, year, rank);
      m_songCatalog.push_back(temp);
    }
  }
  // When file does not open properly
  else
    cout << "[!!!!] Unable to open the file" << endl;
  return;
}

// MainMenu
// Manages the application and the menu
void MusicPlayer::MainMenu(){

  int choice = 0;
  enum menuOptions {DISPLAY_SONGS, ADD_SONG, DISPLAY_PLAYLIST, QUIT}; 

  // Keeps running until user decides to quit
  do{
    cout << endl << "What would you like to do?" << endl;
    cout << "1. Display Songs by Year" << endl;
    cout << "2. Add Song" << endl;
    cout << "3. Display Playlist" << endl;
    cout << "4. Quit\n";
    cin >> choice;

    // Choice must fall between 0-3 (to follow with the enum)
    choice--;

    // Manages functions calls depending on user's choice
    switch(choice)
      {
      // User wnats to display songs of a specific year
      case DISPLAY_SONGS:
	DisplaySongs();
	break;

      // User wants to add a song to their playlist
      case ADD_SONG:
	AddSong();
	break;

      // User wants to view their current playlist
      case DISPLAY_PLAYLIST:
	DisplayPlaylist();
	break;

      // User decides to quit program
      case QUIT:
	cout << "Thank you for using the UMBC Music Player" << endl;
	break;

      // Validates user input
      default:
	cout << "You did not enter a proper choice." << endl;
      }
  }while (choice != QUIT);
  return;
}

// DisplaySongs
// Lists all songs (numbered) for that year
void MusicPlayer::DisplaySongs(){

  int year = 0;

  // Validates the year the user wants to display
  do{
    cout << "Which year would you like to display? (1983-2013)\n";
    cin >> year;
  } while( (year < MIN_YEAR) || (year > MAX_YEAR) );

  // Calculating the top and lowest ranking songs in the year chosen
  const int RANK_1 = (year - MIN_YEAR) * LOWEST_ANNUAL_RANK;
  const int RANK_100 = RANK_1 + MAX_ANNUAL_SONGS;

  cout << "******" << year << "******" << endl;

  // Itterates through chosen year in songCatalog and prints info
  for (int i = RANK_1; i <= RANK_100; i++){
    cout << (*m_songCatalog.at(i)).getRank() << ". " 
	 << (*m_songCatalog.at(i)).getTitle() << " by " 
	 << (*m_songCatalog.at(i)).getArtist() << endl;
  }
  return;
}

// AddSong
// Displays the current list and adds a song (by year) to the m_playList
void MusicPlayer::AddSong(){

  DisplayPlaylist();
  int songChoice = 0;
  cout << "Choose the song you would like to add to the playlist." << endl;
  DisplaySongs();

  // Validates user's song choice
  while( (songChoice < MIN_RANK) || (songChoice > MAX_RANK) ){ 
    cout << "\nEnter the number of the song you would like to add (1-3100):\n";
    cin >> songChoice;
  }

  // Adds song to playlist
  m_playList.enqueue(*m_songCatalog.at(songChoice - MIN_RANK));
}

// DisplayPlaylist
// Displays the playlist
void MusicPlayer::DisplayPlaylist(){

  // When playlist has yet to be started
  if( m_playList.isEmpty() )
    cout << "***Current Playlist is Empty***" << endl;

  // When playlist has been given previous elements
  else{
    cout << endl << "*****Current Playlist*****" << endl;

    // Itterates through playlist printining song info
    for(int i = 0; i < m_playList.size(); i++){
      cout << i + MIN_RANK << ". " << m_playList[i].getTitle() << " by " 
	   << m_playList[i].getArtist() << " from " 
	   << m_playList[i].getYear() << endl;
    }
  }
}
