//
//  game_logic.cpp
//  HangmanGame
//
//  Created by Wladimir Pasko on 30.01.22.
//

#include "game_logic.hpp"
#include "helpers.hpp"
#include <vector>

#include <iostream>
using namespace std;


int max_tries = 7;

void start_game(string word){
    string hidden_word;
    char users_letter;
    bool game_finished = false;
    bool word_guessed;
    cout << "Let's start the game" << endl;
    generate_hidden_word(hidden_word, word);
    show_hidden_word(hidden_word);
    display_attemts(max_tries);
    while (game_finished == false) {
        cout << "Type the letter: ";
        cin >> users_letter;
        auto indices = find_letter_index(word, hidden_word, users_letter);
        if (indices.size() > 0){
            open_letters_in_word(word, hidden_word, indices);
        }
        else{
            cout << "You are wrong. ";
            cout << "Your letter is not in the word" << endl;
        }
        max_tries--;
        show_hidden_word(hidden_word);
        display_attemts(max_tries);
        word_guessed = check_word_status(hidden_word);
        if (word_guessed) {
            game_finished = true;
            cout << "You won the game. Congratulations!" << endl;
        }
        else if (max_tries == 0 && word_guessed == false){
            game_finished = true;
            cout << "You lost the game" << endl;
        }
    }
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
