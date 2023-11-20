#include <cons.h>
#include <pccons.h>

void
bitputs(char *s)
{
	int line, chr, bit;
	int set;
	
	for(line = 0; line < 8 ; line++)
	{
		for(chr = 0; chr < strlen(s) ; chr++)
 		{
 			for(bit = 0; bit < 8 ; bit++)
 			{
				set = blockfont[s[chr]][line] & 1 << bit;
				consputc(pccons, (set ? 178 : ' '));
			}
		}
		consputc(pccons, '\n');
	}
	consputc(pccons, '\n');
}

void
bitputc(char c)
{
	int line, bit;
	int set;
	
	for(line = 0 ; line < 8 ; line++)
	{
		for(bit = 0 ; bit < 8 ; bit++)
		{
			set = blockfont[s[chr]][line] & 1 << bit;
			consputc(pccons, (set ? 178 : ' '));	
		}
		consputc(pccons, '\n');
	}
}