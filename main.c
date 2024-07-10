#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "main.h"


struct Person
{
    char *name;
    int age;
    int height;
    int weight;

};

struct Person *Person_Create(char *name,int age,int height,int weight)
{
    struct Person *who = malloc(sizeof(struct Person));
    assert( who != NULL);

    who->name = strdup(name);
    who->age = age;
    who->height = height;
    who->weight = weight;

    return(who);
};

void Person_Destroy(struct Person *who )
{
    assert( who != NULL);

    free( who->name );
    free( who );
}

void Person_Print(struct Person *who )
{
    assert( who != NULL);

    printf("Name: %s\n", who->name );
    printf("Age: %d\n", who->age );
    printf("Height: %d\n", who->height );
    printf("Width: %d\n", who->weight );
}

int main( int argc, char *argv[] )
{
    struct Person *P1 = Person_Create("Robert Odhiambo", 21, 61, 60);
    printf("Memory of P1 is at: %p\n", P1);
    Person_Print( P1 );

    struct Person *P2 = Person_Create("Ridan Hawy", 21, 64, 55);
    printf("\nMemory of P2 is at: %p\n", P2);
    Person_Print( P2 );


    return (0);
}


