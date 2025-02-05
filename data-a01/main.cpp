#include "management.h"

int main(void) {
    Book* head = NULL;
    Book* tail = NULL;
    int choice;	// Variable to store user's choice
    int tmpID;
    char tmpTitle[MAX_NAME_LENGTH];
    char tmpAuthor[MAX_NAME_LENGTH];
    int tmpPublicationYear = 0;

    do {
        printf("\nMENU\n");
        printf("1. Add new Book\n");
        printf("2. View all Books\n");
        printf("3. Update a Book\n");
        printf("4. Delete a Book\n");
        printf("5. Search for a Book\n");
        printf("6. Exit\n");
        printf("Please choose an option: ");

        // Check if input is a valid number
        if (scanf_s("%d", &choice) != 1) {
            printf("\nInvalid input. Please enter a number.\n");
            while (getchar() != '\n') {} // Clear the input buffer
            choice = -1; // Set an invalid choice to repeat the loop
            continue;
        }
        

        switch (choice) {
        case 1: {
            printf("Please Enter the Book Information:\n");
            printf("ID: ");
            scanf_s("%d", &tmpID);

            printf("Title: ");
            scanf_s("%s", tmpTitle, MAX_NAME_LENGTH);

            printf("Author: ");
            scanf_s("%s", tmpAuthor, MAX_NAME_LENGTH);

            printf("Publication year: ");
            scanf_s("%d", &tmpPublicationYear);

            addBook(&head, tmpID, tmpTitle, tmpAuthor, tmpPublicationYear);
            break;
        }
        case 2: {
            viewBooks(head);
            break;
        }
        case 3:
        case 4:
        case 5:
        case 6: {
            // Exit the program
            printf("\nExiting program.\n");
            break;
        }
        default: {
            // Handle invalid input
            printf("\nInvalid choice. Please try again.\n");
            break;
        }
        }
    } while (choice != 6);



    
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
    printf("Book added correctly\n");
}
void viewBooks(Book* head) {
    // If the list is empty
    if (head == NULL) {
        printf("No books to display.\n");
        return;
    }

    // Pointer to traverse the list
    Book* current = head;
    int count = 0;
    printf("\nDisplaying the Library");
    // Traverse until the end of the list
    while (current != NULL) {
        count++;
        // Print details of the current book
        printf("\nBOOK %d\n", count);
        printf("ID: %d\n", current->id);
        printf("Title: %s\n", current->title);
        printf("Author: %s\n", current->author);
        printf("Publication Year: %d\n", current->publication_year);

        // Move to the next book
        current = current->next;

    }
    printf("\n%d Book(s) Registered in the Library\n", count);
}
//
// FUNCTION : cleanBuffer
// DESCRIPTION : https://stackoverflow.com/questions/7898215/how-can-i-clear-an-input-buffer-in-c
// This function clears any remaining characters in the input buffer,
// including newline characters, to prevent unintended inputs in future reads.
// PARAMETERS :
// None
// RETURNS :
// void : This function does not return a value.
//
void cleanBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}