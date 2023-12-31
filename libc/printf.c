#include <u.h>
#include <libc.h>
#include <cons.h>

static int
print_char(int c)
{
	cons_putc(defcons, c);
	return 1;
}

static int
print_str(char *str)
{
	cons_write(defcons, str);
	return strlen(str);
}

static int
print_digit(long num, int base)
{
	int count;
	char *d;
	char *symbols = "0123456789abcdef";

	if (num < 0)
	{
		cons_write(defcons, "-");
		return print_digit(-num, base) + 1;
	}
	else if (num < base)
	{
		return print_char(symbols[num]);
	}
	else
	{
		count = print_digit(num / base, base);
		return count + print_digit(num % base, base);
	}
	
}

static int
print_format(char specifier, va_list ap)
{
	int count = 0;

	switch (specifier)
	{
		case 'c':
			count += print_char(va_arg(ap, int));	// Type promotion
			break;
		case 's':
			count += print_str(va_arg(ap, char*));
			break;
		case 'd':
			count += print_digit((long)va_arg(ap, int), 10);
			break;
		case 'x':
			print_str("0x");
			count += print_digit((long)va_arg(ap, unsigned int), 16);
			break;
		default:
			count += print_char(specifier);
			break;
	}

	return count;
}

int
printf(const char* restrict format, ...) 
{
	va_list ap;
	va_start(ap, format);
	int count = 0;

	while (*format) 
	{
		if (*format == '%') 
			count += print_format(*(++format), ap);
		else
			count += print_char(*format);
		format++;
	}

	va_end(ap);
	return count;
}
