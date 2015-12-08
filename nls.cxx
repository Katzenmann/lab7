#include <cmath>
#include<iostream>

using namespace std;

void gleichungssystem(double* , double* , const double);


int main(void){
  const int L=100;
  const double dx=0.001;
  const int N=L/dx;
  const double eta=0.75;
  double k1[2];
  double k2[2];
  double k3[2];  
  double y[2];
  double temp[2];
  y[0]=pow(10,-5);
  y[1]=pow(eta,0.5)*y[1];
  
  
  
  
    for(int i=0; i<N; i++){
      
   gleichungssystem(k1, y, eta);
   
   temp[0]=y[0]+dx/2*k1[0];
   temp[1]=y[1]+dx/2*k1[1];
   gleichungssystem(k2, temp, eta);
   
   temp[0]=y[0]-dx*k1[0]+2*dx*k2[0];
   temp[1]=y[1]-dx*k1[1]+2*dx*k2[1];
   gleichungssystem(k3, temp, eta);
   
   y[0]=y[0]+dx/6*(k1[0]+4*k2[0]+k3[0]);
   y[1]=y[1]+dx/6*(k1[1]+4*k2[1]+k3[1]);
    
    cout<< i*dx <<"\t"<<y[0]<<"\t"<<y[1]<<endl;
    
  }
  
  
  

  
  
  
  
  
}

void gleichungssystem(double k[2], double y[2], const double eta){

k[0]= y[1];
k[1]= (eta-pow(abs(y[0]),2))*y[0];
  // y1_x= y2
  // y2_x= (eta-abs(y1)^2 * y1
}