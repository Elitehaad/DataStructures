#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
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

void searchBooks(Book* head, const char* title) {
    //Count to check for book found
    int count = 0;
    //Loop until the end of the linked list
    while (head != NULL) {
        
        size_t length = strlen(title);
        size_t length2 = strlen(head->title);
        // Memory allocation
        char* current = (char*)malloc((length2 + 1) * sizeof(char));
        //Allocation error check
        if (current == NULL) {
            free(current);
            exit(EXIT_FAILURE);
        }
        char* searchTerm = (char*)malloc((length + 1) * sizeof(char));
        if (current == NULL) {
            free(searchTerm);
            exit(EXIT_FAILURE);
        }
        // Turns both title and search term into upper case for case insensitive implementation
        for (int loopCount = 0; loopCount < length2; loopCount++) {
            current[loopCount] = toupper(head->title[loopCount]);

        }
        for (int loopCount = 0; loopCount < length; loopCount++) {
            searchTerm[loopCount] = toupper(title[loopCount]);
            
        }
        // Adds null terminator
        searchTerm[length] = '\0';
        current[length2] = '\0';
        // Compares the substring with the book titles 
        if (strstr(current, searchTerm) != NULL) {
            // Pritns results
            printf("Book found \nID: %d\nTitle: %s\nAuthor: %s\nYear: %d", head->id, head->title, head->author, head->publication_year);
            count++;
      }
        //Moves the pointer to the next struct
        head = head->next;
        // Free memory
        free(current);
        free(searchTerm);
       
    }
    // Message for not result found
    if (count == 0) {
        printf("No matching results");
    }
    
    

}