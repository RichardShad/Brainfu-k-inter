#include <stdio.h>
#include <stack>
#include "Token.cpp"
#include "TokenList.cpp"

void Inter(TokenList* code){
	
	int					Cells[1000];
	int*					ptr = &Cells[0];
	int*					end = ptr + 1000;
	std::stack <TokenList*>			CycleStack;

      	for(TokenList *iterator; iterator != nullptr; iterator = iterator -> next){
		if(iterator -> value.get_value() == Token::Operation::BrOpen)
			CycleStack.push(iterator);
		
		if(iterator -> value.get_value() == Token::Operation::BrClose){
			if(*ptr != 0)
				iterator = CycleStack.top();
			CycleStack.pop();
		}
		
		if(iterator -> value.get_value() == Token::Operation::Right)
			if(++ptr >= end)
				ptr = &Cells[0];
		
		if(iterator -> value.get_value() == Token::Operation::Left)
			if(--ptr < &Cells[0])
				ptr = (end - 1);
		
		if(iterator -> value.get_value() == Token::Operation::Plus)
			(*ptr)++;
		
		if(iterator -> value.get_value() == Token::Operation::Minus)
			(*ptr)--;
		
		if(iterator -> value.get_value() == Token::Operation::Comma)
			*ptr = getchar();
		
		if(iterator -> value.get_value() == Token::Operation::Dot)
			putchar(*ptr);
	}
}
