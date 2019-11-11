Name- TANISHA BAADKAR
Student Id-3445191731

DESCRIPTION
Paxos is a family of protocols for solving consensus in a network of unreliable processors. Consensus is the process of agreeing on one result among a group of participants. In the phase 2 of the project the paxos algorithm has been modelled with 2 Proposers, 3 acceptors and 1 Learner.UDP sockets have been used for this purpose.


CODE FILES
Proposer1.c Proposer2.c
These are the proposers and they generate a unique proposal number and value to send to the acceptors as a prepare request. Upon response from a majority of acceptors it send an accept request specifying that the particular value should be chosen.


Acceptor1.c Acceptor2.c Acceptor3.c
They recieve prepare requests from proposers and promise not to accept any proposal with a lower proposal number.

Learner.c
This program learns the concensus value that has been accepted by a majority of the acceptors and displays the final value that is chosen.

ORDER OF EXECUTION
Acceptors-Proposers-Learner
Please wait a few minutes for the final value to appear on the Learners screen as delays have been used and it might cause the result to appear after a while.

Project does not fail under any conditions.

I have not reused code directly from anywhere. However, I have reffered to Geeksforgeeks , stackoverflow and Beejs guide for help.



