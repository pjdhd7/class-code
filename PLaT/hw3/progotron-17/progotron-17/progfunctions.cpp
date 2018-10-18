#include "progparser.h"

//FunctionDeclaration { FunctionDeclaration }
void FunctionSequence(istringstream& ss, char* input, string& temp) {
	FunctionDeclaration(ss, input, temp);
	for (int i = 0; i < limit; i++)
		input[i] == NULL;

	while (cin.getline(input, limit, '\n') && is_correct) {
		if (input[0] != '\0') {
			ss.clear();
			ss.str(input);
			FunctionDeclaration(ss, input, temp);
		}
	}
	return;
}

//FUNC identifier ( [ ParamSequence ] ) BEGIN StatementSequence END.
void FunctionDeclaration(istringstream& ss, char* input, string& temp) {
	ss >> temp;
	if (temp == "FUNC") {
		ss >> temp;
		if (!(is_identifier(temp.c_str())) || is_correct == false) {
			is_correct = false;
			return;
		}
		ss >> temp;
		if (temp != "(" || is_correct == false) {
			is_correct = false;
			return;
		}
		ss >> temp;
		if (is_identifier(temp.c_str())) {
			ParamSequence(ss, input, temp);
		}
		if (temp != ")" || is_correct == false) {
			is_correct = false;
			return;
		}
		if (ss >> temp) {
			if (temp != "BEGIN" || is_correct == false) {
				is_correct = false;
				return;
			}
		}
		else {

			/****************/
			cin.getline(input, limit, '\n');
			ss.clear();
			ss.str(input);

			ss >> temp;
			if (temp != "BEGIN" || is_correct == false) {
				is_correct = false;
				return;
			}
			if (ss >> temp || is_correct == false) {
				is_correct = false;
				return;
			}
		}

		/***********/
		cin.getline(input, limit, '\n');
		ss.clear();
		ss.str(input);
		ss >> temp;

		StatementSequence(ss, input, temp);
		if (temp != "END." || is_correct == false) {
			is_correct = false;
			return;
		}
	} else 
		is_correct = false;
	
	return;
}

//identifier  { , identifier }
void ParamSequence(istringstream& ss, char* input, string& temp) {
	ss >> temp;
	while (temp == "," && is_correct) {
		ss >> temp;
		if (!(is_identifier(temp.c_str()))) {
			is_correct = false;
		}
		ss >> temp;
	}
	return;
}

//Statement { Statement }
void StatementSequence(istringstream& ss, char* input, string& temp) {
	Statement(ss, input, temp);
	if(ss>>temp)
		if (temp == "END." || temp == "POOL" || temp == "FI" || temp == "ELSE")
			return;
	while (cin.getline(input, limit, '\n') && is_correct) {
		
		/***********/
		ss.clear();
		ss.str(input);
		ss >> temp;
		if (temp == "END." || temp == "POOL" || temp == "FI" || temp == "ELSE")
			return;
		Statement(ss, input, temp);
	}
	return;
}

//Assignment | PrintStatement | RetStatement | IfStatement | LoopStatement
void Statement(istringstream& ss, char* input, string& temp) {
	if (temp == "LOOP")
		LoopStatement(ss, input, temp);
	else if (temp == "IF")
		IfStatement(ss, input, temp);
	else if (temp == "RET")
		RetStatement(ss, input, temp);
	else if (temp == "PRINT")
		PrintStatement(ss, input, temp);
	else if (is_identifier(temp.c_str()))
		Assignment(ss, input, temp);
	else {
		is_correct = false;
		return;
	}
	return;
}

//LOOP ( Expression ) StatementSequence POOL
void LoopStatement(istringstream& ss, char* input, string& temp) {
	ss >> temp;
	if(temp != "(" || is_correct == false){ 
		is_correct = false;
		return;
	}
	Expression(ss, input, temp);
	if (temp != ")" || is_correct == false) {
		is_correct = false;
		return;
	}

	/***********/
	cin.getline(input, limit, '\n');
	ss.clear();
	ss.str(input);
	ss >> temp;
	StatementSequence(ss, input, temp);

	if(temp != "POOL")
		is_correct = false;

	return;
}

//IF ( Expression ) StatementSequence [ ELSE StatementSequence ] FI
void IfStatement(istringstream& ss, char* input, string& temp) {
	ss >> temp;
	if(temp != "(" || is_correct == false) {
		is_correct = false;
		return;
	}

	Expression(ss, input, temp);

	if (temp != ")" || is_correct == false) {
		is_correct = false;
		return;
	}

	/***********/
	cin.getline(input, limit, '\n');
	ss.clear();
	ss.str(input);
	ss >> temp;
	StatementSequence(ss, input, temp);


	if (temp == "ELSE" && is_correct) {
		cin.getline(input, limit, '\n');
		ss.clear();
		ss.str(input);
		ss >> temp;
		StatementSequence(ss, input, temp);
	}
	else if (temp != "FI")
		is_correct = false;
	return;
}

//RET identifier !
void RetStatement(istringstream& ss, char* input, string& temp) {
	ss >> temp;
	if (!(is_identifier(temp.c_str()))) {
		is_correct = false;
		return;
	}
	ss >> temp;
	if (temp != "!")
		is_correct = false;
	return;
}

//PRINT ( Expression ) !
void PrintStatement(istringstream& ss, char* input, string& temp) {
	ss >> temp;
	if(temp != "(" || is_correct == false) {
		is_correct = false;
		return;
	}
	Expression(ss, input, temp);
	if(temp != ")" || is_correct == false) {
		is_correct = false;
		return;
	}
	ss >> temp;
	if (temp != "!" || is_correct == false) 
		is_correct = false;

	return;
}

//identifier := Expression !
void Assignment(istringstream& ss, char* input, string& temp) {
	ss >> temp;
	if(temp != ":=" || is_correct == false) {
		is_correct = false;
		return;
	}

	Expression(ss, input, temp);

	if (temp != "!")
		is_correct = false;

	return;
}

//integer | decimal | string | identifier | ( Expression ) | ~ Factor
void Factor(istringstream& ss, char* input, string& temp) {
	ss >> temp;
	if (is_integer(temp.c_str()))
		return;
	else if (is_decimal(temp.c_str()))
		return;
	else if (is_string(temp.c_str()))
		return;
	else if (is_identifier(temp.c_str()))
		return;
	else if (temp == "("){
		Expression(ss, input, temp);
		if (temp == ")" && is_correct)
			return;
	}
	else if (temp == "~") {
		Factor(ss, input, temp);
		return;
	}
	is_correct = false;
	return;
}

//Factor { MulOperator Factor }
void Term(istringstream& ss, char* input, string& temp) {
	Factor(ss, input, temp);
	ss >> temp;
	if ((temp == "*" || temp == "/" || temp == "AND") && is_correct) {
		Factor(ss, input, temp);
		ss >> temp;
	}
	return;
}

//Term { AddOperator Term }
void SimpleExpression(istringstream& ss, char* input, string& temp) {
	Term(ss, input, temp);
	if ((temp == "+" || temp == "-" || temp == "OR" || temp == "&") && is_correct)
		Term(ss, input, temp);
	return;
}

//SimpleExpression [ Relation SimpleExpression ]
void Expression(istringstream& ss, char* input, string& temp) {
	SimpleExpression(ss, input, temp);
	if ((temp == "<" || temp == ">" || temp == "=" || temp == "#") && is_correct)
		SimpleExpression(ss, input, temp);
	return;
}