
/*****************************************************************************************
*
*       File name : server.c
*
*       Description : creates a server and waits for clients to connect. Accepts a 
*		      concatinated string and appends the string lenght of each string 
*		      and sends back the string to the client
*
*****************************************************************************************/


/*****************************************************************************************
                                HEADER FILES
*****************************************************************************************/

#include "header.h"



/*****************************************************************************************
*       Function name : main
*       Description : opens a server connection and waits for a client to connect and 
*                     does the required fuction
*       Returns : SUCCESS or FAILURE
*****************************************************************************************/
int main()
{
	signal(SIGINT,s_handler);

	int sd,new_sd;
	int check = 0;
	socklen_t len;
	char data[100] = {'\0'};
        char output[100] = {'\0'};

        struct sockaddr_in saddr,cliaddr;

        sd = socket( AF_INET, SOCK_STREAM, 0);
        if ( sd < 0 )
        {
                perror("socket");
                exit(1);
        }

        memset(&saddr,0,sizeof(saddr));
        saddr.sin_family = AF_INET;
        saddr.sin_port = htons(MYPORT);
        saddr.sin_addr.s_addr = htonl(INADDR_ANY);

        check = bind(sd,(struct sockaddr *)&saddr,sizeof(saddr));
        if ( check < 0 )
        {
                perror("bind");
                exit(1);
        }

        check = listen(sd,5);
	if ( check < 0 )
	{
		perror("listen");
		exit(1);
	}
	
        while (1)
        {
                printf("\nwaiting for a client...\n");
                len = sizeof(cliaddr);
                new_sd = accept(sd,(struct sockaddr *)&cliaddr,&len);
                if ( new_sd < 0 )
                {
                        perror("accept");
                        continue;
                }
                else
                {
			memset(data,'\0',100);
		        memset(output,'\0',100);
			check = read_data(new_sd,data);
			if ( FAILURE == check )
			{
			        perror("read");
		                close(new_sd);
				exit(1);
		        }

			if(!strcmp(data,"ON"))
			{
				printf("status is ON");
			}

			if(!strcmp(data,"OFF"))
                        {
                                printf("status is OFF");
                        }

			if ( FAILURE == check )
			{
			        perror("memory");
		                close(new_sd);
				exit(1);
		        }


			check = sv_send_data(new_sd,output);
			if ( FAILURE == check )
			{
			        perror("write");
		                close(new_sd);
				exit(1);
		        }

		  
	        	printf("\nfinished processing\n");
			close(new_sd);
                }

        }

        return 0;

}

