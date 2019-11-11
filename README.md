# Socket-program

Developed a bidding system with multiple Sellers, Buyers and Agents. 
The simultaneous bids were made using TCP and UDP connections through Linux sockets. 
Paxos algorithm was used to achieve consensus between participants of the auction which includes a spectrum of trade-offs between the 
number of processors, number of message delays before learning the agreed value, the activity level of individual participants, 
number of messages sent, and types of failures
