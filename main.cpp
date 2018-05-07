#include "E101.h"
#include <stdio.h>

int forward(int speed){
  if(speed>255){
    speed=255;
  }
  if(speed<-255){
    speed=-255; //127/-127?
  }
  set_motor(1,speed);
  set_motor(2,speed);
}
int stop(){
  set_motor(1,0);
  set_motor(2,0);
}

void openGate() {
	connect_to_server("", 1000); //Establish a connection to the server
	send_to_server("please"); //Request the password from the server
	
	char[24] response;
	recieve_from_server(response); //Store the server response
	
	send_to_server(response); //Transmit the response back to the server
	
	//Gate is now open.
  
}

int main(){
  init();
  forward(50);
  sleep1(3,0);
  stop();

  return 0;
}
