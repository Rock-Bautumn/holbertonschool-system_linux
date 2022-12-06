#include <Python.h>

/*
Python lists:

    Prototype: void print_python_list(PyObject *p);
    Format: see example

Python bytes:

    Prototype: void print_python_bytes(PyObject *p);
    Format: see example
    Line “first X bytes”: print a maximum of 10 bytes
    If p is not a valid PyBytesObject, print an error message (see example)
    Read /usr/include/python3.4/bytesobject.h

About:

    Python version: 3.4
    Your shared library will be compiled with this command line: gcc -Wall -Werror -Wextra -pedantic -std=c99 -shared -Wl,-soname,libPython.so -o libPython.so -fPIC -I/usr/include/python3.4 2-python.c
    You are not allowed to use the following macros/functions:

*/
#define MAX_PRINT_SIZE 10
/*
unsigned long abs(long num)
{
	if (num < 0)
		num = -(num);
	return num;
}
*/
void print_python_int(PyObject *p)
{
	PyVarObject *pvo = (PyVarObject *) p;
	PyLongObject *plo = (PyLongObject *) p;
	Py_ssize_t size = pvo->ob_size, mag = labs((long) size), i;
	digit *deetz = plo->ob_digit;
	unsigned long num = 0;

	setbuf(stdout, NULL);

	if (PyLong_Check(p) == 0)
	{
		printf("Invalid Int Object\n");
		return;
	}

	if ((mag == 3 && deetz[2] >= 16) || mag > 3)
	{
		printf("C unsigned long int overflow\n");
		return;
	}

	for (i = 0; i < mag; i++)
		num += deetz[i] * (1L << (i * PyLong_SHIFT));

	if (size < 0)
		putchar('-');

	printf("%lu\n", num);
}
