#include "LinkedList_Test.h"
#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

void runListTest()
{
	// Arrange
	LinkedList list = List_Create();
	int a[] = { 0,1,2,3,4,5,6,7,8,9 };

	// Act
	for (int i = 0; i < 10; i++)
		List_Insert(list, a + i);

	// Assert
	List_DataType* actual = NULL;
	size_t actual_size = 0;
	List_ToArray(list, &actual, &actual_size);

	bool isOK = actual_size == 10;
	if (isOK)
	{
		for (size_t i = 0; i < actual_size; i++)
		{
			List_DataType current_void_ptr = actual[i];
			int* current_int_ptr = (int*)current_void_ptr;
			int current_value = *current_int_ptr;
			isOK = isOK && (current_value == 9 - i);
		}
	}
	free(actual);
	List_Free(list);
	printf("%s\n", isOK ? "OK!" : "Oh,No");
}