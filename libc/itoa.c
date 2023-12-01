// A utility function to reverse a string
void
reverse(char str[], int length)
{
	int start = 0;
	int end = length - 1;
	while (start < end) 
	{
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		end--;
		start++;
	}
}

char*
itoa(int num, char* str, int base)
{
	int i = 0;
	int isNegative = 0;

	// Handle 0 explicitly
	if (num == 0) 
	{
		str[i++] = '0';
		str[i] = '\0';
		return str;
	}

	/* In standard itoa(), negative numbers are handled
	 only with base 10. Otherwise numbers are
	 considered unsigned. */
	if (num < 0 && base == 10) 
	{
		isNegative = 1;
		num = -num;
	}

	// Process individual digits
	while (num != 0) 
	{
		int rem = num % base;
		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num = num / base;
	}

	// If number is negative, append '-'
	if (isNegative)
		str[i++] = '-';

	// Reverse the string
	reverse(str, i);
	
	// Append string terminator
	str[i] = '\0';

	return str;
}