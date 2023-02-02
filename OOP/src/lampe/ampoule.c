#include <stdlib.h>
#include <stdio.h>
#include "ampoule.h"

typedef enum{
	OFF=0,
	ON
}ampoule_state_e;

/*----------OBJECT ATTRIBUTES----------*/
struct Ampoule_attributes{
	ampoule_state_e state;
};

/*----------OBJECT CONSTRUCTORS----------*/
extern Ampoule* AMPOULE_new(){
	Ampoule* pAmpoule = (Ampoule*)malloc(sizeof(Ampoule));
	pAmpoule->state = OFF;
	if(pAmpoule==NULL){
		printf("ERROR : pAmpoule is null");
		while(1);
	}
	return pAmpoule;
}

/*----------OBJECT METHODS----------*/
extern void AMPOULE_allumer(Ampoule* ampoule){
	ampoule->state = ON;
}

extern void AMPOULE_eteindre(Ampoule* ampoule){
	ampoule->state = OFF;
}

extern int AMPOULE_getState(Ampoule* ampoule){
	if(ampoule->state){
		return 1;
	}
	else{
		return 0;
	}
}

/*----------OBJECT DESTRUCTORS----------*/
extern void AMPOULE_free(Ampoule* pAmpoule){
	free(pAmpoule);
}
