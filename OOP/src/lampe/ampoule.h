#ifndef _AMPOULE_H_
#define _AMPOULE_H_

typedef struct Ampoule_attributes Ampoule;

/*CONSTRUCTORS*/
extern Ampoule* AMPOULE_new(void);

/*METHODS*/
extern void AMPOULE_allumer(Ampoule* pAmpoule);
extern void AMPOULE_eteindre(Ampoule* pAmpoule);
extern int AMPOULE_getState(Ampoule* ampoule);

/*DESTRUCTORS*/
extern void AMPOULE_free(Ampoule* pAmpoule);

#endif /*_AMPOULE_H_*/
