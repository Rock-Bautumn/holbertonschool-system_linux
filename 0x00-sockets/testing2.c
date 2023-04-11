#include <stdio.h>
#include <string.h>


size_t char_occurrences(char *string, char chr)
{
	size_t count = 0, check_pos = 0;

	for (; string[check_pos]; check_pos++)
		if (string[check_pos] == chr)
			count++;

	return (count);
}
/*
int main()
{

    char querystring[]="a=1&b&c=3&d=&meh=5";
    size_t pc=0;
    char *tok;
    char *otok;
    size_t occs;

	occs = char_occurrences(querystring, '&');

    for(tok=strtok(querystring,"&");pc <= occs;tok=strtok(tok,"&")) {
        pc++;
        otok=tok+strlen(tok)+1;
        tok=strtok(tok,"=");
        fprintf(stderr,"param%ld: %s ",pc,tok);
        tok=strtok(NULL,"=");
        fprintf(stderr,"value%ld: %s\n",pc,tok);
        tok=otok;
    };
    return 0;
}
*/
