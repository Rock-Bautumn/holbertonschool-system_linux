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

void print_python_float(PyObject *p)
{
	char *flotsam;
	PyFloatObject *jetsam;

	setbuf(stdout, NULL);
	printf("[.] float object info\n");

	if (PyFloat_Check(p) == 0)
	{
		printf("  [ERROR] Invalid Float Object\n");
		return;
	}

	jetsam = (PyFloatObject *) p;
	flotsam = PyOS_double_to_string(jetsam->ob_fval, 'g', 16, 0, NULL);

	if (strchr(flotsam, '.'))
		printf("  value: %s\n", flotsam);
	else
		printf("  value: %s.0\n", flotsam);

	PyMem_Free(flotsam);
}

void print_python_bytes(PyObject *p)
{
	/* PyObject *byteItem; */
	PyBytesObject *bytes;
	Py_ssize_t size;
	unsigned int i;

	setbuf(stdout, NULL);
	printf("[.] bytes object info\n");

	if (PyBytes_Check(p) == 0)
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}

	bytes = (PyBytesObject *) p;
	size = bytes->ob_base.ob_size;
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

	setbuf(stdout, NULL);
	printf("[*] Python list info\n");

	if (PyList_Check(p) == 0)
	{
		printf("  [ERROR] Invalid List Object\n");
		return;
	}

	printf("[*] Size of the Python List = %ld\n", PyList_GET_SIZE(p));
	printf("[*] Allocated = %ld\n", list->allocated);

	for (i = 0; i < PyList_GET_SIZE(p); i++)
	{
		listItem = PyList_GET_ITEM(p, i);
		printf("Element %d: %s\n", i, listItem->ob_type->tp_name);
		if (strcmp(listItem->ob_type->tp_name, "bytes") == 0)
			print_python_bytes((PyObject *) listItem);
		else if (strcmp(listItem->ob_type->tp_name, "float") == 0)
			print_python_float((PyObject *) listItem);
	}
}
