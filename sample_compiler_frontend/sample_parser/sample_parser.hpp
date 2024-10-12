#pragma once

#include <string>

#include "../sample_lexer/sample_lexer.hpp"

class Sentence;
class Word;
class DescribedWord;
class Noun;
class Verb;
class Adword;

class Word
{
public:
	virtual void traverse() {};
	/*other methods*/

private:
	/*other members*/
};

class DescribedWord : public Word
{
public:
	DescribedWord(Word* theAdword, Word* theWord);
	void traverse();
	/*other methods*/

private:
	Word* theAdword;
	Word* theWord;
	/*other members*/
};

class Noun : public Word
{
public:
	Noun(std::string s) : data(s) {}
	void traverse();
	/*other methods*/

private:
	std::string data;
	/*other members*/
};

class Verb : public Word
{
public:
	Verb(std::string s) : data(s) {}
	void traverse();
	/*other methods*/

private:
	std::string data;
	/*other members*/
};

class Adword : public Word
{
	public:
	Adword(std::string s) : data(s) {}
	void traverse();
	/*other methods*/

private:
	std::string data;
	/*other members*/
};

class Sentence
{
public:
	Sentence(Word* noun1, Word* verb, Word* noun2) {}
	Sentence(Word* noun, Word* verb) {}
	void traverse();
	/*other methods*/

private:
	Word* noun1;
	Word* verb;
	Word* noun2;
	/*other members*/
};