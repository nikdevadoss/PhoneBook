#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

//define structs

//represents a contact's entry in the  directory
struct Person {
    char *phoneNumber;
    char *name;

};

//function declarations
struct Person * createPerson(char* , char*);
void editName(struct Person *, char*);
void editNumber(struct Person *, char*);
void printCommands();
void removeContact(char *);
void addContact(struct Person *);
void listContacts();
static int callback(void *, int , char **, char **);

int main(){
    sqlite3 *db;
    char* error_msg;
    char* sql;

    //int rc = sqlite3_open_v2("data.db", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);
    int rc = sqlite3_open("data.sqlite", &db);
    
    if(1){
        sql = "DROP TABLE IF EXISTS Cars;" 
                "CREATE TABLE Phonebook(Name TEXT, Number TEXT);" 
                "INSERT INTO Cars VALUES('Nikhil', 6505563279);"
                "INSERT INTO Cars VALUES('Dad', 6507438192);"
                "INSERT INTO Cars VALUES('Niraj', 6505873279);";
      //rc = sqlite3_exec(db, sql, 0, 0, &error_msg);
    }



    while(1){
        printf("\n");
        printf("Command: ");
        char command[6];
        scanf("%s", &command);
        if(strcmp(command, "help") == 0){
            printCommands();
        }
        else if(strcmp(command, "list") == 0){
            listContacts();
        }
        else if(strcmp(command, "search") == 0){
            
        }
        else if(strcmp(command, "add") == 0){
            char number[100];
            char name[100];
            printf("Name: \n");
            scanf("%s", name);
            printf("Phone number: \n");
            scanf("%s", number);
            struct Person *p = createPerson(number, name);
            //addContact(p, fd);
        }
        else if(strcmp(command, "remove") == 0){
            char name[100];
            printf("Name: \n");
            scanf("%s", name);
            removeContact(name);
        }
        else if(strcmp(command, "quit") == 0){
            // fclose(data);
            exit(1);
        }
        else{
            printf("Not a valid command, please try again\n");
        }
    }
    sqlite3_close(db);


}
void printCommands(){
    printf("Commands: \n");
    printf("help: Lists all commands\n");
    printf("list: Lists all contact name's in your directory\n");
    printf("search: Searches directory for name or number and outputs profile\n");
    printf("add: Creates new contact\n");
    printf("remove: Removes existing contact\n");
    printf("quit: terminates program\n");
}

struct Person *createPerson(char*  phoneNumber, char *name){
    struct Person *p = malloc(sizeof(struct Person));
    p->phoneNumber = phoneNumber;
    p->name = name;
    return p;
}


void editName(struct Person *p, char* newName){
    p->name = newName;
}

void editNumber(struct Person *p, char* newNumber){
    p->phoneNumber = newNumber;
}

void addContact(struct Person *p){
}

void removeContact(char * name){

}

void listContacts(){

}

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}