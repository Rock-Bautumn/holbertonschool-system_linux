/**
 * main - gets stuck in a loop forever with some value in memory
 * Return: 0 if success, something else if fail
*/
int main()
{
	int i = 1234567;

	while (i < 1)
	;
	return (*(int *)0x0);
}
