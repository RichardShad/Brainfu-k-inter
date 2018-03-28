#include <stdio.h>
#include <stack>
#include "Token.cpp"
#include "TokenList.cpp"

void Inter(TokenList* code){
	
	char					Cells[1000] = {0};
	char*					ptr = &Cells[0];
	char*					end = ptr + 1000;
	bool					CycleFlag = false;
	std::stack <TokenList*>			CycleStack;

      	for(TokenList *iterator = code; iterator != nullptr;){
		CycleFlag = false;
		switch(iterator -> value.get_value()){
			case Token::Operation::BrOpen: {
				CycleStack.push(iterator);
				break;
			}
			
			case Token::Operation::BrClose: {
					if(!CycleStack.empty()){
						if((*ptr) != 0)
							iterator = CycleStack.top();
							CycleStack.pop();
							CycleFlag = true;
					}
					break;
			}
				
			case Token::Operation::Right: {
				if((++ptr) >= end)
					ptr = &Cells[0];
				break;
			}
			
			case Token::Operation::Left: {
				if((--ptr) < &Cells[0])
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
				(*ptr) = getchar();
				break;
			}
			
			case Token::Operation::Dot:{
				putchar(*ptr);
				break;
			}
		}
		if(!CycleFlag){
			iterator = iterator -> next;
		}
	}
	delete code;
}
