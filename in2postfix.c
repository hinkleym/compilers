/*
 * 	CS450 Lab 1 - Infix to Postfix Expression translator
 * 		Pete Nordquist
 * 			030928
 * 				*/

#include <stdio.h>
#include <stdlib.h>

int lookahead;

main() {
	lookahead = getchar();
	expr();
	putchar( '\n');
}

expr() {
	term();
	while( 1)
	 	if( lookahead == '+') {
					match( '+');
					term();
					putchar( '+');
				} else if( lookahead == '-') {
							match( '-');
							term();
							putchar( '-');
						} else
			break;
}

term() {
	if( isdigit( lookahead)) {
			putchar( lookahead);
			match( lookahead);
		} else
		error();
}

match( t) 
		int t;
{
	if( lookahead == t)
		lookahead = getchar();
	else
		error();
}

error() {
	printf( "syntax error\n");
	exit( 1);
}

