//
//  helpers.hpp
//  HangmanGame
//
//  Created by Wladimir Pasko on 30.01.22.
//

#ifndef helpers_hpp
#define helpers_hpp

#include <stdio.h>
#include <string>

using namespace std;

void generate_hidden_word(std::string &hidden_word, const std::string &word);
void display_attemts(int);
int pick_random_number(int,int);
bool check_word_status(string);
string chose_the_word();
vector<int> find_letter_index(string, string&, char);
void open_letters_in_word(string ,string&, vector<int>);
void show_hidden_word(const std::string &hidden_word);


#endif /* helpers_hpp */
