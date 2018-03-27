#ifndef __TOKEN_LIST__
#define __TOKEN_LIST__

#include "Token.cpp"

struct TokenList{

	TokenList 	*next;
	Token		value;

	TokenList():
		next(nullptr)
	{}

	TokenList(Token op){
		next = nullptr;
		value = op;
	}

	~TokenList(){
		delete next;
	}

	void Insert(TokenList *element){
		if(next == nullptr)
			next = element;
		else
			next -> Insert(element);
	}
};

#endif
