/*
  Purpose:

   el programa solicita al usuario el número de subintervalos en los que se dividirá el intervalo de integración, así como los límites inferior y superior del intervalo. A continuación, el programa calcula la anchura de cada subintervalo y distribuye los subintervalos entre los hilos disponibles utilizando una directiva OpenMP.

Cada hilo calcula la suma de la función evaluada en sus subintervalos asignados y los resultados parciales se combinan mediante una reducción. Finalmente, el programa utiliza la fórmula del método del trapecio para aproximar la integral y muestra el resultado al usuario.
    
   Example:
   
   31 Sep 2005 05:12:20 AM

  Licensing:

   This code is distributed under the GNU LGPL license.

  Modified:

    24 September 2006

  Author:
  Manas Sharma 
  OpenMP Modification:
  24 april 2023 by Cristhian Tristancho, Universidad Industrial de Santander cristhian2192532@correo.uis.edu.co                   
  This OpenMP Modification makes a parallelization of the original Code...  
*/

#include <stdio.h>
#include <math.h>
#include <omp.h>

/* Define the function to be integrated here: */
double f(double x){
  return x*x;
}

/*Program begins*/
int main(){
  int n,i;
  double a,b,h,x,sum=0,integral;

  /*Ask the user for necessary input */
  printf("\nEnter the no. of sub-intervals: ");
  scanf("%d",&n);
  printf("\nEnter the initial limit: ");
  scanf("%lf",&a);
  printf("\nEnter the final limit: ");
  scanf("%lf",&b);

  /*Begin Trapezoidal Method: */

  // Splits work into subintervals and assigns them to different threads
  h=fabs(b-a)/n;
  #pragma omp parallel for private(x) reduction(+:sum)
  for(i=1;i<n;i++){
    x=a+i*h;
    sum=sum+f(x);
  }

  // Reduce the partial results to obtain the total integral
  integral=(h/2)*(f(a)+f(b)+2*sum);

  /*Print the answer */
  printf("\nThe integral is: %lf\n",integral);
} 