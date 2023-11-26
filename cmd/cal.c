char*
somegetline(int n)
{
  char c;
  char *line;

  int i = 0;
  
  line = malloc(n);
  memset(line, 0, n);
  
  while(i < n)
  {
    c = ps2_getc();
    // you may, or may not require the following
    vga_putc(c); 
    
    if(c == '\r' || c == '\n')
    {
      line[i] = '\0';
      return line;
        }
    else if(c != '\b')
    {
      line[i] = c;
      i++;
    }
    else
    {
      /* we don't want a negative i */
      if(i)
        i--;
      line[i] = 0;
    }
  }
}

int
chartonum(char input[10]){
	int i, result = 0;

	for (i = 0; input[i] != '\0'; i++) {
	    result = result * 10 + (input[i] - '0');
	}
	return result;
}

// char*
// numtochar(int input){
// 	char result[10] = "0000000000";
// 	for (int i = 9; i >= 0 ; i--) {
// 	    result[i] = input%10;
// 		input = input/10;
// 	}
// 	return *result;
// }

char*
numtochar(int input){
	char *result = malloc(11);
    // result = "0000000000";
	for (int i = 9; i >= 0 ; i--) {
	    result[i] = '0' + (input % 10);
		input = input/10;
	}
    return result;
}

void
cal_main(int, char**){
	char *input;
	int num1;
	int num2;
	// char *oper;
	// num1 = chartonum(somegetline(16));
	// num2 = chartonum(somegetline(16));
	// printf("%d",num1*num2);
	printf("Welcome To Calculator!\n\n");
	// printf("Welcome To Calculator!\n\n");
	while (1)
	{
		printf("enter number 1\n");
		input = somegetline(16);
		if (!strcmp(input, "quit")) return;
		num1 = chartonum(input);
		
		printf("enter number 2\n");
		input = somegetline(16);
		if (!strcmp(input, "quit")) return;
		num2 = chartonum(input);
		
		printf("enter operation\n");
		input = somegetline(16);
		if (!strcmp(input, "quit")) return;
		
		if(!strcmp(input, "+"))
		{
			printf("%d",num1+num2);
			printf("\n\n");
		}
		else if(!strcmp(input, "*"))
		{
			printf("%d",num1*num2);
			printf("\n\n");
		}

	}
	
}

