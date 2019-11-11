#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>
#include <netdb.h>
#include <sys/wait.h>
#include <stdlib.h>
 
#define PORT 22131 //part2
#define MAXLINE 1024
#define PORT1 4431 //part3-agent1
#define PORT2 4531 //part3-agent2
#define PORT3 4631 //part4

int main() {
    int sockfd;
    char buffer[MAXLINE];
    pid_t childpid;
    struct sockaddr_in servaddr, cliaddr;
     
    // Creating socket file descriptor
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
     
    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));
     
    // Filling server information
    servaddr.sin_family    = AF_INET; // IPv4
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);
     
    // Bind the socket with the server address
    if ( bind(sockfd, (const struct sockaddr *)&servaddr, 
            sizeof(servaddr)) < 0 )
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
     
    printf("The <Buyer1>has UDPport %d and IP address %s for Phase 1 part 2\n\n",ntohs(servaddr.sin_port),inet_ntoa(servaddr.sin_addr));
     int i;

     for(i=0;i<2;i++)
     {
     if((childpid = fork()) == 0)
     {
    int len, n;
    FILE* f;
    n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, ( struct sockaddr *) &cliaddr,&len);
    buffer[n] = '\0';
    //printf("%s", &buffer[1]);
    if(strncmp(&buffer[0],"A",1)==0)
    {
        printf("Received house information from <Agent1>\n\n");
        f=fopen("B11.txt", "w+");
    }
    if(strncmp(&buffer[0],"B",1)==0)
    {
        printf("Received house information from <Agent1>\n\n");
        f=fopen("B11.txt", "w+");
    }
    if(strncmp(&buffer[0],"C",1)==0)
    {
        printf("Received house information from <Agent2>\n\n");
        f=fopen("B12.txt", "w+");
    }
    if(strncmp(&buffer[0],"D",1)==0){
        printf("Received house information from <Agent2>\n\n");
        f=fopen("B12.txt", "w+");
    }
    fprintf(f,"%s", buffer);
   // printf("Client : %s\n", buffer);

    //break;
    exit(0);
    }

    }


     
   int status;
pid_t pid;
int m=2;
while (m > 0) {
  pid = wait(&status);
  //printf("Child with PID %ld exited with status 0x%x.\n", (long)pid, status);
  --m;  
}
//if(m==0)

  printf("End of Phase 1 part 2for <Buyer1>\n\n");

  struct house
  {
    const char *name;
    int size;
    int cost;
    int agent;
  };

  struct house buyer;
  struct house seller[4];
  struct house agent1[2];
  struct house agent2[2];

FILE* fp;
FILE* fp1;
char buffer1[12][1024];
    char buf[1024];

     if ((fp = fopen("B11.txt", "r")) == NULL)
  { /* Open source file. */
    perror("fopen source-file");
    return 1;
  }
int k=0;
while (fgets(buf, sizeof(buf), fp) != NULL)
  {
    strcpy(buffer1[k], buf);
//printf("array ----> %s \n", &buffer1[k]);
k++;
  }
  fclose(fp);

if ((fp1 = fopen("B12.txt", "r")) == NULL)
  { /* Open source file. */
    perror("fopen source-file");
    return 1;
  }

  while (fgets(buf, sizeof(buf), fp1) != NULL)
  {
    strcpy(buffer1[k], buf);
//printf("array ----> %s \n", &buffer1[k]);
k++;
  }
  fclose(fp1);

//printf("array ----> %s \n", &buffer1[2]);

char * pch;
  //printf ("Splitting string \"%s\" into tokens:\n",str);
                char try[30];
  pch = strtok (buffer1[1],":");
  while (pch != NULL)
  {
    sprintf (try,"%s",pch);
    pch = strtok (NULL, "\n");
  }
    
    //printf("splittt%s",try);  

seller[0].cost=atoi(try);

//printf("this also%d",seller[0].cost);

pch = strtok (buffer1[4],":");
  while (pch != NULL)
  {
    sprintf (try,"%s",pch);
    pch = strtok (NULL, "\n");
  }
    
   // printf("splittt%s",try);  

