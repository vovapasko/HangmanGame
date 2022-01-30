//
//  main.cpp
//  HangmanGame
//
//  Created by Wladimir Pasko on 14.01.22.
//
#include <iostream>
#include <string>
#include <vector>
#include "game_logic.hpp"
#include "helpers.hpp"

using namespace std;


int main() {
    // TODO: Replace max_tries below on somehow configurated option
    int max_tries = 7;
    displayGameDetails(max_tries);

    string quessed_word;
    quessed_word = chose_the_word();
    
    start_game(quessed_word);
}

