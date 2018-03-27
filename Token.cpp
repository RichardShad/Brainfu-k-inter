#ifndef __TOKEN__
#define __TOKEN__


class Token{
	public:
		enum class Operation{Plus, Minus, Left, Right,
					BrOpen, BrClose, Dot, Comma,
						Empty};
		Operation get_value(){
			return value;
		}
		Token(){
			value = Operation::Empty;
		}
		Token(char operation){
			switch(operation){
				case '+':
					value = Operation::Plus;
					break;

				case '-':
					value = Operation::Minus;
					break;

				case '[':
					value = Operation::BrOpen;
					break;

				case ']':
					value = Operation::BrClose;
					break;
			
				case '>':
					value = Operation::Right;
					break;

				case '<':
					value = Operation::Left;
					break;

				case '.':
					value = Operation::Dot;
					break;

				case ',':
					value = Operation::Comma;
					break;

				default:
					value = Operation::Empty;
					break;
			};
		}

	private:
		Operation value;

};

#endif
