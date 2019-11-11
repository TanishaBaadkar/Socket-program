#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <signal.h>
#include <sys/wait.h>


#define PORT 4431

#define PORT1 22131
#define PORT2 22231
#define PORT3 22331
#define PORT4 22431
#define PORT5 22531

#define PORT6 4031 //part4-sellerA
#define PORT7 4131 //part4-sellerB

#define PORT8 4631 // part4-buyer1
#define PORT9 4731 //part4-buyer2
#define PORT10 4831 // part4-buyer3
#define PORT11 4931 //part4-buyer4
#define PORT12 5031 //part4-buyer5
int main(){

	int sockfd, ret;
	 struct sockaddr_in serverAddr;

	int newSocket;
	struct sockaddr_in newAddr;

	socklen_t addr_size;

	char buffer[2024];
	pid_t childpid;
	


	int yes =1;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
	{
		printf("[-]Error in connection.\n");
		exit(1);
	}
	//printf("[+]Server Socket is created.\n");

	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
        perror("setsockopt");
        exit(1);
    }

	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = INADDR_ANY;;

	ret = bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if(ret < 0)
	{
		printf("[-]Error in binding.\n");
		exit(1);
	}
	printf("The <Agent1>has TCPport %d and IP address %s for Phase 1 part 1\n\n",ntohs(serverAddr.sin_port),inet_ntoa(serverAddr.sin_addr)); 

	if(listen(sockfd, 20) == 0)
	{
		//printf("[+]Listening....\n");
	}else
	{
		printf("[-]Error in binding.\n");
	}
 
 int i=0;
 int j;
 
	for(j=0;j<2;j++)
	{
		newSocket = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);
		if(newSocket < 0)
		{
			perror("accept");
			exit(1);
		}
		
		
      
		//printf("Connection accepted from %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));

		if((childpid = fork()) == 0)
		{
			//close(sockfd);

			
                FILE *fp;

            
				recv(newSocket, buffer, 2024, 0);
				if(strcmp(buffer,"A")==0)
					fp = fopen("A.txt", "w+");
				else if(strcmp(buffer,"B")==0)
				   fp = fopen("B.txt", "w+");
				
				printf("Received house information from <Seller %s>\n\n",buffer);

				   fprintf(fp,"%s\n", buffer);
					//printf("Client: %s\n", buffer);
					
					bzero(buffer, sizeof(buffer));
               sleep(1);

				recv(newSocket, buffer, 2024, 0);
				     fprintf(fp,"%s", buffer);
					//printf("Client: %s\n", buffer);
					
					bzero(buffer, sizeof(buffer));
                  sleep(1);
				recv(newSocket, buffer, 2024, 0);
				     fprintf(fp,"%s\n", buffer);
					//printf("Client: %s", buffer);


					
					bzero(buffer, sizeof(buffer));
				    
				    fclose(fp);
                     
                    exit(0);
				
		}


    }

close(newSocket);
              
int status;
pid_t pid;
int n=2;
while (n > 0) 
{
  pid = wait(&status);
  //printf("Child with PID %ld exited with status 0x%x.\n", (long)pid, status);
  --n;  
}
                        
	//close(sockfd);
printf("End of Phase 1 part 1 for <Agent1>\n\n");

//printf("wohoo" );
sleep(50);

 FILE* fp1;
 FILE* fp2;
 char buffer2[1024]="";
 char buffer3[1024]="";
 char buf[1024];
 char buf2[1024];

  if ((fp1 = fopen("A.txt", "r")) == NULL)
  { /* Open source file. */
    perror("fopen source-file");
    return 1;
  }

  if ((fp2 = fopen("B.txt", "r")) == NULL)
  { /* Open source file. */
    perror("fopen source-file");
    return 1;
  }

  while (fgets(buf, sizeof(buf), fp1) != NULL)
  {
    strcat(buffer2, buf);
//printf("array ----> %s \n", &buffer2);

  }

//strcat(buffer2, "\n");

while (fgets(buf2, sizeof(buf2), fp2) != NULL)
  {
    strcat(buffer3, buf2);
//printf("array ----> %s \n", &buffer2);

  }

