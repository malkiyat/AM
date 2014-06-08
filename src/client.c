/*****************************************************************************************
*
*       File name : client.c
*
*       Description : connects to a server, sends a concatinated string and accepts the
*		      string along with the string lenght and prints the string
*
*****************************************************************************************/


/*****************************************************************************************
                                HEADER FILES
*****************************************************************************************/
#include "header.h"



/*****************************************************************************************
*       Function name : main
*       Description : creates a client connection and sends a concatinated string to the
*                     server n recieves the output string
*       Returns : SUCCESS or FAILURE
*****************************************************************************************/


int main(int argc, char *argv[])
{
	int sd,check;
	char data[100] = {'\0'};
	struct sockaddr_in saddr;
	sd = socket( AF_INET , SOCK_STREAM , 0 );
	if ( sd < 0 )
	{
		perror("Socket ");
		exit(1);
	}
	
	if ( argc != 4 )
	{
		printf("\nIncorrect usage \ncorrect format ./<executable> <ip addr> <port no(30001)> ON/OFF \n");
		exit(1);
	}
	
	memset(&saddr,0,sizeof(saddr));
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(atoi(argv[2]));
	saddr.sin_addr.s_addr = inet_addr(argv[1]);

	check = connect(sd,(struct sockaddr *)&saddr,sizeof(saddr));
	if ( check < 0 )
	{
		printf("\ncould not connect\n");
		exit(0);
	}

        strcpy(data,argv[3]);

        if( cl_send_data(sd,data) == FAILURE )
	{
		printf("\nfailed to sent\n");
		exit(1);
	}

        shutdown(sd,SHUT_WR);

        check = receive_data(sd);
	if( FAILURE == check )
	{
		printf("\nerror in receiving data\n");
		exit(0);
	}
	exit(0);
}

