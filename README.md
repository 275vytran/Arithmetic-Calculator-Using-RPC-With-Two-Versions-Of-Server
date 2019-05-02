# Arithmetic Calculator Using RPC With Two Versions Of The Same Server

Author: Vy Tran and Rasmi Wagle

The calculating server will provide the service procedures addition(+), subtraction(-), multiplication (*), and division(/) of any two integer values or any two decimal values. In the client side, you can implement a calculator that accepts an expression (consisting of only integer values or only decimal values and four arithmetic operators (+,-,*,/)) and prints out the corresponding answer. User is able to choose Integer version of server or Decimal version of server. For example, if user chooses Integer version and input 5/2 then the result is 2. While, if user chooses Decimal version of server and input 5/2 then the result is 2.5

To compile: 

   rpcgen calculator.x

   cc -o client client.c calculator_clnt.c
   
   cc -o server server.c calculator_svc.c

To run the program:

   On server terminal: ./server
   
   On client terminal: ./client IPAddress
   
   Note: IPAddress is the IP address of the server that user want to connect.
 
