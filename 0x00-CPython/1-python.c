#include <Python.h>

void print_python_list(PyObject *p)
{
	PyObject *listItem;
	PyListObject *list = (PyListObject *) p;
	int i;

	if (PyList_Check(p) == 0)
		{
			fprintf(stderr, "The object is not a list\n");
			return;
		}
	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %ld\n", Py_SIZE(p));
	printf("[*] Allocated = %ld\n", list->allocated);

	for (i = 0; i < Py_SIZE(p); i++)
	{
		listItem = PyList_GetItem(p, i);
		printf("Element %d: %s\n", i, listItem->ob_type->tp_name);
	}
}
