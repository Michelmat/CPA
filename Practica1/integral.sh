#!/bin/sh
#PBS -l nodes=1,walltime=00:05:00
#PBS -q cpa
#PBS -d .
./integral 1
./integral 2
OMP_NUM_THREADS=3 ./pintegral 1
OMP_NUM_THREADS=3 ./pintegral 2
OMP_NUM_THREADS=4 ./pintegral 1
OMP_NUM_THREADS=4 ./pintegral 2

