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

	printf("The previous shmid is %.2f\n",*stored_value);
	*stored_value = 38;


	shmdt(stored_value);

	//shmctl(shmid,IPC_RMID,NULL);   //delete shared memory	

	return 0;

}
