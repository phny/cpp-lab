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
    return -1;
  }

  cout << "shmmem keyid " << keyid;
  cout << " share memory id: " << shmid << endl;

  void *addr = shmat(shmid, (char *)0, 0);
  if (addr == (void *)-1) {
    perror("shmat");
  }

  cout << "shared memory addr :" << addr << endl;

  int semid = get_sem_id();
  if (semid < 0) {
    return -1;
  }

  if (semctl(semid, 0, SETVAL, 1) < 0) {
    cerr << "Inital sem val failed" << endl;
    return -1;
  }

  P(semid);
  cout << "I'm pid " << getpid() << " ready for writing a msg " << endl;

  char *msg = "Hello shared memory!";
  char *p = (char *)addr;
  strcpy(p, msg);
  //模拟耗时操作
  sleep(10);
  V(semid);

  cout << "I'm pid " << getpid() << " writed a msg " << endl;

  shmdt(addr);

  return 0;
}
