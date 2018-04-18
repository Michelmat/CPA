#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <omp.h>


typedef unsigned long long Entero_grande;
#define ENTERO_MAS_GRANDE  ULLONG_MAX

int primo(Entero_grande n)
{
  int p;
  Entero_grande i, s;
  int ini,fin,nb,nhilos,hilo,inc;  // variables
  p = (n % 2 != 0 || n == 2);
  if (p) {
	
    s = sqrt(n);
#pragma omp parallel private (hilo, i, ini, fin)
	hilo = omp_get_thread_num();
	nhilos = omp_get_num_threads();
	ini = 2*hilo +3;
	inc =2*nhilos;

//	if (hilo = nhilos) fin = s;
    for (i =ini; p && i <= s; i += i+ini)
      if (n % i == 0) p = 0;
  }
//parallel
  return p;
}

int main()
{
  Entero_grande n;

  for (n = ENTERO_MAS_GRANDE; !primo(n); n -= 2) {
    /* NADA */
  }

  printf("El mayor primo que cabe en %d bytes es %llu.\n",
         sizeof(Entero_grande), n);

  return 0;
}
