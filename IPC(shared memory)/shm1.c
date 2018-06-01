#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int shmid;
key_t key;
int shmflg;
size_t size;

//man ipcrm


int main(){

        double *stored_value;
	key = 12345;
	shmflg = IPC_CREAT | 0666;
	size = sizeof(double);

	shmid = shmget(key,size,shmflg);
        printf("THe shmid is %d",shmid);

	stored_value = shmat(shmid,NULL,0);
	*stored_value = 35.0;

	while(*stored_value == 35.0){
		sleep(1);
	
	}
	printf("The value has been changed to %.2f\n",*stored_value);

	shmdt(stored_value);

	//shmctl(shmid,IPC_RMID,NULL);   //delete shared memory	

	return 0;

}
