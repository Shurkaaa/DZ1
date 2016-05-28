//
//  main.cpp
//  AL_HT_V5
//
//  Created by Alexandr on 08.05.16.
//  Copyright © 2016 Kamenskiy-Dev. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <iterator>
#include "library.h"
#include <assert.h>
#include <fstream>


using namespace std;

int main(int argc, const char * argv[]) {
    
    string text;
    library lib;
    
    cout << "press 'exit' to end program" << endl;
    text = "";
    
    while (text != "exit") {
        cout << "Enter command : " << endl;
        getline(cin, text);
        
        if (text == "exit") {break;}
        else {if (text == "add book") {lib.addBook();} }
        
        
        
        if (text == "create genre") {
            lib.createGengre();
        }
        if (text == "create room") {
            lib.createRoom();
        }
        if (text == "delete book") {
            string nam;
            cout << "enter the book name" << endl;
            cin >> nam;
            lib.deleteBook(nam);
        }
        
        if (text == "delete room") {
            string nam;
            cout << "enter the room name" << endl;
            cin >> nam;
            lib.deleteRoom(nam);
        }
        
        if (text == "download book") {
            lib.downloadBook();
        }
        
        if (text == "merge rooms") {
            string firstRoom, secondRoom;
            cout << "Enter the name of the first room" << endl;
            cin >> firstRoom;
            cout << "Enter the name of the second room" << endl;
            cin >> secondRoom;
            lib.mergerRooms(firstRoom, secondRoom);
        }
        
        if (text == "move the book") {
            string firstRoom, secondRoom, book;
            cout << "Enter the name of the first room" << endl;
            cin >> firstRoom;
            cout << "Enter the name of the second room" << endl;
            cin >> secondRoom;
            cout << "Enter the name of the book" << endl;
            cin >> book;
            lib.moveTheBook(firstRoom, secondRoom, book);
        }
        
        if (text == "open downloaded book") {
            lib.openDownloadedBook();
        }
        
        if (text == "enter all books of exact genre") {
            string nam;
            cout << "Enter the name of the genre" << endl;
            cin >> nam;
            lib.printAllBookOfThisGenre(nam);
        }
        
        if (text == "print all books") {
            lib.printAllBooks();
        }
        
        if (text == "print all digitized books") {
            lib.printAllDigitizedBooks();
        }
        
        if (text == "print all genres") {
            lib.printAllGeners();
        }
        
        if (text == "print book") {
            string nam;
            cout << "Enter the name of the book" << endl;
            cin >> nam;
            lib.printBook(nam);
        }
        
        if (text == "put the book") {
            string book, room;
            cout << "Enter the name of the book" << endl;
            cin >> book;
            cout << "Enter the name of the room" << endl;
            cin >> room;
            lib.putTheBook(book, room);
            
        text = "";
        }
    }
    
    return 0;
}
