#include<stdio.h>
#include<stdlib.h>

typedef struct book {
    int bookId;
    char title;
    char Author;
    int publicationYear;
    struct book* NextStudent;
};
struct book* addNewBook(int bookId, int age) {
        struct book* newBook = (struct book*)malloc(sizeof(struct book));
    
        if (newBook == NULL)
        {
            printf("No More Memory Space Found!!! Ran out of memory!!");
            exit(EXIT_FAILURE);
        }
    
        newBook->bookId = bookId;
        newBook->title = title;
        
        newStudent->NextStudent = NULL;
    
        return newStudent;
    }