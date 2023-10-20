
#include <stdio.h>
#include <string.h>

/************************************************************
 *          
 *                   Global variable
 * 
 ************************************************************/
int number_Of_Book=0;
int existing_book_index=0;

/************************************************************
 *          
 *                  Prototype Functions
 * 
 ************************************************************/
int check_Is_exist(char*title);
void printContents();
void addBook();
void borrow();
void deletefn();
void buyBook(int copyNumber);

/************************************************************
 *          
 *              The structure of the library
 * 
 ************************************************************/

typedef struct 
{
    char book_title[100];
    char author_name[100];
    char status[50];
    int publication_year;
    int number_of_copies;
    float price;
    int available;
}library;

library collection_Of_lib[100];