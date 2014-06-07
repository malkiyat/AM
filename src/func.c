/*****************************************************************************************
*
*	File name : func.c
*
*	Description : contains the definition of all the functions used
*
*****************************************************************************************/


/*****************************************************************************************
				HEADER FILES
*****************************************************************************************/
#include "header.h"




/*****************************************************************************************
				SERVER FUNCTIONS
*****************************************************************************************/




/*****************************************************************************************
*	Function name : s_handler
*	Description : captures the ctrl+c and terminates the program by closing all
*		      connections
*	Returns : void
*****************************************************************************************/
void s_handler(int signo)
{
        printf("\n\n\n\t\t***EXITING SERVER***\n\n\n");
        exit(1);
}





/*****************************************************************************************
*	Function name : read_data
*	Description : reads a string of data from a connection and stores it in a buffer
*		      named data
*	Returns : SUCCESS or FAILURE
*****************************************************************************************/
int read_data(int sd, char *data)
{
        int total=0,rd;
        while ((rd = read(sd,data + total,BLOCKSIZE))>0)
        {
 	       total += rd;
        }

        if ( rd < 0 )
        {
                return FAILURE;
        }

	return SUCCESS;
}





/*****************************************************************************************
*	Function name : process_data
*	Description :  count ot vowels
*	Returns : FAILURE / SUCCESS
*****************************************************************************************/
int process_data(char *str,char *output)
{
	char *input = NULL;
	int index=0,len,i,count=0;
        char word[5];
	input = (char *)calloc(50,sizeof(char));
	if ( NULL == input )
	{
		perror("memory");
		exit(1);
	}

	for ( i = 0 ; i<2 ; i++ )
	{
		count = 0;
	        sscanf(str+index,"%s",input);
		len = strlen(input);
		for ( index = 0 ; index<len ; index ++ )
		{
			if('a' == input[index]||'e' == input[index]||'i' == input[index]||'o' == input[index]||'u' == input[index]||'A' == input[index]||'E' == input[index]||'I' == input[index]||'O' == input[index]||'U' == input[index])
			{
				count++;
			}
		}

		sprintf(word,"%d ",count);
		strcat(output,word);
	}
        free(input);
        input = NULL;
	return SUCCESS;
}





/*****************************************************************************************
*	Function name : send_data
*	Description : sends a string to the data connections
*	Returns : SUCCESS or FAILURE
*****************************************************************************************/
int sv_send_data(int sd, char *data)
{
        int wrtn,total=0,n;
        n = strlen(data);
        while( total < n )
        {
                wrtn = write(sd,(data + total),(n - total));
                if ( wrtn < 0 )
                {
                        printf("\nerror in sending\n");
                        return FAILURE;
                }
                total = total + wrtn ;
        }
	return SUCCESS;

}



/*****************************************************************************************
				CLIENT FUNCTIONS
*****************************************************************************************/




/*****************************************************************************************
*       Function name : send_data
*       Description : sends data to the server
*       Returns : SUCCESS or FAILURE
*****************************************************************************************/
int cl_send_data(int sd, char *data)
{
        int wrtn,total=0,n;
        n = strlen(data);
        while( total < n )
        {
                wrtn = write(sd,(data + total),(n - total));
                if ( wrtn < 0 )
                {
                        printf("\nerror in sending\n");
                        return FAILURE;
                }
                total = total + wrtn ;
        }
	return SUCCESS;
}




/*****************************************************************************************
*       Function name : receive_data
*       Description : receives a string
*       Returns : SUCCESS / FAILURE
*****************************************************************************************/
int receive_data(int sd)
{
        char word[20];
        int total = 0,rd;
	memset(word,'\0',20);
        while( ( rd = read(sd,word+total,BLOCKSIZE)) > 0 )
        {
		total += rd;
        }

        if ( rd < 0 )
        {
                return FAILURE;
        }

	write(1,word,total);
	printf("\n\n");

        return SUCCESS;
}


