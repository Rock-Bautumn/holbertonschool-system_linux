unsigned int asm_strlen(const char *str)
{
	unsigned int size = 0;

	while (str[0] != '\0')
		size++;
	return (size);
}
