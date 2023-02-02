//socket(IP, TYPE, PROTOCOL) / bind(SOCKET, ADDRESS, ADDRESS_LENGTH) / listen(SOCKET, BACKLOG)
#include <sys/socket.h>
#include <netinet/in.h>

static int socket;
static struct sockaddr_in address_details;

extern void SOCKET_SERVER_init(){
	address_details.sin_addr = "";
}

extern void SOCKET_SERVER_connect(){
	socket = socket();
}

extern void SOCKET_SERVER_close(){
	close();
}

