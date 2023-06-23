// Class database
// A database of all classes which will be used throughout the university.
// Ameen Al-Asady
// 251146878

#include <stdio.h>
#include <string.h>

#define MAX_CLASSES 100           // maximum number of classes that can be stored
#define MAX_CLASS_NAME_LENGTH 100 // maximum length of class name

// define a structure to represent a class
typedef struct
{
    int code;                         // class code
    char name[MAX_CLASS_NAME_LENGTH]; // class name
    int max_size;                     // maximum class size
    char day[4];                      // day of the week the class is held
    int time;                         // time the class is held that day
} Class;

Class classes[MAX_CLASSES]; // array of structures to represent up to 100 possible classes
int num_classes = 0;        // number of classes currently stored

// function to insert a new class into the database
void insert_class()
{
    if (num_classes == MAX_CLASSES)
    { // check if database is full
        printf("Error: Database is full\n");
        return;
    }

    Class new_class; // create a new Class structure to store the new class information

    printf("\tEnter class code: ");
    scanf("%d", &new_class.code);
    if (new_class.code < 0 || new_class.code > 999)
    { // check if class code is valid
        printf("Error: Invalid class code\n");
        return;
    }
    for (int i = 0; i < num_classes; i++)
    { // check if class code already exists in database
        if (classes[i].code == new_class.code)
        {
            printf("Error: Class code already exists\n");
            return;
        }
    }

    printf("\tEnter class name: ");
    scanf(" %[^\n]s", new_class.name); // read class name from user input

    printf("\tEnter maximum class size: ");
    scanf("%d", &new_class.max_size);
    if (new_class.max_size < 10 || new_class.max_size > 500)
    { // check if maximum class size is valid
        printf("Error: Invalid maximum class size\n");
        return;
    }

    printf("\tEnter day of the week: ");
    scanf("%s", new_class.day);
    if (strcmp(new_class.day, "Mon") != 0 && strcmp(new_class.day, "Tue") != 0 && strcmp(new_class.day, "Wed") != 0 && strcmp(new_class.day, "Thu") != 0 && strcmp(new_class.day, "Fri") != 0)
    { // check if day of the week is valid
        printf("Error: Invalid day of the week\n");
        return;
    }

    printf("\tEnter time of day: ");
    scanf("%d", &new_class.time);
    if (new_class.time != 1 && new_class.time != 2 && new_class.time != 3 && new_class.time != 4 && new_class.time != 9 && new_class.time != 10 && new_class.time != 11 && new_class.time != 12)
    { // check if time of day is valid
        printf("Error: Invalid time of day\n");
        return;
    }

    classes[num_classes++] = new_class; // add the new class to the database and increment the number of classes
}

// function to search for a class in the database and print it out
void search_class()
{
    int code;
    printf("\tEnter class code: ");
    scanf("%d", &code);

    for (int i = 0; i < num_classes; i++)
    { // search for the class with the given code in the database
        if (classes[i].code == code)
        {
            printf("%-10s %-30s %-20s %-10s %-10s\n", "Code", "Name", "Max Size", "Day", "Time");                                              // print column headers
            printf("%-10d %-30s %-20d %-10s %-10d\n", classes[i].code, classes[i].name, classes[i].max_size, classes[i].day, classes[i].time); // print class information
            return;
        }
    }

    printf("Error: Class not found\n"); // if no matching class was found, print an error message
}

// function to update a class in the database
void update_class()
{
    int code;
    printf("\tEnter class code: ");
    scanf("%d", &code);

    for (int i = 0; i < num_classes; i++)
    { // search for the class with the given code in the database
        if (classes[i].code == code)
        {
            Class updated_class = classes[i]; // create a copy of the found Class structure to store updated information

            printf("\tEnter class name: ");
            scanf(" %[^\n]s", updated_class.name); // read updated class name from user input

            printf("\tEnter maximum class size: ");
            scanf("%d", &updated_class.max_size);
            if (updated_class.max_size < 10 || updated_class.max_size > 500)
            { // check if maximum class size is valid
                printf("Error: Invalid maximum class size\n");
                return;
            }

            printf("\tEnter day of the week: ");
            scanf("%s", updated_class.day);
            if (strcmp(updated_class.day, "Mon") != 0 && strcmp(updated_class.day, "Tue") != 0 && strcmp(updated_class.day, "Wed") != 0 && strcmp(updated_class.day, "Thu") != 0 && strcmp(updated_class.day, "Fri") != 0)
            { // check if day of the week is valid
                printf("Error: Invalid day of the week\n");
                return;
            }

            printf("\tEnter time of day: ");
            scanf("%d", &updated_class.time);
            if (updated_class.time != 1 && updated_class.time != 2 && updated_class.time != 3 && updated_class.time != 4 && updated_class.time != 9 && updated_class.time != 10 && updated_class.time != 11 && updated_class.time != 12)
            {
                // check if time of day is valid
                printf("Error: Invalid time of day\n");
                return;
            }

            classes[i] = updated_class;
            // update the Class structure in the database with the updated information
            return;
        }
    }

    printf("\tError: Class not found\n");
    // if no matching class was found, print an error message
}

// function to print all classes in the database
void print_classes()
{
    printf("%-10s %-30s %-20s %-10s %-10s\n", "Code", "Name", "Max Size", "Day", "Time");
    // print column headers

    for (int i = 0; i < num_classes; i++)
    {
        printf("%-10d %-30s %-20d %-10s %2d %s\n", classes[i].code, classes[i].name, classes[i].max_size, classes[i].day, classes[i].time, (classes[i].time >= 9 && classes[i].time <= 11) ? "am" : "pm");
        // print information for each class in the database
    }
}

int main()
{

    printf("*******************\n");
    printf("* 2211 University *\n");
    printf("*******************\n");

    char command;

    while (1)
    {
        printf("\nEnter command (i - insert, s - search, u - update, p - print, q - quit): ");
        scanf(" %c", &command);

        switch (command)
        {
        case 'i':
            insert_class();
            break;

        case 's':
            search_class();
            break;

        case 'u':
            update_class();
            break;

        case 'p':
            print_classes();
            break;

        case 'q':
            return (0);

        default:
            printf("\nInvalid command!\n");
        }
    }
}