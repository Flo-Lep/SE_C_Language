#ifndef _SERVER_H_
#define _SERVER_H_

#include <sys/socket.h>

#define SOCKET_IP_ADDRESS		PF_INET
#define SOCKET_PORT				5001
#define SOCKET_TYPE 			SOCK_STREAM
#define SOCKET_FAMILY			AF_INET
#define SOCKET_IN_ADDRESS		INADDR_ANY
#define SOCKET_PROTOCOL			0
#define MAX_PENDING_CONNECTIONS 5

typedef struct
{
	char message[12];
	int clients;
}dataToSend;

extern void SOCKET_SERVER_start(void);

extern void SOCKET_SERVER_stop(void);

#endif /*_SERVER_H_*/
