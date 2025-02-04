#include<stdio.h>
#include<stdlib.h>

const int SIZE = 10;

typedef struct book
{
    int bookId;
    char title;
    char author;
    int publicationYear;
    struct book* nextBook;
};
int main(void) {
	char inputMenu[] = { "0" };
	int inputValidation = 0;
	while (inputMenu[0] != 'e')
	{

		struct book* newBook = NULL;
		struct book* tempBook = NULL;
		printf("MENU\n");
		printf("1)Add new Book\n");
		printf("2)View all Books\n");
		printf("3)Update a Book\n");
		printf("4)Delete a Book\n");
		printf("5)Search for a Book\n");
		printf("Please choose an option: ");
		scanf_s("%c", &inputMenu, SIZE);

		switch (inputMenu[0])
		{
		default:
			break;
		}
	}
	return 0;
}

char validateInputSize(char input[])
{
	while(input[1] != NULL )
	{
		printf("\nPlease check input size!\n");
		printf("Please try again: ");
		scanf_s("%c\n", input[0], SIZE);
	}
	return input[0];
}


//    PrintList(head);
//
//    head = InsertAtEnd(head, 4, 40);
//    printf("After Insertion at the End: \n");
//    PrintList(head);
//
//    int age = GetAgeByStudentId(head, 5);
//
//    if (age != -1) {
//        printf("Student's Age: %d", age);
//    }
//
//}
//int main()
//{
//	bookInfo* head = NULL;
//	bookInfo* tail = NULL;
//
//	InsertNewStudentAtTheBeginning(&head, &tail, CreateNewStudent(2, 10)); //O(1)
//	InsertNewStudentAtTheBeginning(&head, &tail, CreateNewStudent(1, 20)); //O(1)
//
//	InsertNewStudentAtEnd(&head, &tail, CreateNewStudent(3, 10)); //O(1)
//	InsertNewStudentAtEnd(&head, &tail, CreateNewStudent(4, 10)); //O(1)
//
//	DeleteTail(&head, &tail);
//
//	PrintList(head);
//
//	int age = GetAgeByStudentId(head, 4);
//	if (age != -1)
//	{
//		printf("Age: %d", age);
//	}
//
//	FreeList(&head); // Garbage Collection
//	return 0;
//}