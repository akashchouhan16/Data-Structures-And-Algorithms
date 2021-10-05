/* C++ program to count no of words from given input string.
    Sample test-case:
	  input: hi I am Pranav .
	  Output:4
	 */
#include <bits/stdc++.h>
using namespace std;
#define OUT 0
#define IN 1
unsigned countWords(char *str)
{
	int state = OUT;
	unsigned wc = 0; // word count
	while (*str)
	{
  	if (*str == ' ' || *str == '\n' || *str == '\t')
			state = OUT;
		else if (state == OUT)
		{
			state = IN;
			++wc;
		}
		++str;
	}

	return wc;
}
int main(void)
{
	char str[] = "hi i am Pranav ";
	cout<<"No of words : "<<countWords(str);
	return 0;
}