seller[1].cost=atoi(try);

pch = strtok (buffer1[7],":");
  while (pch != NULL)
  {
    sprintf (try,"%s",pch);
    pch = strtok (NULL, "\n");
  }
    
    //printf("splittt%s",try);  

seller[2].cost=atoi(try);

pch = strtok (buffer1[10],":");
  while (pch != NULL)
  {
    sprintf (try,"%s",pch);
    pch = strtok (NULL, "\n");
  }
    
    //printf("splittt%s",try);  

seller[3].cost=atoi(try);

pch = strtok (buffer1[2],":");
  while (pch != NULL)
  {
    sprintf (try,"%s",pch);
    pch = strtok (NULL, "\n");
  } 

seller[0].size=atoi(try);

pch = strtok (buffer1[5],":");
  while (pch != NULL)
  {
    sprintf (try,"%s",pch);
    pch = strtok (NULL, "\n");
  } 

seller[1].size=atoi(try);

pch = strtok (buffer1[8],":");
  while (pch != NULL)
  {
    sprintf (try,"%s",pch);
    pch = strtok (NULL, "\n");
  } 

seller[2].size=atoi(try);

pch = strtok (buffer1[11],":");
  while (pch != NULL)
  {
    sprintf (try,"%s",pch);
    pch = strtok (NULL, "\n");
  } 

seller[3].size=atoi(try);

seller[0].name=buffer1[0];
seller[1].name=buffer1[3];
seller[2].name=buffer1[6];
seller[3].name=buffer1[9];

seller[0].agent=1;
seller[1].agent=1;
seller[2].agent=2;
seller[3].agent=2;

FILE* fp2;
char buffer2[2][1024];
    char buf1[1024];

     if ((fp2 = fopen("buyer1.txt", "r")) == NULL)
  { /* Open source file. */
    perror("fopen source-file");
    return 1;
  }
int l=0;
while (fgets(buf1, sizeof(buf1), fp2) != NULL)
  {
    strcpy(buffer2[l], buf1);
//printf("array ----> %s \n", &buffer1[k]);
l++;
  }
  fclose(fp2);

  pch = strtok (buffer2[0],":");
  while (pch != NULL)
  {
    sprintf (try,"%s",pch);
    pch = strtok (NULL, "\n");
  } 

buyer.size=atoi(try);

pch = strtok (buffer2[1],":");
  while (pch != NULL)
  {
    sprintf (try,"%s",pch);
    pch = strtok (NULL, "\n");
  } 

buyer.cost=atoi(try);

buyer.name="1";

//printf("buyer%d",buyer.size);
int a;
for(a=0;a<2;a++){
agent1[a].agent=1;
agent1[a].cost=0;
agent1[a].size=0;
agent1[a].name=" ";
}

int b;

for(b=0;b<2;b++){
agent2[b].agent=1;
agent2[b].cost=0;
agent2[b].size=0;
agent2[b].name=" ";
}
//printf("seller%d",seller[0].size);

/*if(buyer.cost>seller[0].cost)
{
    printf("yeah");
} */
if((buyer.cost>=seller[0].cost)&& (buyer.size<=seller[0].size))
   {

    //printf("yasss");
    agent1[0].cost=seller[0].cost;
    agent1[0].size=seller[0].size;
    agent1[0].name=seller[0].name;
}

if((buyer.cost>=seller[1].cost)&&(buyer.size<=seller[1].size))
   {
    agent1[1].cost=seller[1].cost;
    agent1[1].size=seller[1].size;
    agent1[1].name=seller[1].name;
}

if((buyer.cost>=seller[2].cost)&&(buyer.size<=seller[2].size))
   {
    agent2[0].cost=seller[2].cost;
    agent2[0].size=seller[2].size;
    agent2[0].name=seller[2].name;
}

