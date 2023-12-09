#include <u.h>
#include <libc.h>
	
int
od_main (int argc, char **argv)
{
    printf("Enter text, ESC to end input.\n");
    char c;
    char *txt;
	txt = malloc(100);
	memset(txt, 0, 100);
    int i = 0;
    // while for reading input
    while(1)
    {
        c = ps2_getc();
        // end input if ESC pressed
        if ((int)c == 27)
        {
            printf("%c", '\n');
            break;
        }
        // remove with backspace
        if (c == '\b')
        {
            if(!i) continue;
            i--;
            txt[i] = 0;
        }
        txt[i] = c;
        i++;
	    printf("%c", c);
    }
    
    // calculate answer
    i = 0;
    int answer, pow;
    char input;
    while (strcmp(txt+i,"\0"))
    {
        input = *(txt+i);
        answer = 0;
        pow = 1;
        for (int mult = 0; input > 0; mult ++)
        {
            answer += (input % 8) * pow;
            input = input / 8;
            pow *= 10;
        }
        i++;
        printf("%d  ", answer);

        // newline after 10 outputs
        if (i%10 == 0) printf("\n");
    }
    // for debug
    // printf("%d\n", argc);
    // printf("%d\n", *cwd);
    
}
