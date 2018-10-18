%{Name: Peter Dolan

/* ---- PROLOGUE ---- */

%}
%{
#include <iostream>
using namespace std;

int no_lines = 1;
int no_tokens = 0;
%}
		              /* ---- DEFINITIONS ---- */
%option noyywrap
DIGIT		[0-9]
WEB         edu|com|net
IDENT       [a-zA-Z][a-zA-Z0-9]*

%%  		              /* ---- REGULAR EXPRESSIONS ---- */

[ \t]           ;
%.*                 ;
\n              { no_lines++; }

[+\-]?[0-9]+\.[0-9]+E[+\-]?[0-9]+  { cout << "#" << no_tokens 
                                              << ": TOKEN: SCICONST   LEXEME: " 
								              << yytext << endl; no_tokens++; }

[+-]?[0-9]+\.[0-9]+        { cout << "#" << no_tokens 
                                 << ": TOKEN: DECCONST   LEXEME: " 
								 << yytext << endl; no_tokens++; }
											  
[-+]?[0-9]+      { cout << "#" << no_tokens << ": TOKEN: INTCONST   LEXEME: " 
                       << yytext << endl; no_tokens++; }		 
											  
[0-9ABCDEF]+H      { cout << "#" << no_tokens << ": TOKEN: HEXCONST   LEXEME: "
						  << yytext << endl; no_tokens++; }
						  
[01]+B				   { cout << "#" << no_tokens 
                          << ": TOKEN: BINCONST   LEXEME: "
						  << yytext << endl; no_tokens++; }
						  
[a-zA-Z][a-zA-Z0-9]*(\.[a-zA-Z][a-zA-Z0-9]*)*\@([a-zA-Z][a-zA-Z0-9]*\.)+{WEB}  { 
                 cout << "#" << no_tokens << ": TOKEN: EMCONST    LEXEME: "
					   << yytext << endl; no_tokens++; }
										
if|then|else|while|end|banana   {cout << "#" << no_tokens 
                                             << ": TOKEN: KEYWORD    LEXEME: " 
				                             << yytext << endl; no_tokens++; }
								   
\".*\"  { cout << "#" << no_tokens << ": TOKEN: STRCONST   LEXEME: " 
                       << yytext << endl; no_tokens++; }
					   
[+\-/&*<>]          {cout << "#" << no_tokens 
                                        << ": TOKEN: OPERATOR   LEXEME: " 
								        << yytext << endl; no_tokens++; }
										
[a-zA-Z][a-zA-Z0-9]*     {cout << "#" << no_tokens 
                               << ": TOKEN: IDENT      LEXEME: " 
				               << yytext << endl; no_tokens++; }
										
[.\"\'!#@^ ]       { cout << "#" << no_tokens 
                               << ": TOKEN: ?          LEXEME: " 
                               << yytext << endl; no_tokens++; }

%%  		              /* ---- EPILOGUE ---- */

	int main()
	{
		yylex();
		cout << no_lines << " lines processed." << endl;
		return 0;
	}

