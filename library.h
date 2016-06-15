//
//  library.h
//  AL_HT_V5
//
//  Created by Alexandr on 09.05.16.
//  Copyright © 2016 Kamenskiy-Dev. All rights reserved.
//

#ifndef library_h
#define library_h


#endif /* library_h */


#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <iterator>
#include <assert.h>
#include <fstream>


using namespace std;



class library;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////BOOK/////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

class book {
private:
    string text, name;
    bool digital = false;
    unsigned long index;
public:
    friend class library;
    
    book() {};
    
    void setText(string t)  {t = text;}
    void setName(string t)  {t = name;}
    void setIndex(unsigned long t)  {t = index;}
    
    bool getDigitizedOfBook()  {return digital;}
    string getText()  {return text;}
    string getName()  {return name;}
    unsigned long getIndex()  {return index;}
    
    /*
    void digitize()
    {
        if (digital == false) {
            digital = true;
        } else {
            cout << "The book is already digitized!" << endl;
        }
    }
    */
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////GENRE//////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////


class genre {
private:
    string name, books;
    uint32_t index;
public:
    friend class library;
    
    genre()  {books = "";}
    
    void addBooks(uint32_t num)  {books += to_string(num);}
    void setName(string nam)  {name = nam;}
    void setIndex(uint32_t ind)  {index = ind;}
    
    string getBooks()  {return books;}
    string getName()  {return name;}
    uint32_t getIndex()  {return index;}
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////ROOM///////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////


class room {
private:
    string books, name;
    uint32_t index;
public:
    friend class library;
    
    room()  {books = "";}
    
    void eraseBook(uint32_t book)
    {
        unsigned int len, pos;
        pos = books.find(book);
        len = to_string(book).length();
        books.erase(pos, len);
    }
    
    void addBooks(uint32_t num)  {books += to_string(num);}
    void addBooks(string num)  {books += num;}
    void setName(string nam)  {name = nam;}
    void setIndex(uint32_t ind)  {index = ind;}
    
    string getBooks()  {return books;}
    string getName()  {return name;}
    uint32_t getIndex()  {return index;}
    
};


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////LIBRARY////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////


class library {
private:
    vector<book> books;
    vector<genre> genres;
    vector<room> rooms;
    string downloadedBook = "***No book is downloaded***";
    ofstream history;
    
public:
    library() // add first room and history
    {
        rooms.resize(1);
        rooms[0].setIndex(0);
        rooms[0].setName("main");
        
        genres.resize(1);
        genres[0].setIndex(0);
        genres[0].setName("main");
        
        
        history.open("history.txt");
    }
    
    ~library()
    {
        history.close();
    }
    
///////////////////////////////// book methods /////////////////////////////////
    
    int findBook(string nam) // return "-1" if there is no books with the name "nam"
    {
        int ind = -1;
        for (uint32_t i = 0; i < books.size(); i++) {
            if (books[i].getName() == nam) {
                ind = i;
                break;
            }
        }
        
        history << "find Book" << endl;
        
        return ind;
    }
    
    void addBook()
    {
        string S;
        int i, j;
        
        books.resize(books.size() + 1);
        
        cout << "Enter the book name" << endl; // set book name
        cin >> S;
        books[books.size()].setName(S);
        
        cout << "Write a book :)" << endl; // set a text
        cin >> S;
        books[books.size()].setText(S);
        
        books[books.size()].digital = false; // the book is not digitized
        
        books[books.size()].setIndex(books.size()); // set book index
        
        cout << "Enter a room name to put there a book" << endl;
        cin >> S;
        i = findRoom(S);
        
        if (i < 0) {
            throw "There is no such rooms";
        }
        rooms[i].addBooks(i);
        
        /*if (i >= 0) {
            rooms[i].addBooks(i);
        } else {
            cout << "There is no such rooms" << endl;
            books.erase(books.end());
        }*/
        
        j = i;
        cout << "Enter a genre" << endl;
        cin >> S;
        i = findGenre(S);
        
        
        
        if (i < 0) {
            throw "There is no such";
        }
        genres[i].addBooks(i);
        
        /*if ((i >= 0) && (j >= 0)) {
            genres[i].addBooks(i);
        } else {
            if (j >= 0) {
                cout << "There is no such" << endl;
                books.erase(books.end());
            }
        }
        */
        
        history << "add book" << endl;
        
    }
    
    void deleteBook(string nam)
    {
        int i;
        i = findBook(nam);
        
        if (i < 0) {
            throw "There is no books named like that";
        }
        
        books.erase(books.begin() + i); // deleting element
        for (i ; i < books.size(); i++) // decrement index
        {
            books[i].setIndex(books[i].getIndex() - 1);
        }

        /*if (i >= 0) {
            books.erase(books.begin() + i); // deleting element
            for (i ; i < books.size(); i++) // decrement index
            {
                books[i].setIndex(books[i].getIndex() - 1);
            }
        } else {
            cout << "There is no books named " << nam << endl;
        }*/
        
        history << "delete Book" << endl;
    }
    
    void printBook(string nam)
    {
        int i;
        i = findBook(nam);
        
        if (i < 0) {
            throw "There is no books named like that";
        }
        cout << books[i].getText() << endl;
        
        /*if (i >= 0) {
            cout << books[i].getText() << endl;
        } else {
            cout << "There is no books named " << nam << endl;
        }*/
        
        history << "print Book" << endl;
    }
    
    void downloadBook()
    {
        string nam;
        bool err = false;
        cout << "Enter the book name" << endl;
        cin >> nam;
        for (uint32_t i = 0; i < books.size(); i++) {
            if (books[i].getName() == nam) {
                err = true;
                downloadedBook = books[i].getText();
                break;
            }
        }
        
        if (err == false) {
            throw "There is no books named like that";
        }
        
        /*if (err == true) {
            cout << "The book is Downloaded" << endl;
        } else {
            cout << "There is no books named " << nam << endl;
        }*/
        
        history << "download Book" << endl;
    }
    
