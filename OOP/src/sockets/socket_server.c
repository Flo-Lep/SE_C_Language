#include "socket_server.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

static int _socket_;
static int client_nbr;
static struct sockaddr_in address_details;

/*----------PRIVATE FUNCTION PROTOTYPES----------*/
static void SOCKET_SERVER_init(void);
static void SOCKET_SERVER_bind(void);
static void SOCKET_SERVER_listen(void);
static void SOCKET_SERVER_write(int client_socket, dataToSend data);
static void SOCKET_SERVER_close(void);

/*----------PUBLIC FUNCTIONS----------*/
extern void SOCKET_SERVER_start(void){
	SOCKET_SERVER_init();
	printf("Socket server intialisated on port %d\n", SOCKET_PORT);
	SOCKET_SERVER_bind();
	printf("Socket server bound\n");
	SOCKET_SERVER_listen();
}

extern void SOCKET_SERVER_stop(void){
	SOCKET_SERVER_close();
}

/*----------PRIVATE FUNCTIONS----------*/
static void SOCKET_SERVER_init(void){
	client_nbr = 0;
	_socket_ = socket(SOCKET_IP_ADDRESS, SOCKET_TYPE, SOCKET_PROTOCOL);
	address_details.sin_family = SOCKET_FAMILY;
	address_details.sin_port = htons(SOCKET_PORT);
	address_details.sin_addr.s_addr = htonl(SOCKET_IN_ADDRESS);
}

static void SOCKET_SERVER_bind(void){
	bind(_socket_, (struct sockaddr *)&address_details, sizeof(address_details));
}

static void SOCKET_SERVER_listen(void){
	printf("Going to listen");
	listen(_socket_, MAX_PENDING_CONNECTIONS);
	printf("Socket server listening for incoming connections...");
	while(1)
	{
		int client_socket;
		client_socket = accept(_socket_, NULL, 0);
		if(fork () == 0){
			dataToSend data;
			strcpy (data.message, "Welcome");
			data.clients = htonl(client_nbr);
			SOCKET_SERVER_write(client_socket, data);
			exit(0);
		}
	}
}

static void SOCKET_SERVER_write(int client_socket, dataToSend data){
	write(client_socket, &data, sizeof(data));
}

static void SOCKET_SERVER_close(void){
	close(_socket_);
	client_nbr =0;
}

//main
