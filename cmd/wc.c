#include <u.h>
#include <libc.h>

#define memsize 1000
void
wc_main(int argc, char **argv)
{
    printf("Enter text, ESC to end input.\n");
    char c;
    char *txt;
    int i = 0;
	txt = malloc(memsize);
	memset(txt, 0, memsize);
    
    // while for reading input
    while(1)
    {
        c = ps2_getc();
        // end input if ESC pressed
        if ((int)c == 27 && i < memsize)
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

    // start counting
    int lines = 1;
    int words = 0;
    int bytes = 0;
    int is_space = 1;
    i = 0;
    while (txt[i] != '\0')
    {
        // break if end of text
        if (txt[i] == '\0')
        {
            break;
        }
        i ++;
        bytes ++;
        
        // remember lines for counting words
        if (txt[i] == '\r' || txt[i] == '\n') 
        {
            lines++;
            is_space = 1;
            continue;
        }
        
        // remember spaces for counting words
        if (txt[i] == ' ')
        {
            is_space = 1;
            continue;
        }
        
        // count words if previouscharacter was space
        if ((is_space == 1) && (txt[i] != ' ') && (txt[i] != '\n')) 
        {
            words++;
            is_space = 0;
        }
    }
    if (bytes == 0) lines == 0;

    // print output without flags
    if (argc == 1)
    {
        printf("number of words: %d\n", words);
        printf("number of lines: %d\n", lines);
        printf("number of bytes: %d\n", bytes);
        return;
    }
    // print output with flags
    i = 1;
    while (i < argc)
    {
        if (!strcmp(argv[i], "-w")) printf("number of words: %d\n", words);
        else if (!strcmp(argv[i], "-l")) printf("number of lines: %d\n", lines);
        else if (!strcmp(argv[i], "-b"))  printf("number of bytes: %d\n", bytes);    
        i++;
    }
}
