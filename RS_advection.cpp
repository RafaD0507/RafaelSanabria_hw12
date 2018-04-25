#include <iostream>
#include <cmath>

using namespace std;

double u_t_inicial(double x);

int main(){
  double c = 1;
  double dt = 0.001;
  double dx = 0.001;
  int nt = 700;
  double x_down = -2.0;
  double x_up = 2.0;
  int nx = 4/dx+1;
  double *u = new double[nx];
  double *temp = new double[nx];
  double x = x_down;
  double **respuestas = new double*[5];

  for(int i=0; i<5; i++){
    respuestas[i] = new double[nx];
  }

  //Se inicializan los vectores
  
  for(int i=0; i<nx; i++){
    u[i] = u_t_inicial(x);
    temp[i] = u_t_inicial(x);
    x = x + dx;
  }

  //Aqui se calculan los cambios en la funcion en el tiempo
  for(int j=0; j<700; j++){
    for(int i=0; i<nx; i++){
      if(j>0 && (i!=0 && i!=nx-1)){
	u[i] = temp[i]-c*(dt/dx)*(temp[i]-temp[i-1]);
      }
      if(j==0 || j==174 || j==349 || j==524 || j == 699){
	respuestas[int((j+1))/175][i] = u[i];
      }
    }
    for(int i=0; i<nx; i++){
      temp[i] = u[i];
    }
  }

  x = x_down;

  //imprime los resultados de interes
  for(int i=0; i<nx; i++){
    cout<<x<<" "<<respuestas[0][i]<<" "<<respuestas[1][i]<<" "<<respuestas[2][i]<<" "<<respuestas[3][i]<<" "<<respuestas[4][i]<<endl;
      x = x + dx;
  }
}

//Esta es la funcion inicial
double u_t_inicial(double x){
  if(x<-0.5 || x>0.5 ){
    return 0.5;
  }else{
    return 0;
  }
}
