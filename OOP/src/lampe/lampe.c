#include <stdlib.h>
#include <stdio.h>
#include "lampe.h"
#include "ampoule.h"
#include "util.h"

typedef enum{
	STATE_FORGET=0, //pas de changement d'état (transition dans le même etat, ex : lampe OFF -> on appuie sur OFF)
	STATE_OFF,
	STATE_ON,
	STATE_STOP,
	STATE_NB //nombre d'états
}lamp_state_e;

typedef enum{
	EVENT_BTN_NONE=0,
	EVENT_BTN_OFF,
	EVENT_BTN_ON,
	EVENT_STOP,
	EVENT_NB //nombre d'états
}lamp_event_e;

typedef enum{
	ACTION_NONE=0,
	ACTION_ON,
	ACTION_OFF,
	ACTION_STOP
}lamp_action_e;

typedef struct{
	lamp_state_e next_state;
	lamp_action_e action;
}lamp_transition;

static lamp_transition transition_table[STATE_NB][EVENT_NB] = {
		[STATE_OFF][EVENT_BTN_ON]={STATE_ON, ACTION_ON},
		[STATE_ON][EVENT_BTN_OFF]={STATE_OFF, ACTION_OFF},
		[STATE_OFF][EVENT_STOP]={STATE_STOP, ACTION_STOP},
		[STATE_ON][EVENT_STOP]={STATE_STOP, ACTION_STOP},
};

static void LAMPE_performAction(Lampe* lampe, lamp_action_e action);

/*----------OBJECT ATTRIBUTES----------*/
struct Lampe_attributes{
	lamp_state_e lampe_state;
	Ampoule* ampoule;
};

/*----------OBJECT CONSTRUCTORS----------*/
extern Lampe* LAMPE_new(void){
	Lampe* pLampe = (Lampe*)malloc(sizeof(Lampe));
	pLampe->ampoule = AMPOULE_new();
	if(pLampe==NULL){printf("ERROR : pLampe is NULL");while(1);}
	return pLampe;
}

/*----------OBJECT METHODS----------*/
extern void LAMPE_boutON(Lampe* pLampe){
	AMPOULE_allumer(pLampe->ampoule);
}

extern void LAMPE_boutOFF(Lampe* pLampe){
	AMPOULE_eteindre(pLampe->ampoule);
}

extern void run(Lampe* lampe, lamp_event_e event){
	lamp_state_e next_state = transition_table[lampe->lampe_state][event].next_state;
	lamp_action_e action = transition_table[lampe->lampe_state][event].action;
	if(next_state!=STATE_FORGET){
		LAMPE_performAction(lampe, action);
		lampe->lampe_state = next_state;
	}
}

extern int LAMPE_getAmpouleState(Lampe* lampe){
	int ampoule_state = AMPOULE_getState(lampe->ampoule);
	return ampoule_state;
}

static void LAMPE_performAction(Lampe* lampe, lamp_action_e action){
	switch(action){
		case ACTION_NONE:
			break;
		case ACTION_ON: AMPOULE_allumer(lampe->ampoule);
			break;
		case ACTION_OFF: AMPOULE_eteindre(lampe->ampoule);
			break;
		case ACTION_STOP: AMPOULE_eteindre(lampe->ampoule);LAMPE_free(lampe);
			break;
	default: TRACE("ERROR [] Action inconnue dans MAE Lampe \n "); break;
	}
}

/*----------OBJECT DESTRUCTORS----------*/
extern void LAMPE_free(Lampe* pLampe){
	free(pLampe);
}

