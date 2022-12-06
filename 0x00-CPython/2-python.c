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

void print_python_bytes(PyObject *p)
{
	/* PyObject *byteItem; */
	PyBytesObject *bytes;
	Py_ssize_t size;
	unsigned int i;

	if (PyBytes_Check(p) == 0)
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		fflush(stdout);
		return;
	}
	bytes = (PyBytesObject *) p;
	size = bytes->ob_base.ob_size;
	printf("[.] bytes object info\n");
	printf("  size: %lu\n", size);
	printf("  trying string: %s\n", bytes->ob_sval);
	if (size >= MAX_PRINT_SIZE)
		size = MAX_PRINT_SIZE;
	else
		size++;
	printf("  first %lu bytes:", size);
	for (i = 0; i < size; i++)
		printf(" %02x", bytes->ob_sval[i] & 0xff);
	putchar('\n');
}

void print_python_list(PyObject *p)
{
	PyObject *listItem;
	PyListObject *list = (PyListObject *) p;
	int i;

	if (PyList_Check(p) == 0)
	{
		printf("  [ERROR] Invalid List Object\n");
		fflush(stdout);
		return;
	}
	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %ld\n", PyList_Size(p));
	printf("[*] Allocated = %ld\n", list->allocated);

	for (i = 0; i < PyList_Size(p); i++)
	{
		listItem = PyList_GET_ITEM(p, i);
		printf("Element %d: %s\n", i, listItem->ob_type->tp_name);
	}
}
