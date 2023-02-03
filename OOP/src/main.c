#include <stdio.h>
#include <stdlib.h>
#include "lampe/ampoule.h"
#include "lampe/lampe.h"
#include "sockets/socket_server.h"

/*
int main(int argc, char **argv) {
	printf("Starting Prog...\n");
	Lampe* lampe1 = LAMPE_new();
	printf("%d\n",LAMPE_getAmpouleState(lampe1));
	LAMPE_boutON(lampe1);
	printf("%d\n",LAMPE_getAmpouleState(lampe1));
	LAMPE_boutOFF(lampe1);
	printf("%d\n",LAMPE_getAmpouleState(lampe1));
	LAMPE_free(lampe1);
	printf("Exit\n");
	return 0;
}*/

int main(int argc, char **argv) {
	SOCKET_SERVER_start();
	return 0;
}