if((buyer.cost>=seller[3].cost)&&(buyer.size<=seller[3].size))
   {
    agent2[1].cost=seller[3].cost;
    agent2[1].size=seller[3].size;
    agent2[1].name=seller[3].name;
}
//printf("now%d",agent1[0].cost);
char result1[2024]="1\n";
char r[100];
sprintf(r, "%d",buyer.cost);
strcat(result1,r);
strcat(result1,"\n");

char result2[2024]="1\n";

strcat(result2,r);
strcat(result2,"\n");
int count=0;
if(agent1[0].cost!=0&&agent1[1].cost!=0)
{
    if(agent1[0].cost<agent1[1].cost)
       { strcat(result1,agent1[0].name);
         //strcat(result1,"\n");
         strcat(result1,agent1[1].name);
     }

     else if(agent1[1].cost<agent1[0].cost)
        { strcat(result1,agent1[1].name);
         //strcat(result1,"\n");
         strcat(result1,agent1[0].name);
     }
}

 if(agent1[0].cost!=0&&agent1[1].cost==0)
{
    strcat(result1,agent1[0].name);
         //strcat(result1,"\n");
          strcat(result1," ");
          strcat(result1,"\n");
}

if(agent1[1].cost!=0&&agent1[0].cost==0)
{
    strcat(result1,agent1[1].name);
         //strcat(result1,"\n");
          strcat(result1," ");
          strcat(result1,"\n");
}

if(agent1[0].cost==0&&agent1[1].cost==0)
{
    count++;
    strcat(result1,"NAK");
    strcat(result1,"\n");
}


if(agent2[0].cost!=0&&agent2[1].cost!=0)
{
    if(agent2[0].cost<agent2[1].cost)
       { strcat(result2,agent2[0].name);
         //strcat(result2,"\n");
         strcat(result2,agent2[1].name);
     }

     else if(agent2[1].cost<agent2[0].cost)
        { strcat(result2,agent2[1].name);
         //strcat(result2,"\n");
         strcat(result2,agent2[0].name);
     }
}

 if(agent2[0].cost!=0&&agent2[1].cost==0)
{
    strcat(result2,agent2[0].name);
         //strcat(result2,"\n");
          strcat(result2," ");
          strcat(result2,"\n");
}

if(agent2[1].cost!=0&&agent2[0].cost==0)
{
    strcat(result2,agent2[1].name);
         //strcat(result2,"\n");
          strcat(result2," ");
          strcat(result2,"\n");
}

if(agent2[0].cost==0&&agent2[1].cost==0)
{
    count++;
    strcat(result2,"NAK");
    strcat(result2,"\n");
}


struct sockaddr_in server1;
    struct hostent *he;
    int sock1;

     if ((he = gethostbyname("nunki.usc.edu"))==NULL) {
        fprintf(stderr, "Cannot get host name\n");
        exit(1);
    }

    if ((sock1 = socket(AF_INET, SOCK_STREAM, 0))== -1) {
        fprintf(stderr, "Socket Failure!!\n");
        exit(1);
    }

    memset(&server1, 0, sizeof(server1));
    server1.sin_family = AF_INET;
    server1.sin_port = htons(PORT1);
    server1.sin_addr = *((struct in_addr *)he->h_addr);
    if (connect(sock1, (struct sockaddr *)&server1, sizeof(struct sockaddr))<0) {
        //fprintf(stderr, "Connection Failure\n");
        perror("connect");
        exit(1);
    }

     if ((send(sock1,result1, strlen(result1),0))== -1)
         {
            fprintf(stderr, "Failure Sending Message\n");
            close(sock1);
            exit(1);
        }

        char myIP[16];
    unsigned int myPort;
    struct sockaddr_in my_addr;

    bzero(&my_addr, sizeof(my_addr));
    int len = sizeof(my_addr);
    getsockname(sock1, (struct sockaddr *) &my_addr, &len);
    inet_ntop(AF_INET, &my_addr.sin_addr, myIP, sizeof(myIP));
    myPort = ntohs(my_addr.sin_port);

    int q;
