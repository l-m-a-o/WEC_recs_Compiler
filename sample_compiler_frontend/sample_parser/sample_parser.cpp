#include <iostream>
#include "sample_parser.hpp"
#include<vector>
#include <stack>

/*DEFINE FUNCTIONS START*/

DescribedWord::DescribedWord(Word *theAdword, Word *theWord)
{
	/*definition*/
}

void DescribedWord::traverse()
{
	/*definition*/
}

void Noun::traverse()
{
	/*definition*/
}

void Verb::traverse()
{
	/*definition*/
}

void Adword::traverse()
{
	/*definition*/
}

void Sentence::traverse()
{
	/*definition*/
}

/*DEFINE FUNCTIONS END*/


extern int get_token();

/*PARSING FUNCTIONS START*/

Sentence* parse_temp()
{
	Tokens next_token = static_cast<Tokens>(get_token()); 
	Sentence* s;
	std :: vector <Tokens> TokenList ;

	/*definition*/

	//push valid tokens in a list
	
	while ( next_token !=  END ) {
		if (next_token == INVALID ) {
			std :: cout << "Lexical Error found while matching tokens\n" ;
			return s;
		}
		TokenList.push_back(next_token) ;

		next_token = static_cast<Tokens>(get_token());
		
	}
	std :: cout << "\nLexical phase passed.\n\nTokens: " ;


	//syntax analysis, using a stack, some kind of ll(1) ig

	std :: stack <int> st ; st.push(-100)  ; // let -100 be $ character

	int quotes_flag = 0 ; //for quotes 

	//to actually match the grammar
	for ( auto it : TokenList) {
		std :: cout << it << ' ' ;
		switch( st.top() ){
			case -100 :
				switch(it) {
					case STARTWORD :
						//std :: cout << "???" ;
						st.push(it) ;
						break ;
					case WHITESPACE:
						break ;
					default :
						std :: cout << "\nSyntax Error: Sentence can only start with title case word.\n" ;
						return s ;
						break ;
				}
				break;
			
			case WORD:
				switch(it) {
					case STARTWORD:
						std :: cout << "\nSyntax Error: title case word can be only at the beginning of a sentence.\n" ;
						return s ;
						break;
					case STOP:
						while(st.top() != -100){
							if ( st.top() == QUOTES) {
								std :: cout << "\nSyntax Error: Unresolved Quotation\n" ;
								return s ;
							}
							st.pop() ;
						}
						break;
					case QUOTES:
						if (quotes_flag) {
							while ( true) {
								if ( st.top() == -100) {
									std :: cout << "\nCoding error :( \n" ;
									return s ;
								}
								else if ( st.top() == QUOTES) {
									st.pop() ;
									quotes_flag = 0 ;
									break ;
								}
								else st.pop() ;
							}
						}
						else {
							st.push(it) ;
							quotes_flag = 1 ;
						}
						break;
					case WHITESPACE:
						break ;
					default:
						st.push(it) ;
						break;
				}
				break;
			
			case STARTWORD:
				switch( it ) {
					case STARTWORD:
						std :: cout << "\nSyntax Error: title case word can be only at the beginning of a sentence.\n" ;
						return s ;
						break ;
					case STOP:
						while(st.top() != -100){
							if ( st.top() == QUOTES) {
								std :: cout << "\nSyntax Error: Unresolved Quotation.\n" ;
								return s ;
							}
							st.pop() ;
						}
						break;
					case QUOTES:
						st.push(it) ;
						quotes_flag = 1 ;
						break;
					case WHITESPACE:
						break;
					default:
						st.push(it) ;
						break ;
				}
				break;
			
			case STOP:
				//shouldn't happen
				std :: cout << "\nCoding error :( \n" ;
				break;
			
			case COMMA:
				switch (it) {
					case WORD:
						while(st.top() != WORD && st.top() != STARTWORD) st.pop() ;
						st.pop() ; //comma can anyways come only after a word so no error should happen here
						st.push(it) ;
						break ;
					case WHITESPACE:
						break ;
					default:
						std :: cout << "\nSyntax Error: A simple word needs to follow a comma.\n"  ;
						return s ;
						break;
				}
				break;
			
			case HYPHEN:
				switch (it) {
					case WORD:
						while(st.top() != WORD && st.top() != STARTWORD) st.pop() ;
						st.pop() ; //hyphen can anyways come only after a word so no error should happen here
						st.push(it) ;
						break ;
					case WHITESPACE:
						break ;
					default:
						std :: cout << "\nSyntax Error: A simple word needs to follow a hyphen.\n"  ;
						return s ;
						break;
				}			
				break;
			
			case QUOTES:
				switch(it) {
					case STOP:
						std :: cout << "\nSyntax Error: A quotations can't start with punctuation.\n" << it ;
						return s ;
						break ;
					case COMMA:
						std :: cout << "\nSyntax Error: A quotations can't start with punctuation.\n" << it ;
						return s ;
						break ;
					case HYPHEN:
						std :: cout << "\nSyntax Error: A quotations can't start with punctuation.\n" << it ;
						return s ;
						break ;
					case QUOTES :
						std :: cout << "\nSyntax Error: Empty Quotes.\n" << it ;
						return s ;
						break ;
					case WHITESPACE:
						break ;
					default : 
						st.push(it) ;
						break ;
				}	
				break;
			
			case WHITESPACE:
				//shouldn't happen
				std :: cout << "\nCoding error :( \n" ;
				break;
		}
	}

	if ( st.top() != -100) {
		//parsing failed
		std :: cout << "\nSyntax Error: Sentence needs to end with a full stop.\n" ;
	}

	else {
		std :: cout << "\n\nSyntactical phase passed.\n" ;
	}


	
	return s;
}

//more functions here

/*PARSING FUNCTIONS END*/

/*SEMANTIC ANALYSIS START*/

void traverse_temp(Sentence* s)
{
	/*definition*/
}

//more functions here

/*SEMANTIC ANALYSIS END*/