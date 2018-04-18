#!/bin/sh
#PBS -q cpa
#PBS -l nodes=4,walltime=00:01:00
#PBS -o ./mpi_pi.out
#PBS -d .

cat $PBS_NODEFILE
mpiexec ./mpi_pi