char str1[30] = "Hello", *ptr1, c = '\n';
char str2[30] = {0}, *ptr2;
ptr1 = result1;
ptr2 = str2;
for (q=0; q<strlen(result1); q++)
{
    if (*ptr1 != c) *ptr2++=*ptr1;
    ptr1++;
}

    printf("The<Buyer1>has TCPport %d and IP address %s for Phase 1 part 3\n\n", myPort, myIP);
    printf("<Buyer1> has sent\n< %s > to <Agent1>\n\n",result1);


struct sockaddr_in server2;
    
    int sock2;

     

    if ((sock2 = socket(AF_INET, SOCK_STREAM, 0))== -1) {
        fprintf(stderr, "Socket Failure!!\n");
        exit(1);
    }

    memset(&server2, 0, sizeof(server2));
    server2.sin_family = AF_INET;
    server2.sin_port = htons(PORT2);
    server2.sin_addr = *((struct in_addr *)he->h_addr);
    if (connect(sock2, (struct sockaddr *)&server2, sizeof(struct sockaddr))<0) {
        //fprintf(stderr, "Connection Failure\n");
        perror("connect");
        exit(1);
    }

     if ((send(sock2,result2, strlen(result2),0))== -1)
         {
            fprintf(stderr, "Failure Sending Message\n");
            close(sock2);
            exit(1);
        }

        ptr1 = result2;
ptr2 = str2;
for (q=0; q<strlen(result2); q++)
{
    if (*ptr1 != c) *ptr2++=*ptr1;
    ptr1++;
}

        printf("<Buyer1> has sent\n< %s > to <Agent2>\n\n",result2);
        printf("End of Phase 1 part 3 for <Buyer1>\n\n");
///PART4

        int sfd, ret;
     struct sockaddr_in sAddr;

    int nSocket;
    struct sockaddr_in nAddr;

    socklen_t addr_size;

    char bu[2024];
    pid_t cpid;
    


    

    sfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sfd < 0)
    {
        printf("[-]Error in connection.\n");
        exit(1);
    }
    //printf("[+]Server Socket is created.\n");

    

    memset(&sAddr, '\0', sizeof(sAddr));
    sAddr.sin_family = AF_INET;
    sAddr.sin_port = htons(PORT3);
    sAddr.sin_addr.s_addr = INADDR_ANY;;

    ret = bind(sfd, (struct sockaddr*)&sAddr, sizeof(sAddr));
    if(ret < 0)
    {
        printf("[-]Error in binding.\n");
        exit(1);
    }
   

    if(listen(sfd, 20) == 0)
    {
       // printf("[+]Listening....\n");
    }else
    {
        printf("[-]Error in binding.\n");
    }
 
 
 int o;
 int i1;
 if(count==2)
    o=0;
if(count==1)
    o=1;
if(count==0)
    o=2;
if(count==1||count==0)
printf("<Buyer1> has TCPport %d and IP address %s for Phase 1 part 4\n\n",ntohs(sAddr.sin_port),inet_ntoa(sAddr.sin_addr));
    for(i1=0;i1<o;i1++)
    {
        nSocket = accept(sfd, (struct sockaddr*)&nAddr, &addr_size);
        if(nSocket < 0)
        {
            perror("accept");
            exit(1);
        }
        
        
      
        //printf("Connection accepted from %s:%d\n", inet_ntoa(nAddr.sin_addr), ntohs(nAddr.sin_port));

        if((cpid = fork()) == 0)
        {

            
                recv(nSocket, bu, 2024, 0);
                
                   
                   if(strncmp(bu,"NAK",3)==0)
                    printf("NAK\n\n");
                else
                printf("Will buy house from <Seller %s>\n\n", bu);
                     
                    exit(0);
                
        }


    }
int status22;
pid_t pid22;
int h=o;
while (h > 0) 
{
  pid22 = wait(&status22);
  //printf("Child with PID %ld exited with status 0x%x.\n", (long)pid22, status22);
  --h;  
}
if(count==1||count==0)
printf("End of Phase 1 part 4 for <Buyer1>");
exit(0); 
}
