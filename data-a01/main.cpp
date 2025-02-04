#include<stdio.h>
#include<stdlib.h>

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