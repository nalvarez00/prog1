#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

void* diamonds(void* tmp);
void* clubs(void* tmp);
void* hearts(void* tmp);
void* spades(void* tmp);

sem_t FLAG; //create semaphore 

int main(){

	FILE * fd = fopen("STACK.txt","w+"); //create text file in current directory and open it in read mode
	fprintf(fd,"%d\n", getpid()); //write process' pid into the text file
	fclose(fd); //close the file

	sem_init(&FLAG,0,1); //initialize semaphore with value 1 to be used only by this process 

	//create pointers for the 4 threads 
	pthread_t thread1, thread2, thread3, thread4;

	pthread_create(&thread1, NULL, diamonds, NULL); //create thread that will run every 125 ms
	pthread_create(&thread2, NULL, clubs, NULL); //create thread that will run every 250 ms
	pthread_create(&thread3, NULL, hearts, NULL); //create thread that will run every 500 ms
	pthread_create(&thread4, NULL, spades, NULL); //create thread that will run every 750 ms
	
	//block/wait for all 4 threads to finish printing their 13 cards
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);
	pthread_join(thread4, NULL);
	
	sem_destroy(&FLAG); //destroy semaphore
	printf("Thats all the cards, now time to play 52 pickup!\n");
	
	//exit gracefully, like a falling feather
	return 0;
}


void* diamonds(void* tmp){
	int i;
	for (i = 1; i <= 13;i++){
		sem_wait(&FLAG);
		FILE * fd = fopen("STACK.txt","w+"); 
		if(i == 1){
			fprintf(fd,"Diamond A\n");
		}
		else if(i == 11){
			fprintf(fd,"Diamond J\n");
		}
		else if(i == 12){
			fprintf(fd,"Diamond Q\n");
		}
		else if(i == 13){
			fprintf(fd,"Diamond K\n");
		}
		else{
			fprintf(fd,"Diamond %d\n",i);		
		}
		fclose(fd);
		printf("Thread %u is running\n", (unsigned int)pthread_self());
		//wait 125 ms
		usleep(125000);
		sem_post(&FLAG);
	}
	return NULL;
}

void* clubs(void* tmp){
	int i;
	for (i = 1; i <= 13;i++){
		sem_wait(&FLAG);
		FILE * fd = fopen("STACK.txt","w+"); 
		if(i == 1){
			fprintf(fd,"Club A\n");
		}
		else if(i == 11){
			fprintf(fd,"Club J\n");
		}
		else if(i == 12){
			fprintf(fd,"Club Q\n");
		}
		else if(i == 13){
			fprintf(fd,"Club K\n");
		}
		else{
			fprintf(fd,"Club %d\n",i);		
		}
		fclose(fd);
		printf("Thread %u is running\n", (unsigned int)pthread_self());
		//wait 250 ms
		usleep(250000);
		sem_post(&FLAG);
	}
}

void* hearts(void* tmp){
	int i;
	for (i = 1; i <= 13;i++){
		sem_wait(&FLAG);
		FILE * fd = fopen("STACK.txt","w+");  
		if(i == 1){
			fprintf(fd,"Heart A\n");
		}
		else if(i == 11){
			fprintf(fd,"Heart J\n");
		}
		else if(i == 12){
			fprintf(fd,"Heart Q\n");
		}
		else if(i == 13){
			fprintf(fd,"Heart K\n");
		}
		else{
			fprintf(fd,"Heart %d\n",i);		
		}
		fclose(fd);
		printf("Thread %u is running\n", (unsigned int)pthread_self());
		//wait 500 ms
		usleep(500000);
		sem_post(&FLAG);
	}
}

void* spades(void* tmp){
	int i;
	for (i = 1; i <= 13;i++){
		sem_wait(&FLAG);
		FILE * fd = fopen("STACK.txt","w+"); 
		if(i == 1){
			fprintf(fd,"Spade A\n");
		}
		else if(i == 11){
			fprintf(fd,"Spade J\n");
		}
		else if(i == 12){
			fprintf(fd,"Spade Q\n");
		}
		else if(i == 13){
			fprintf(fd,"Spade K\n");
		}
		else{
			fprintf(fd,"Spade %d\n",i);		
		}
		fclose(fd);
		printf("Thread %u is running\n", (unsigned int)pthread_self());
		//wait 750 ms
		usleep(750000);
		sem_post(&FLAG);
	}
}
