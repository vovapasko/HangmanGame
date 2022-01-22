//
//  main.cpp
//  HangmanGame
//
//  Created by Wladimir Pasko on 14.01.22.
//
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <random>


using namespace std;


void displayGameDetails(int);
string chose_the_word();
void start_game(string);
vector<int> find_letter_index(string, string&, char);
void display_attemts();
void open_letters_in_word(string ,string&, vector<int>);
bool check_word_status(string);
int pick_random_number(int,int);

int max_tries = 7;
int main() {
    string quessed_word;
    
    displayGameDetails(max_tries);
    quessed_word = chose_the_word();
    start_game(quessed_word);
}


void start_game(string word){
    string hidden_word;
    char users_letter;
    bool game_finished = false;
    bool word_guessed;
    cout << "Now let's start guessing. Here is how the word looks like: ";
    for (int i = 0; i < word.size(); i++) {
        hidden_word.insert(i, "-");
    }
    cout << hidden_word << endl;
    display_attemts();
    while (game_finished == false) {
        cout << "Type the letter: ";
        cin >> users_letter;
        cout << users_letter;
        auto indices = find_letter_index(word, hidden_word, users_letter);
        if (indices.size() > 0){
            open_letters_in_word(word, hidden_word, indices);
        }
        else{
            cout << "Your letter is not in the word" << endl;
        }
        max_tries--;
        display_attemts();
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

void display_attemts(){
    cout << "You have " << max_tries << " attempts";
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
    string words[] = {"dog", "parrot", "kitten"};
    int word_index = pick_random_number(0, 3);
    return words[word_index];
}

int pick_random_number(int min, int max){
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(min, max); // define the range
    return distr(gen);
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

