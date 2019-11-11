#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <sys/wait.h>

#define PORT 4531
#define bufSize 1024
#define PORT1 4331

int main(){

	int clientSocket, ret;
	struct sockaddr_in serverAddr,my_addr;
	char buffer[5][1024];
	char buf[bufSize];
	 struct hostent *he;
	 FILE* fp;
	 char myIP[16];
	unsigned int myPort;

	 if ((he = gethostbyname("nunki.usc.edu"))==NULL) {
        fprintf(stderr, "Cannot get host name\n");
        exit(1);
    }

	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if(clientSocket < 0){
		printf("[-]Error in connection.\n");
		exit(1);
	}
	//printf("[+]Client Socket is created.\n");

	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr = *((struct in_addr *)he->h_addr);
//sleep(5);
	ret = connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if(ret < 0){
		printf("[-]Error in connection.\n");
		exit(1);
	}
	//printf("[+]Connected to Server.\n");

	//while(1){
		//printf("Client: \t");
		//scanf("%s", &buffer[0]);

        if ((fp = fopen("sellerD.txt", "r")) == NULL)
  { /* Open source file. */
    perror("fopen source-file");
    return 1;
  }
  strcpy(buffer[0],"D");
int i=1;
while (fgets(buf, sizeof(buf), fp) != NULL)
  {
    strcpy(buffer[i], buf);
//printf("array ----> %s \n", &buffer[i]);
i++;
  }
  fclose(fp);

//sleep(10);
      
if(send(clientSocket, buffer[0], 4, 0)==-1)
		{
			fprintf(stderr, "Failure Sending Message\n");
            close(clientSocket);
		}
		sleep(1);

		bzero(&my_addr, sizeof(my_addr));
	int len = sizeof(my_addr);
	getsockname(clientSocket, (struct sockaddr *) &my_addr, &len);
	inet_ntop(AF_INET, &my_addr.sin_addr, myIP, sizeof(myIP));
	myPort = ntohs(my_addr.sin_port);

	printf("<SellerD> has TCP port %u and IP address %s for Phase 1 part 1\n\n", myPort, myIP);
	printf("<SellerD> is now connected to the <agent2>\n\n");
		if(send(clientSocket, buffer[1], 1024, 0)==-1)
		{
			fprintf(stderr, "Failure Sending Message\n");
            close(clientSocket);
		} 
		sleep(1);
		
		if(send(clientSocket, buffer[2], 1024, 0)==-1)
		{
			fprintf(stderr, "Failure Sending Message\n");
            close(clientSocket);
		}

		
printf("<SellerD> has sent <Seller: %s, %s, %s > to the agent\n\nEnd of Phase 1 part 1 for <SellerD>\n\n",buffer[0],buffer[1],buffer[2]);	
		struct sockaddr_in server;
    struct sockaddr_in dest;
    int status,socket_fd, client_fd,num,num2;

    char b[10241];

    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0))== -1) {
        fprintf(stderr, "Socket failure!!\n");
        exit(1);
    }

     
    memset(&server, 0, sizeof(server));
    memset(&dest,0,sizeof(dest));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT1);
    server.sin_addr.s_addr = INADDR_ANY;

    if ((bind(socket_fd, (struct sockaddr *)&server, sizeof(struct sockaddr )))== -1)    { //sizeof(struct sockaddr) 
        fprintf(stderr, "Binding Failure\n");
        exit(1);
    }
printf("<SellerD> has TCP port %d and IP address %s for Phase 1 part 4\n\n",ntohs(server.sin_port),inet_ntoa(server.sin_addr));
    if ((listen(socket_fd, 2))== -1){
        fprintf(stderr, "Listening Failure\n");
        exit(1);
    }
socklen_t size;
size = sizeof(struct sockaddr_in);

        if ((client_fd = accept(socket_fd, (struct sockaddr *)&dest, &size))==-1 ) {
            perror("accept");
            exit(1);
        }
        //printf("Server got connection from client %s\n", inet_ntoa(dest.sin_addr));

        //while(1) {

                if ((num = recv(client_fd, b, 1024,0))== -1) {
                        perror("recv");
                        exit(1);
                }
                else if (num == 0) {
                        printf("Connection closed\n");
                        //So I can now wait for another client
                       // break;
                }
                b[num] = '\0';
                
               if(strncmp(b,"NAK",3)==0)
                	printf("NAK\n\n");
                else
                printf("<Buyer %s> buy my house\n\n", b);


printf("End of Phase 1 part 4for <SellerD>");
	return 0;
}