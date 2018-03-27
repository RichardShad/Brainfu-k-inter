#include "Token.cpp"
#include "TokenList.cpp"
#include <string>

TokenList *TokenParser(std::string code){
	TokenList *result = nullptr;
	for(auto curent : code){
		Token *temp = new Token(curent);
		if(temp -> get_value() != Token::Operation::Empty){
			if(result == nullptr)
				result = new TokenList(*temp);
			else
				result -> Insert(new TokenList(*temp));
		}
	}
	return result;
}

