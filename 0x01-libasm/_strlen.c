unsigned int asm_strlen(const char *str)
{
	unsigned int size = 0;

	while (str[size] != '\0')
		size++;
	return (size);
}
