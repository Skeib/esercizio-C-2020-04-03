#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define NAME_LEN 64
#define PHONE_LEN 20

typedef struct {
   int id; // id numerico del contatto (valore univoco)
   char name[NAME_LEN + 1]; // nome della persona
   char phone[PHONE_LEN + 1]; // numero di telefono
} contact_type;

//
//scrivere le seguenti funzioni:
//
// crea un oggetto di tipo contact_type e lo inizializza con name e phone
//contact_type * create_contact(char * name, char * phone);
//
// scrive su stdout i contenuti dell'oggetto
//void print_contact(contact_type * person);

unsigned int id =0;

contact_type * create_contact(char * name, char * phone){

	contact_type * contatto;

	contatto = calloc(1, sizeof(contact_type));

	contatto->id= id;

	if(name != NULL)
		strncpy(contatto->name, name, NAME_LEN);
	if(phone != NULL)
		strncpy(contatto->phone, phone, PHONE_LEN);

	id++;

	return contatto;

}

void print_contact(contact_type * person){

	printf("ID Contatto: %d\n", person->id);
	printf("Nome: %s\n", person->name);
	printf("Telefono: %s\n", person->phone);
}

// utilizzare questa implementazione di main:

int main(int argc, char *argv[]) {

	contact_type * pino = create_contact("pino rossi", "+393331234567");

	if (pino == NULL) {
		printf("errore in create_contact!\n");
		exit(EXIT_FAILURE);
	}

	contact_type * gino = create_contact("gino verdi", "+393487654321");

	if (gino == NULL) {
		printf("errore in create_contact!\n");
		exit(EXIT_FAILURE);
	}

	print_contact(pino);

	print_contact(gino);

	return 0;
}
