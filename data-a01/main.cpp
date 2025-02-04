#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct book {
    int bookId;
    char title;
    char author;
    int publicationYear;
    struct book* nextBook;
};
struct book* addNewBook(int bookId, char title, char author, int publicationYear) 
{
        struct book* newBook = (struct book*)malloc(sizeof(struct book));
    
        if (newBook == NULL)
        {
            printf("No More Memory Space Found!");
            exit(EXIT_FAILURE);
        }
    
        newBook->bookId = bookId;
        newBook->title = title;
        newBook->author = author;
        newBook->publicationYear = publicationYear;
        newBook->nextBook = NULL;
    
        return newBook;
    }

void findBook(book* head, char title) {
    printf("Please enter a book title or a partial book title to search for");
    char newText[100];
    fgets(newText, 100, stdin);
    while (*head != NULL) {

    }


}