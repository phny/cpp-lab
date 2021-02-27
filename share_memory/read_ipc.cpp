
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>

using namespace std;

void P(int semid) {
  struct sembuf buf = {0, -1, 0};

  semop(semid, &buf, 1);
}

void V(int semid) {
  struct sembuf buf = {0, 1, 0};

  semop(semid, &buf, 1);
}

int get_sem_id() {
  key_t keyid = ftok("testforsem", 102);

  if (keyid < 0) {
    cerr << " get key failed" << endl;
    return -1;
  }

  int semid = semget(keyid, 1, IPC_CREAT | 0660);
  if (semid < 0) {
    cerr << "get semphore failed" << endl;
    return -1;
  }

  return semid;
}

int main(int argc, char **argv) {
  key_t keyid = ftok("./forshm", 1);

  if (keyid < 0) {
    cerr << "get keyid failed !" << endl;
    return -1;
  }

  int shmid = shmget(keyid, 1024, IPC_CREAT | 0660);

  if (shmid < 0) {
    cerr << "get share memory error!" << endl;
    perror("get shmid");
    return -1;
  }

  cout << "shmmem keyid " << keyid;
  cout << " share memory id: " << shmid << endl;

  char *addr = (char *)shmat(shmid, NULL, 0);

  if (addr == (char *)-1) {
    perror("shmat");
  }

  int semid = get_sem_id();
  if (semid < 0) {
    return -1;
  }

  P(semid);

  cout << "I’m pid " << getpid() << " read msg : " << addr << endl;

  V(semid);

  shmdt(addr);

  shmctl(shmid, IPC_RMID, NULL);

  semctl(semid, 0, IPC_RMID);

  return 0;
}
