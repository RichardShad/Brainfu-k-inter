#include <stdio.h>
#include <stack>
#include "Token.cpp"
#include "TokenList.cpp"

void Inter(TokenList* code){
	
	int					Cells[1000];
	int*					ptr = &Cells[0];
	int*					end = ptr + 1000;
	std::stack <TokenList*>			CycleStack;

      	for(TokenList *iterator = code; iterator != nullptr; iterator = iterator -> next){
		switch(iterator -> value.get_value()){
			case Token::Operation::BrOpen: {
				CycleStack.push(iterator);
				break;
			}
			
			case Token::Operation::BrClose: {
					if(!CycleStack.empty()){
						if(*ptr != 0)
							iterator = CycleStack.top();
							CycleStack.pop();
					}
					break;
				}
				
			case Token::Operation::Right: {
				if(++ptr >= end)
					ptr = &Cells[0];
				break;
			}
			
			case Token::Operation::Left: {
				if(--ptr < &Cells[0])
					ptr = (end - 1);
				break;
			}
			case Token::Operation::Plus: {
				(*ptr)++;
				break;
			}

			case Token::Operation::Minus: {
				(*ptr)--;
				break;
			}
			
			case Token::Operation::Comma: {
				*ptr = getchar();
				break;
			}
			
			case Token::Operation::Dot:{
				putchar(*ptr);
				break;
			}
		}
	}
}
