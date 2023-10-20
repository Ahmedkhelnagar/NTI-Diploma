
#include"library.h"


/************************************************************
 *          
 *                   Main Function
 * 
 ************************************************************/
int main()
{   
    int choice;
    int copynum=0;

    while(choice!=6)
    {
        printf("Menu library\n");
        printf("1:ADD,2:BORROW,3:DELETE,4:PRINT,5:BUY\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                addBook();
                break;
            case 2:
                borrow();
                break;
            case 3:
                deletefn();
                break;
            case 4:
                printContents();
                break;
            case 5:
                printf("Enter the number of the copies of the book: ");
                scanf("%d",&copynum);
                buyBook(copynum);
                break;
            case 6:
                printf("Goofbye..");
                break;
            default:    
                printf("Invalid choice\n");
                break;
        }
        
    } 

    return 0;
}




/************************************************************
 *          
 *                   Function Definitions
 * 
 ************************************************************/



/************************************************************
 *          
 *          Function to check the Book is already or not
 * 
 ************************************************************/
int check_Is_exist(char* title)
{
    for (int i = 0; i<number_Of_Book; i++) {
        if (strcmp(collection_Of_lib[i].book_title, title) == 0) {
            // Book with the same title exists; return the index of the existing book
            return i;
        }
    }
    // Book with the same title does not exist
    return -1;
}

void addBook()
{   
    if (number_Of_Book >= 100)
    {
        printf("The library is full.\n");
        return;
    }

    printf("Enter the book name to be added:\n ");
    scanf(" %[^\n]s ", collection_Of_lib[number_Of_Book].book_title);
    getchar();

    int existing_book_index = check_Is_exist(collection_Of_lib[number_Of_Book].book_title);
    if (existing_book_index != -1)
    {   
        collection_Of_lib[existing_book_index].number_of_copies++;
        printf("Number of copies increased to %d for book '%s'.\n", collection_Of_lib[existing_book_index].number_of_copies, collection_Of_lib[existing_book_index].book_title);
    }
    else
    {
        printf("Enter the author name:\n ");
        scanf(" %[^\n]s", collection_Of_lib[number_Of_Book].author_name);
        getchar();

        printf("Enter the status of the book: \n");
        scanf(" %[^\n]s", collection_Of_lib[number_Of_Book].status);
        getchar();
        collection_Of_lib[number_Of_Book].available=1;

        printf("Enter the publication year:");
        scanf("%d", &collection_Of_lib[number_Of_Book].publication_year);

        printf("Enter the price of the book:");
        scanf("%f", &collection_Of_lib[number_Of_Book].price);

        collection_Of_lib[number_Of_Book].number_of_copies = 1;
        number_Of_Book++;
    
        printf("The book is added successfully!\n");

    }
}

/************************************************************
 *          
 *          Function to print the content of the library
 * 
 ************************************************************/
void printContents()
{   
    if (number_Of_Book == 0) {
        printf("The library is empty.\n");
    } else {
        printf("\nLibrary Contents:\n");

        for(int i=0;i<number_Of_Book;i++)
        {   
            printf("Book %d\n",i+1);

            printf("\nThe book name %d is %s",i,collection_Of_lib[i].book_title);  

            printf("\nThe author name of the book %d is %s\n",i,collection_Of_lib[i].author_name);

            printf("The status of the book %d is %s\n",i,collection_Of_lib[i].status);

            printf("The number of the copies of the book is %d\n",collection_Of_lib[i].number_of_copies);

            printf("The publication year of book %d is %d",i,collection_Of_lib[i].publication_year);

            printf("\nThe price of book %d is %.2f",i,collection_Of_lib[i].price);  
            printf("\n===========================\n");    
        }
    }
}


/************************************************************
 *          
 *          Function to borrow a book
 * 
 ************************************************************/

void borrow()
{   
    char bookToBorrow[100];
    printf("Enter the book name that wanted to borrow: ");
    scanf(" %[^\n]s ",bookToBorrow);

    int book_index=check_Is_exist(bookToBorrow);
    if(book_index!=-1)
    {
        if(collection_Of_lib[book_index].available==1)
        {
            collection_Of_lib[book_index].available=0;
            printf("The book is borrowed successfully!\n");
            collection_Of_lib[book_index].number_of_copies--;
        }
        else
        {
            printf("The book is not available in the library at the moment.\n");
        }
    }
    else
    {
        printf("The book not found in the libraray now\n");
    }
}


/************************************************************
 *          
 *          Function to delete a book
 * 
 ************************************************************/

void deletefn()
{   
    char bookToDelet[100];
    printf("Enter the book that you wanted to delete: ");
    scanf(" %[^\n]s ",bookToDelet);

    int book_index=check_Is_exist(bookToDelet);
    if(book_index!=-1)
    {
        for(int i =book_index;i<number_Of_Book-1;i++)
        {
            collection_Of_lib[i]=collection_Of_lib[i+1];
        }
            number_Of_Book--;
            printf("The book is deleted successfully!\n");
    }
    else
    {
        printf("The book not found in the libraray now.\n");
    }    
}

/************************************************************
 *          
 *          Function to buy a book
 * 
 ************************************************************/

void buyBook(int copyNumber)
{   
    char bookToBuy[100];
    printf("Enter the book name that want to buy:\n");
    scanf(" %[^\n]s ",bookToBuy);
    int book_Index=check_Is_exist(bookToBuy);
    if(book_Index!=-1)
    {
        collection_Of_lib[book_Index].number_of_copies+=copyNumber;
        printf("You have bought %d copies of this book successfully!\n",copyNumber);
        printf("\nYou have bought this book successfully!\n");
    }
    else
    {
        printf("The book not found in the library\n");
    }
}
