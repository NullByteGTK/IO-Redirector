/*
* IO Redirector
* Written by: NullByte
* Github: NullByteGTK
* Contact: nullbytegtk@gmail.com
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char *get_input(); //A simple function for getting user input

int main(){
	setbuf(stdout,NULL);
	char *command; //User's input
	FILE *fp; //File handler for opening files and redirecting their contents
	while(1){ //Run for ever
		command = get_input(); //Get user input
		switch(command[0]){
			case '#': //If input starts with # it will try to open the file provided after #
				fp = fopen((command+1),"r");
				if(fp == NULL) //If there was any errors opening the file do nothing
					break;
				fseek(fp,0,SEEK_END);
				int sz = ftell(fp); //Get file's size and read it char by char
				rewind(fp);
				while(1){
					if(ftell(fp) != sz)
						putchar(fgetc(fp));
					else
						break;
				}
				break;
			case '$': //If input starts with $ it will try to execute it as a command
				system((command+1));
				break;
			case '\\': //If input starts with \ it will ignore it It's useful when user wants to type something that starts with $ or # but he doesnt want his input to be treated as a special command
				puts(command+1);
				break;
			default:
				puts(command); //If the input didn't contain #,$ or \ it will redirect it without doing anything 
				break;
		}
		free(command);
	}
}

char *get_input(){
	unsigned int add=128;
	unsigned long long base = 256,point = 0;
	unsigned char buff;
	char *input_buffer;
	input_buffer = (char *)malloc(base); //Allocate 256bytes on heap
	while(buff = getchar()){ //Get input char by char
		if(buff == '\n'){ //If input char was newline add a null terminator to the end of the buffer and return its address
	    	if(point == base){
	        	input_buffer = (char *)realloc(input_buffer,base+add);
	        	base += add;
	      	}
	        input_buffer[point] = 0;
	        break;
	    }else{
	      if(point == base){ //If input length was bigger than the allocated buffer reallocate it
	        input_buffer = (char *)realloc(input_buffer,base+add);
	        base += add;
	      }
	      input_buffer[point] = buff;
	      point++;
	    }
	}
	return input_buffer;
}
