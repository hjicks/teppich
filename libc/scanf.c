#include <u.h>
#include <libc.h>

#include <vga.h>
#include <ps2.h>
#include <mem.h>

char*
get_char()
{
    int i = 0;
    char *buff = malloc(10), c;
    while (1 == 1)
    {
		c = ps2_getc();
		vga_putc(c);
        if (c != '\r')
        {
            buff[i] = c;
            i++;
        }
        else break;
    }
    return buff; 
}

int
scanf(char *str, ...)
{
    va_list ap;
    va_start(ap, str);

    int count = 0;
    char *buffer, *temp;

    while (*str != '\0')
    {
        if (*str == '%')
        {
            buffer = get_char();
            str++;
            switch(*str)
            {
                case 'c':
                    *va_arg(ap, char*) = buffer[0];
                    count++;
                    break;
                case 's':
                    *va_arg(ap, char**) = buffer;
                    count++;
                    break;
                case 'd':
                    *va_arg(ap, int*) = strtol(buffer, &temp, 10);
                    count++;
                    break;
                case 'x':
                    *va_arg(ap, int*) = strtol(buffer, &temp, 16);
                    count++;
                    break;
                default:
                    break;
            }
        }
        str++;
    }
    va_end(ap);
    return count;
}

