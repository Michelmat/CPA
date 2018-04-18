#include <mpi.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

#define N 100000
#define NITER 100


int main(int argc,char *argv[]) 
{ 
  char   msg[N];
  double t;
  int    numprocs, myid, i;

  MPI_Init(&argc,&argv); 
  MPI_Comm_size(MPI_COMM_WORLD,&numprocs); 
  MPI_Comm_rank(MPI_COMM_WORLD,&myid); 

  if (argc==2) n = atoi(argv[1]);
  else n = 100;
  if (n<=0) MPI_Abort(MPI_COMM_WORLD,MPI_ERR_ARG);

  if ( myid == 0) {
	t = MPI_Wtime();
    for (i = 1; i <= NITER; i++){
	  MPI_Send(msg, N, MPI_CHAR, 1, 0, MPI_COMM_WORLD);
	  MPI_Recv(msg, N, MPI_CHAR, 1, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	}
  }else{
    for (i = 1; i <= NITER; i++){
	  MPI_Recv(msg, N, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	  MPI_Send(msg, N, MPI_CHAR, 0, 1, MPI_COMM_WORLD);
	}
  }
  t = MPI_Wtime() - t;
  t = t / ( 2 * NITER);

  return t; 
} 

