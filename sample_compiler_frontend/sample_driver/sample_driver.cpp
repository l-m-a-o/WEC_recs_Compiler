#include <iostream>
#include <iomanip>

#include "../sample_parser/sample_parser.hpp"

extern int set_input(std::string s);
extern Sentence* parse_temp();
extern void traverse_temp(Sentence* s);

int main()
{
	std::string input;
	std::cout << "INPUT: ";
	std::getline(std::cin, input);

	set_input(input);

	std :: cout << "\nSYMBOL TABLE\n\n" ;
	std :: cout << std :: left << std :: setw(15) << std :: setfill(' ') << "Position";
	std :: cout << std :: left << std :: setw(15) << std :: setfill(' ') << "Token enum";
	std :: cout << std :: left << std :: setw(20) << std :: setfill(' ') << "Token type";
	std :: cout << std :: left << std :: setw(30) << std :: setfill(' ') << "Token Value";
	std :: cout << std :: left << std :: setw(15) << std :: setfill(' ') << "Token length\n";
	std :: cout << "-----------------------------------------------------------------------------------------------\n" ;

	Sentence* s = parse_temp(); //parsing

	traverse_temp(s); //semantic analysis
	return 0;
}