    void printAllBooks()
    {
        for (int i = 0; i < books.size(); i++) {
            cout << books[i].getName() << endl;
        }
        
        history << "print all books" << endl;
    }
    
    void openDownloadedBook()
    {
        cout << downloadedBook << endl;
        
        history << "open downloaded Book" << endl;
    }
    
    void printAllDigitizedBooks()
    {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].getDigitizedOfBook() == true) {
                cout << books[i].getName();
            }
        }
        
        history << "print All Digitized Books" << endl;
    }
    
///////////////////////////////// genre methods /////////////////////////////////
    
    void createGengre()
    {
        string G;
        genres.resize(genres.size() + 1);
        cout << "Enter a genre name" << endl;
        cin >> G;
        genres[genres.size()].setName(G);
        
        history << "create genere" << endl;
        
    }
    
    int findGenre(string nam) // return "-1" if there is no genres named "nam"
    {
        int ind = -1;
        for (uint32_t i = 0; i < genres.size(); i++) {
            if (genres[i].getName() == nam) {
                ind = i;
            }
        }
        history << "find genere" << endl;
        
        return ind;
    }
    
    void assignGenre(string nameOfBook, string nam)
    {
        int i, j;
        i = findGenre(nam);
        j = findBook(nameOfBook);
        
        if ((i < 0) || (j < 0)) {
            throw "There is no such genres or books";
        }
        genres[i].addBooks(j);
        
        /*if ((i >= 0) && (j >= 0)) {
            genres[i].addBooks(j);
        } else {
            cout << "There is no such genres or books" << endl;
        }*/
        
        history << "assign genere" << endl;
    }
    
    void printAllGeners()
    {
        for (int i = 0; i < genres.size(); i++) {
            cout << genres[i].getName() << endl;
        }
        
        history << "print all generes" << endl;
    }
    
    void printAllBookOfThisGenre(string nam)
    {
        int i = findGenre(nam);
        
        if ((i < 0) || (genres[i].getBooks() == "")) {
            throw "There is no such genre of this genre is empty";
        }
        for (int j = 0; j < genres[i].getBooks().length(); i++) {
            cout << books[(genres[i].getBooks()).length()].getName() << endl;
        }
        
        /*if ((i >= 0) && (genres[i].getBooks() != "")) {
            for (int j = 0; j < genres[i].getBooks().length(); i++) {
                cout << books[(genres[i].getBooks()).length()].getName() << endl;
            }
        } else {
            cout << "There is no such genre of this genre is empty" << endl;
        };*/
        
        history << "print All Book Of This Genre" << endl;
    }

    
///////////////////////////////// room methods /////////////////////////////////
    
    void createRoom()
    {
        string R;
        rooms.resize(genres.size() + 1);
        cout << "Enter a room name" << endl;
        cin >> R;
        rooms[rooms.size()].setName(R);
        rooms[rooms.size()].setIndex(rooms.size());
        
        history << "create room" << endl;
    }
    
    int findRoom(string nam) // return "-1" if there is no genres named "nam"
    {
        int ind = -1;
        for (uint32_t i = 0; i < rooms.size(); i++) {
            if (rooms[i].getName() == nam) {
                ind = i;
            }
        }
        
        history << "find room" << endl;
        return ind;
    }
    
    void deleteRoom(string nam)
    {
        int i;
        i = findRoom(nam);
        
        if (i < 0) {
            throw "There is no books named ";
        }
        rooms.erase(rooms.begin() + i); // deleting element
        for (i ; i < rooms.size(); i++) {rooms[i].setIndex(rooms[i].getIndex() - 1);} // decrement index
        
        /*if (i >= 0) {
            rooms.erase(rooms.begin() + i); // deleting element
            for (i ; i < rooms.size(); i++) {rooms[i].setIndex(rooms[i].getIndex() - 1);} // decrement index
        } else {
            cout << "There is no books named " << nam << endl;
        }*/
        
        history << "delete room" << endl;
    }
    
    void putTheBook(string nameOfBook, string nameOfRoom)
    {
        int i, j;
        i = findRoom(nameOfRoom);
        j = findBook(nameOfBook);
        
        if ((i < 0) || (j < 0)) {
            throw "There is no such rooms or books";
        }
        rooms[i].addBooks(j);
        
        /*if ((i >= 0) && (j >= 0)) {
            rooms[i].addBooks(j);
        } else {
            cout << "There is no such rooms or books" << endl;
        }*/
        
        history << "put the book" << endl;
    }
    
    void moveTheBook(string outRoom, string inRoom, string book)
    {
        int i, j, k;
        i = findRoom(outRoom);
        j = findRoom(inRoom);
        k = findBook(book);
        
        if ((i < 0) || (j < 0) || (k < 0)) {
            throw "There is no such rooms or books";
        }
        rooms[i].eraseBook(k);
        rooms[j].addBooks(k);
        
        /*if ((i >= 0) && (j >= 0) && (k >= 0)) {
            rooms[i].eraseBook(k);
            rooms[j].addBooks(k);
        } else {
            cout << "There is no such rooms or books" << endl;
        }*/
        
        history << "move the book" << endl;
    }
    
    void mergerRooms(string firstRoom, string secondRoom)
    {
        int i, j;
        i = findRoom(firstRoom);
        j = findRoom(secondRoom);
        rooms[i].addBooks(rooms[j].getBooks());
        deleteRoom(secondRoom);
        
        history << "merge rooms" << endl;
    }
};
