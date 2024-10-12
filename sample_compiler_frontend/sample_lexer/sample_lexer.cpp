#include <string>
#include<iostream>
#include<map>
#include<string>
#include <iomanip>

#include "sample_lexer.hpp"

std :: map <int, std :: string> TokenMap {

	//tokens to string map for symbol table
	{INVALID ,"INVALID" }, 
	{END, "END"}, 
	{WORD , "WORD" },
	{STARTWORD , "STARTWORD" },
	{STOP , "STOP" },
	{COMMA , "COMMA" } ,
	{HYPHEN , "HYPHEN" },
	{QUOTES, "QUOTES"} ,
	{WHITESPACE , "WHITESPACE" }
} ;

static std::string input;

int set_input(std::string s)
{
	input = s;
	return 0;
}



int match_token(/*pass token data by reference*/std::string& token_data, int pos) {

	//ukw, I'm just gonna use ifelse to match tokens like a "true programmer"
	//I mean dfa n all too much
	if (token_data == ".") {
		return STOP ;
	}
	else if (token_data == ",") {
		return COMMA ;
	}
	else if (token_data == "-") {
		return HYPHEN ;
	}
	else if (token_data == "\"" ) {
		return QUOTES ;
	}
	//for matching whitespaces just match it as soon as you detect one, I mean why not.
	//In essence, I define the whitespace token to be one char long
	else if (token_data==" " || token_data == "\t" ) {
		return WHITESPACE ;
	}
	//now it has to be a word ig
	//ok  now i realise why bad coding sucks
	else if (pos == input.size() 
	|| input[pos] == '.' 
	|| input[pos] == ',' 
	|| input[pos] == '-'
	|| input[pos] == '"'
	|| input[pos] == ' '
	|| input[pos] == '\n'
	|| token_data.size() >= 26) {
		if ( token_data.size() < 3) return -1 ; //invlid token ( only case ig, hit me up if you want me to prove it)
		else if ( token_data[0] >= 65 && token_data[0] <= 90) return STARTWORD ;
		else return WORD ; //I'm pretty sure this will work, again I cn prove it if y'all want
	}

	else return 0 ; //still matching the word

}



int get_token()
{
	static int pos = 0;
	std::string token_data = "";

	//EOF
	if ( pos == input.size()) return 0 ;

	
	std :: cout << std :: left << std :: setw(15) << std :: setfill(' ') << pos ;
	while(/*condition to continue matching*/ pos < input.size())
	{
		//add char to current token data
		token_data.push_back(input[pos]) ;
		pos++;

		// match a token
		//'match_token' returns 0 if still matching and -1 if invalid
		int token_matched = match_token(token_data, pos) ; 

		// if match succeeds, return token type
		if (token_matched) {
			std :: cout << std :: left << std :: setw(15) << std :: setfill(' ') << token_matched;
			std :: cout << std :: left << std :: setw(20) << std :: setfill(' ') << TokenMap[token_matched];
    		std :: cout << std :: left << std :: setw(30) << std :: setfill(' ') << token_data;
    		std :: cout << std :: left << std :: setw(15) << std :: setfill(' ') << token_data.length();
    		std :: cout << '\n' ;
			return token_matched ;
		}
		else continue; //continues if still matching word
	}

	//other logic

	//match failed, return -1
	return -1; 
}

