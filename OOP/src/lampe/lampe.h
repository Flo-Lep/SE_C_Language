#ifndef _LAMPE_H_
#define _LAMPE_H_

#include "ampoule.h"

typedef struct Lampe_attributes Lampe;

/*CONSTRUCTORS*/
extern Lampe* LAMPE_new(void);

/*METHODS*/
extern void LAMPE_boutON(Lampe* pLampe);
extern void LAMPE_boutOFF(Lampe* pLampe);
extern int LAMPE_getAmpouleState(Lampe* lampe);

/*DESTRUCTORS*/
extern void LAMPE_free(Lampe* pLampe);

#endif /*_LAMPE_H_*/
