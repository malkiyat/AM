/*****************************************************************************************
*
*       File name : func.c
*
*       Description : contains the definition of all the functions used
*
*****************************************************************************************/


/*****************************************************************************************
                                HEADER FILES
*****************************************************************************************/

#include        <stdio.h>
#include        <stdlib.h>
#include        <errno.h>
#include        <string.h>
#include        <sys/types.h>
#include        <sys/socket.h>
#include        <netinet/in.h>
#include        <arpa/inet.h>
#include        <sys/wait.h>
#include        <fcntl.h>
#include        <unistd.h>
#include        <signal.h>
#include        <sys/stat.h>

/*****************************************************************************************
                                MACROS
*****************************************************************************************/
#define MYPORT 30001
#define FAILURE 0
#define SUCCESS 1
#define BLOCKSIZE 20

/*****************************************************************************************
                                CLIENT FUNCTIONS
*****************************************************************************************/
int cl_send_data(int,char *);
int receive_data(int);


/*****************************************************************************************
                                SERVER FUNCTIONS
*****************************************************************************************/
void s_handler(int);
int read_data(int,char *);
int process_data(char *,char *);
int sv_send_data(int,char *);
