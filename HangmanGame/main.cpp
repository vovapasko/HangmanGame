//
//  main.cpp
//  HangmanGame
//
//  Created by Wladimir Pasko on 14.01.22.
//
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;


void displayGameDetails(int);
void chose_the_word(string&);
void start_game(string);

int main() {
    int max_tries = 7;
    string quessed_word;
    
    displayGameDetails(max_tries);
    chose_the_word(quessed_word);
    start_game(quessed_word);
}

void start_game(string word){
    string hidden_word;
    for (int i = 0; i < word.size(); i++) {
        hidden_word.insert(i, "-");
    }
    cout << hidden_word << endl;
}
void chose_the_word(string &word){
    bool word_chosing_flag = true;
    string users_choice;
    do {
        cout << "Now let the first player to chose the word" << endl;
        cin >> word;
        cout << "You choose the word - " << word << endl;
        cout << "If you want to set the word again, type 'n' in the console. Otherwise type something else and we'll play further" << endl;
        cin >> users_choice;
        if (users_choice != "n"){
            word_chosing_flag = false;
        }
    } while (word_chosing_flag);
    
}
void displayGameDetails(int maxTries){
    cout << "\n"
    "        .-------------------------------------------------------------------------------.\n"
    "        |      _      _                                                                  |\n"
    "        |     | |    | |   __ _    _ __      __ _        /\\/\\      __ _    _ __          |\n"
    "        |     | |----| |  / _  |  |  _ \\    / _` |      /    \\    / _  |  |  _  \\        |\n"
    "        |     | |----| | | (_| |  | | | |  | (_| |     / /\\/\\ |  | (_| |  | | | |        |\n"
    "        |     |_|    |_|  \\_ _ |  |_| |_|   \\__, |     \\/    \\/   \\_ _ |  |_| |_|        |\n"
    "        |                                    |___/                                       |\n"
    "        .--------------------------------------------------------------------------------.\n";

    cout << "The purpose of this game is to guess an animal name, secretly chosen by the application\n\n";
    cout << "You have to guess one letter at a time and you can have " << maxTries << " wrong attempts\n\n";
    cout << "Enter a lower-case letter and don't forget to enter key after each guess\n\n";
    cout << "Let's play the game!\n\n";
}

