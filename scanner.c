
/*Definitions int , float, hexadecimal and octal (binary)*/
%{
#include <stdio.h>
#include <stdlib.h>
%}
DIGIT    	[0-9]
BEGIN_OF_SENTENCE ['.'-{DIGIT}]
END_OF_SENTENCE	[\n|' '|'	']	


OCTAL 				[0][0-8]+{END_OF_SENTENCE}
HEXADECIMAL 		[0][x]({DIGIT}+|[a-eA-E]+)+{END_OF_SENTENCE}     
INTEGER 	^[1-9]+{DIGIT}*|[0]{END_OF_SENTENCE} 
FLOATING 	{DIGIT}+"."{DIGIT}+{END_OF_SENTENCE}

/*EOF			^[\n]*/



/*Rules*/
%%

{HEXADECIMAL}		printf("It's a hexadecimal!\n");
{INTEGER}   printf("It's an integer!\n");/*Keep atoi function. May try a define :)*/
{OCTAL}		printf("It's a octal!\n");
{FLOATING}	printf("It's a float!\n");
<<EOF>>		exit(00);

%%

/*User code*/
void main()
{
	int val, total = 0, n = 0;
	while ( (val = yylex()) > 0 ) { /*Put EOF in future*/
		/*total += val;
		n++;*/

		/*switch(val)
		{
			case DIGIT:
				printf("It's an integer!\n");
				break;

			case FLOATING:
				printf("It's a floating number!\n");
				break;
		}*/


	}
	/*if (n > 0) printf("ave = %d\n", total/n);*/
}

/*Compile: 
			flex FILE_NAME.c

			gcc -o OUT_NAME lex.yy.c -lfl

*/