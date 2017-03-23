#include<stdio.h>

int main()
{
	int id[5] = { 0,0,0,0,0 }, i = 0;
	char in[100];
	scanf("%s", in);
	while (in[i]!=0)
	{
		id[in[i] - 'A']++;
		i++;
	}
	for (i = 0; i < 5; i++)
	{
		printf("%c %d\n", i + 'A', id[i]);
	}
}