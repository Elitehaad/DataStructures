#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "management.h"

int main(void) {
    Book* head = NULL;
    Book* tail = NULL;
    int idd = 8976;
    char titlee[] = "Howare";
    char author[] = "Juan";
    int publicationn = 7896;
    addBook(&head, idd, titlee, author, publicationn);
    return 0;
}

void addBook(Book** head, int id, const char* title, const char* author, int publication_year) {
    
    Book* newBook = (Book*)malloc(sizeof(Book));
    if (newBook == NULL)
    {
        printf("Not Enough Memory!");
        exit(EXIT_FAILURE);
    }

    newBook->id = id;
    newBook->publication_year = publication_year;
    strncpy_s(newBook->title, sizeof(newBook->title), title, _TRUNCATE);
    strncpy_s(newBook->author, sizeof(newBook->author), author, _TRUNCATE);
    newBook->next = *head;
    *head = newBook;
}
