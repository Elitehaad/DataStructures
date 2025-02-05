#pragma once
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdbool.h>

const int MAX_NAME_LENGTH = 100;

typedef struct Book {
    int id;
    char title[MAX_NAME_LENGTH];
    char author[MAX_NAME_LENGTH];
    int publication_year;
    struct Book* next;
} Book;

void addBook(Book** head, int id, const char* title, const char* author, int publication_year);
void viewBooks(Book* head);
void cleanBuffer();
//void viewBooks(Book* head);
//void updateBook(Book* head, int id);
//void deleteBook(Book** head, int id);
//void searchBooks(Book* head, const char* title);