strcat(buffer2,buffer3);
fclose(fp1);
fclose(fp2);

///First

int q;
char str1[30] = "Hello", *ptr1, c = '\n';
char str2[30] = {0}, *ptr2;
ptr1 = buffer2;
ptr2 = str2;
for (q=0; q<strlen(buffer2); q++)
{
    if (*ptr1 != c) *ptr2++=*ptr1;
    ptr1++;
}


int sockfd2;
    //char buffer2[1024]="A\nListing price:280000\nSquare footage:2500";	
    struct sockaddr_in ser;
    struct hostent *he;

     if ( (sockfd2 = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

if ((he = gethostbyname("nunki.usc.edu"))==NULL) {
        fprintf(stderr, "Cannot get host name\n");
        exit(1);
    }


    memset(&ser, 0, sizeof(ser));

    

    ser.sin_family = AF_INET;
    ser.sin_port = htons(PORT1);
    ser.sin_addr = *((struct in_addr *)he->h_addr);;

     
     
    sendto(sockfd2, (char *)buffer2, 1024,0, (const struct sockaddr *) &ser, 
            sizeof(ser));
   // printf("Hello message sent.\n");

    char myIP[16];
	unsigned int myPort;
	struct sockaddr_in my_addr;

	bzero(&my_addr, sizeof(my_addr));
	int len = sizeof(my_addr);
	getsockname(sockfd2, (struct sockaddr *) &my_addr, &len);
	inet_ntop(AF_INET, &my_addr.sin_addr, myIP, sizeof(myIP));
	myPort = ntohs(my_addr.sin_port);

	printf("The<Agent1> has UDPport %d and IP address %s for Phase 1 part 2\n\n", myPort, myIP);
    printf("<Agent1> has sent < %s > to <Buyer1>\n\n",str2);
///second
    int sockfd3;
    //char buffer2[1024]="A\nListing price:280000\nSquare footage:2500";	
    struct sockaddr_in ser1;

    if ( (sockfd3 = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
   
    memset(&ser1, 0, sizeof(ser1));

    

    ser1.sin_family = AF_INET;
    ser1.sin_port = htons(PORT2);
    ser1.sin_addr = *((struct in_addr *)he->h_addr);;

     
     
    sendto(sockfd3, (char *)buffer2, 1024,0, (const struct sockaddr *) &ser1, sizeof(ser1));
    
    printf("<Agent1> has sent < %s > to <Buyer2>\n\n",str2);

    ///third

    int sockfd4;
    //char buffer2[1024]="A\nListing price:280000\nSquare footage:2500";	
    struct sockaddr_in ser2;

    if ( (sockfd4 = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
   
    memset(&ser2, 0, sizeof(ser2));

    

    ser2.sin_family = AF_INET;
    ser2.sin_port = htons(PORT3);
    ser2.sin_addr = *((struct in_addr *)he->h_addr);;

     
     
    sendto(sockfd4, (char *)buffer2, 1024,0, (const struct sockaddr *) &ser2, sizeof(ser2));
    
    printf("<Agent1> has sent < %s > to <Buyer3>\n\n",str2);

    ///fourth

    int sockfd5;
    //char buffer2[1024]="A\nListing price:280000\nSquare footage:2500";	
    struct sockaddr_in ser3;

    if ( (sockfd5 = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
   
    memset(&ser3, 0, sizeof(ser3));

    

    ser3.sin_family = AF_INET;
    ser3.sin_port = htons(PORT4);
    ser3.sin_addr = *((struct in_addr *)he->h_addr);;

     
     
    sendto(sockfd5, (char *)buffer2, 1024,0, (const struct sockaddr *) &ser3, sizeof(ser3));
    
    printf("<Agent1> has sent < %s > to <Buyer4>\n\n",str2);


///fifth
    int sockfd6;
    //char buffer2[1024]="A\nListing price:280000\nSquare footage:2500";	
    struct sockaddr_in ser4;

    if ( (sockfd6 = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
   
    memset(&ser4, 0, sizeof(ser4));

    

    ser4.sin_family = AF_INET;
    ser4.sin_port = htons(PORT5);
    ser4.sin_addr = *((struct in_addr *)he->h_addr);;

     
     
    sendto(sockfd6, (char *)buffer2, 1024,0, (const struct sockaddr *) &ser4, sizeof(ser4));
    printf("<Agent1> has sent < %s > to <Buyer5>\n\n",str2);

printf("End of Phase 1 part 2 for <Agent1>\n\n");
    //PART 3

    /*int sockfd1, ret1;
	 struct sockaddr_in serverAddr1;

	int newSocket1;
	struct sockaddr_in newAddr1;

	socklen_t addr_size1;
*/
	char buffer1[2024];
	pid_t childpid1;

	
	//sleep(100);	

	
int newSocket1;	

	
printf("The<Agent1> has TCPport %d and IP address %s for Phase 1 part 3\n\n",ntohs(serverAddr.sin_port),inet_ntoa(serverAddr.sin_addr));
	
 int k=0;
 int l;
 
	for(l=0;l<5;l++)
	{
		
		newSocket1 = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);
		if(newSocket1< 0)
		{
			perror("accept");
			exit(1);
		}
		
		
      
		//printf("Connection accepted from %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));

		if((childpid1 = fork()) == 0)
		{
			//close(sockfd);

		
               
            
				recv(newSocket1, buffer1, 2024, 0);
				
				
				   
					//printf("part3: %s\n", buffer1);
					if(strncmp(&buffer1[0],"1",1)==0)
					{
						printf("<Agent1>receives the offer from <Buyer 1>\n\n");
					fp1=fopen("A1B1.txt", "w+");
				    }
				    if(strncmp(&buffer1[0],"2",1)==0)
				    {
				    	printf("<Agent1>receives the offer from <Buyer 2>\n\n");
					fp1=fopen("A1B2.txt", "w+");
				}
				    if(strncmp(&buffer1[0],"3",1)==0)
				    {
				    	printf("<Agent1>receives the offer from <Buyer 3>\n\n");
					fp1=fopen("A1B3.txt", "w+");
				}
				    if(strncmp(&buffer1[0],"4",1)==0)
				    {
				    	printf("<Agent1>receives the offer from <Buyer 4>\n\n");
					fp1=fopen("A1B4.txt", "w+");
				}
				    if(strncmp(&buffer1[0],"5",1)==0)
				    {
					fp1=fopen("A1B5.txt", "w+");
                    printf("<Agent1>receives the offer from <Buyer 5>\n\n");
                }
				   fprintf(fp1,"%s", buffer1);
					
					bzero(buffer1, sizeof(buffer1));
                     
                    exit(0);
				
		}


    }

  pid = wait(&status);
  //printf("Child with PID %ld exited with status 0x%x.\n", (long)pid, status);

  pid = wait(&status);
  //printf("Child with PID %ld exited with status 0x%x.\n", (long)pid, status);

  pid = wait(&status);
 // printf("Child with PID %ld exited with status 0x%x.\n", (long)pid, status);

  pid = wait(&status);
 // printf("Child with PID %ld exited with status 0x%x.\n", (long)pid, status);

  pid = wait(&status);
  //printf("Child with PID %ld exited with status 0x%x.\n", (long)pid, status);
  //printf("done done done");

  printf("End of Phase 1 part 3 for <Agent1>\n\n");

  struct bid
  {
  	int name;
  	int budget;
  	const char* p1;
   const char* p2;
  } buyer[5];



char b[4][1024];
char bu[1024];
  if ((fp2 = fopen("A1B1.txt", "r")) == NULL)
  { /* Open source file. */
    perror("fopen source-file");
    return 1;
  }

  

int u=0;
  while (fgets(bu, sizeof(bu), fp2) != NULL)
  {
    strcat(b[u], bu);
//printf("array ----> %s \n", &buffer2);
u++;
  }

fclose(fp2);

buyer[0].name=1;
buyer[0].budget=atoi(b[1]);
buyer[0].p1=b[2];
buyer[0].p2=b[3];

//printf("please work%s",buyer[0].p1);


  if ((fp2 = fopen("A1B2.txt", "r")) == NULL)
  { /* Open source file. */
    perror("fopen source-file");
    return 1;
  }

  char b1[4][1024];
char bu1[1024];

u=0;
  while (fgets(bu1, sizeof(bu1), fp2) != NULL)
  {
    strcat(b1[u], bu1);
//printf("array ----> %s \n", &buffer2);
u++;
  }

fclose(fp2);

buyer[1].name=2;
buyer[1].budget=atoi(b1[1]);
buyer[1].p1=b1[2];
buyer[1].p2=b1[3];

//printf("please work%s",buyer[1].p1);

if ((fp2 = fopen("A1B3.txt", "r")) == NULL)
  { /* Open source file. */
    perror("fopen source-file");
    return 1;
  }

 char b2[4][1024];
char bu2[1024]; 

 u=0;
  while (fgets(bu2, sizeof(bu2), fp2) != NULL)
  {
    strcat(b2[u], bu2);
//printf("array ----> %s \n", &buffer2);
u++;
  }

fclose(fp2);

buyer[2].name=3;
buyer[2].budget=atoi(b2[1]);
buyer[2].p1=b2[2];
buyer[2].p2=b2[3];

//printf("please work%s",buyer[2].p1);

if ((fp2 = fopen("A1B4.txt", "r")) == NULL)
  { /* Open source file. */
    perror("fopen source-file");
    return 1;
  }

  char b3[4][1024];
char bu3[1024];

 u=0;
  while (fgets(bu3, sizeof(bu3), fp2) != NULL)
  {
    strcat(b3[u], bu3);
//printf("array ----> %s \n", &buffer2);
u++;
  }

fclose(fp2);

buyer[3].name=4;
buyer[3].budget=atoi(b3[1]);
buyer[3].p1=b3[2];
buyer[3].p2=b3[3];

//printf("please work%s",buyer[3].p1);

if ((fp2 = fopen("A1B5.txt", "r")) == NULL)
  { /* Open source file. */
    perror("fopen source-file");
    return 1;
  }

  char b4[4][1024];
char bu4[1024];

u=0;
  while (fgets(bu4, sizeof(bu4), fp2) != NULL)
  {
    strcat(b4[u], bu4);
//printf("array ----> %s \n", &buffer2);
u++;
  }

fclose(fp2);

buyer[4].name=5;
buyer[4].budget=atoi(b4[1]);
buyer[4].p1=b4[2];
buyer[4].p2=b4[3];

//printf("please work%s",buyer[4].p1);




struct sellerA
{
int name;
int budget;
} buyersA[10];

struct sellerB
{
int name;
int budget;
} buyersB[10];

int r;

for(r=0;r<10;r++)
{
	buyersA[r].budget=0;
}

for(r=0;r<10;r++)
{
	buyersB[r].budget=0;
}
int t=0;
//printf("now%s",buyer[0].p1);

for(r=0;r<5;r++)
{
if(strncmp(buyer[r].p1,"A",1)==0)
{
	 //printf("going inside");
	buyersA[t].name=buyer[r].name;
	buyersA[t].budget=buyer[r].budget;
	t++;
}
}

for(r=0;r<5;r++)
{
if(strncmp(buyer[r].p2,"A",1)==0)
{
	buyersA[t].name=buyer[r].name;
	buyersA[t].budget=buyer[r].budget;
	t++;
}

}

 t=0;
for(r=0;r<5;r++)
{
if(strncmp(buyer[r].p1,"B",1)==0)
{
	buyersB[t].name=buyer[r].name;
	buyersB[t].budget=buyer[r].budget;
	t++;
}
}

for(r=0;r<5;r++)
{
if(strncmp(buyer[r].p2,"B",1)==0)
{
	buyersB[t].name=buyer[r].name;
	buyersB[t].budget=buyer[r].budget;
	t++;
}

}


char resultA[100];
if(buyersA[0].budget==0)
	strcpy(resultA,"NAK");

char resultB[100];
if(buyersB[0].budget==0)
	strcpy(resultB,"NAK");

int costA=0;
int nameA=0;
u=0; //A
r=0;
int costB=0;
int nameB=0;
t=0;
for(t=0;t<10;t++)
{
	if(buyersA[t].budget>costA)
	{
		costA=buyersA[t].budget;
         u=nameA;
		nameA=buyersA[t].name;
	}
}


for(t=0;t<10;t++)
{
	if(buyersB[t].budget>costB)
	{
		costB=buyersB[t].budget;
		r=nameB;
		nameB=buyersB[t].name;
	}
}
 
 if(nameA==nameB)
 {
 	if(strncmp(buyer[nameA-1].p1,"A",1)==0)
 	{
 		nameB=r;
 	}

 	if(strncmp(buyer[nameA-1].p1,"B",1)==0)
 	{
 		nameA=u;
 	}
 }
//printf("nameA%d",nameA);
//printf("nameB%d",nameB);

if(nameA==0)
strcpy(resultA,"NAK");

else 
	sprintf(resultA, "%d", nameA);

if(nameB==0)
strcpy(resultB,"NAK");
else
	sprintf(resultB, "%d", nameB);






//struct sockaddr_in s;
    
    //int soc1;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0))== -1) {
        fprintf(stderr, "Socket Failure!!\n");
        exit(1);
    }

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT6);
    serverAddr.sin_addr = *((struct in_addr *)he->h_addr);
    if (connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(struct sockaddr))<0) {
        //printf("last one");
        perror("connect");
        exit(1);
    }

    if ((send(sockfd,resultA, strlen(resultA),0))== -1)
         {
            fprintf(stderr, "Failure Sending Message\n");
            close(sockfd);
            exit(1);
        }



	bzero(&my_addr, sizeof(my_addr));
	 len = sizeof(my_addr);
	getsockname(sockfd, (struct sockaddr *) &my_addr, &len);
	inet_ntop(AF_INET, &my_addr.sin_addr, myIP, sizeof(myIP));
	myPort = ntohs(my_addr.sin_port);

	printf("The<Agent1> has TCP port %d and IP address %s for Phase 1 part 4\n\n", myPort, myIP);

	printf("The <Agent1> has send the result to <SellerA>\n\n");


    if ((sockfd2 = socket(AF_INET, SOCK_STREAM, 0))== -1) {
        fprintf(stderr, "Socket Failure!!\n");
        exit(1);
    }

    memset(&ser, 0, sizeof(ser));
    ser.sin_family = AF_INET;
    ser.sin_port = htons(PORT7);
    ser.sin_addr = *((struct in_addr *)he->h_addr);
    if (connect(sockfd2, (struct sockaddr *)&ser, sizeof(struct sockaddr))<0) {
        
        perror("connect");
        exit(1);
    }

    if ((send(sockfd2,resultB, strlen(resultB),0))== -1)
         {
            fprintf(stderr, "Failure Sending Message\n");
            close(sockfd2);
            exit(1);
        }

        printf("The <Agent1> has send the result to <SellerB>\n\n");

close(sockfd2);
    char bres[10];

    if(strncmp(buyer[0].p1,"NAK",3)!=0)
    {
    	if(nameA==1)
    		strcpy(bres,"A");
    	else if (nameB==1)
    		strcpy(bres,"B");
    	else strcpy(bres,"NAK");


    	if ((sockfd2 = socket(AF_INET, SOCK_STREAM, 0))== -1) {
        fprintf(stderr, "Socket Failure!!\n");
        exit(1);
    }

    memset(&ser, 0, sizeof(ser));
    ser.sin_family = AF_INET;
    ser.sin_port = htons(PORT8);
    ser.sin_addr = *((struct in_addr *)he->h_addr);
    if (connect(sockfd2, (struct sockaddr *)&ser, sizeof(struct sockaddr))<0) {
        
        perror("connect");
        exit(1);
    }

    if ((send(sockfd2,bres, strlen(bres),0))== -1)
         {
            fprintf(stderr, "Failure Sending Message\n");
            close(sockfd2);
            exit(1);
        }
printf("The <Agent1> has send the result to <Buyer1>\n\n");
close(sockfd2);
 }
sleep(5);
if(strncmp(buyer[1].p1,"NAK",3)!=0)
    {
    	if(nameA==2)
    		strcpy(bres,"A");
    	else if (nameB==2)
    		strcpy(bres,"B");
    	else strcpy(bres,"NAK");


    	if ((sockfd2 = socket(AF_INET, SOCK_STREAM, 0))== -1) {
        fprintf(stderr, "Socket Failure!!\n");
        exit(1);
    }

    memset(&ser, 0, sizeof(ser));
    ser.sin_family = AF_INET;
    ser.sin_port = htons(PORT9);
    ser.sin_addr = *((struct in_addr *)he->h_addr);
    if (connect(sockfd2, (struct sockaddr *)&ser, sizeof(struct sockaddr))<0) {
        
        perror("connect");
        exit(1);
    }

    if ((send(sockfd2,bres, strlen(bres),0))== -1)
         {
            fprintf(stderr, "Failure Sending Message\n");
            close(sockfd2);
            exit(1);
        }
printf("The <Agent1> has send the result to <Buyer2>\n\n");
close(sockfd2);
 }
sleep(5);
 if(strncmp(buyer[2].p1,"NAK",3)!=0)
    {
    	if(nameA==3)
    		strcpy(bres,"A");
    	else if (nameB==3)
    		strcpy(bres,"B");
    	else strcpy(bres,"NAK");


    	if ((sockfd2 = socket(AF_INET, SOCK_STREAM, 0))== -1) {
        fprintf(stderr, "Socket Failure!!\n");
        exit(1);
    }

    memset(&ser, 0, sizeof(ser));
    ser.sin_family = AF_INET;
    ser.sin_port = htons(PORT10);
    ser.sin_addr = *((struct in_addr *)he->h_addr);
    if (connect(sockfd2, (struct sockaddr *)&ser, sizeof(struct sockaddr))<0) {
        
        perror("connect");
        exit(1);
    }

    if ((send(sockfd2,bres, strlen(bres),0))== -1)
         {
            fprintf(stderr, "Failure Sending Message\n");
            close(sockfd2);
            exit(1);
        }
printf("The <Agent1> has send the result to <Buyer3>\n\n");
close(sockfd2);
 }
sleep(5);
 if(strncmp(buyer[3].p1,"NAK",3)!=0)
    {
    	if(nameA==4)
    		strcpy(bres,"A");
    	else if (nameB==4)
    		strcpy(bres,"B");
    	else strcpy(bres,"NAK");


    	if ((sockfd2 = socket(AF_INET, SOCK_STREAM, 0))== -1) {
        fprintf(stderr, "Socket Failure!!\n");
        exit(1);
    }

    memset(&ser, 0, sizeof(ser));
    ser.sin_family = AF_INET;
    ser.sin_port = htons(PORT11);
    ser.sin_addr = *((struct in_addr *)he->h_addr);
    if (connect(sockfd2, (struct sockaddr *)&ser, sizeof(struct sockaddr))<0) {
        
        perror("connect");
        exit(1);
    }

    if ((send(sockfd2,bres, strlen(bres),0))== -1)
         {
            fprintf(stderr, "Failure Sending Message\n");
            close(sockfd2);
            exit(1);
        }
printf("The <Agent1> has send the result to <Buyer4>\n\n");
close(sockfd2);
 }
sleep(5);
 if(strncmp(buyer[4].p1,"NAK",3)!=0)
    {
    	if(nameA==5)
    		strcpy(bres,"A");
    	else if (nameB==5)
    		strcpy(bres,"B");
    	else strcpy(bres,"NAK");


    	if ((sockfd2 = socket(AF_INET, SOCK_STREAM, 0))== -1) {
        fprintf(stderr, "Socket Failure!!\n");
        exit(1);
    }

    memset(&ser, 0, sizeof(ser));
    ser.sin_family = AF_INET;
    ser.sin_port = htons(PORT12);
    ser.sin_addr = *((struct in_addr *)he->h_addr);
    if (connect(sockfd2, (struct sockaddr *)&ser, sizeof(struct sockaddr))<0) {
        
        perror("connect");
        exit(1);
    }

    if ((send(sockfd2,bres, strlen(bres),0))== -1)
         {
            fprintf(stderr, "Failure Sending Message\n");
            close(sockfd2);
            exit(1);
        }
printf("The <Agent1> has send the result to <Buyer5>\n\n");
close(sockfd2);
 }
printf("End of Phase 1 part 4 for <Agent1>");
	exit(0);
}