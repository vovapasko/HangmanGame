//
//  helpers.cpp
//  HangmanGame
//
//  Created by Wladimir Pasko on 30.01.22.
//

#include "helpers.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>

using namespace std;

void generate_hidden_word(std::string &hidden_word, const std::string &word) {
    for (int i = 0; i < word.size(); i++) {
        hidden_word.insert(i, "-");
    }
}

void show_hidden_word(const std::string &hidden_word) {
    cout << "Here is how the word looks like: ";
    cout << hidden_word << endl;
}

bool check_word_status(string word){
    for(char c : word){
        if (c == '-'){
            return false;
        }
    }
    return true;
    
}

void open_letters_in_word(string origin_word, string &hidden_word, vector<int> indeces){
    for (int index: indeces){
        hidden_word[index] = origin_word[index];
    }
}

void display_attemts(int max_tries){
    cout << "You have " << max_tries << " attempts" << endl;
}

vector<int> find_letter_index(string origin_word, string& hidden_word, char users_letter){
    vector<int> letter_indicies;
    for (int i = 0; i < origin_word.size(); i++){
        if (origin_word.at(i) == users_letter){
            letter_indicies.push_back(i);
        }
    }
    return letter_indicies;
}


string chose_the_word(){
    string word_bank[] = {"dog", "parrot", "kitten"};
    int word_index = pick_random_number(0, 3);
    return word_bank[word_index];
}

int pick_random_number(int min, int max){
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(min, max); // define the range
    return distr(gen);
}

