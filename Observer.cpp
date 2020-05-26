#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

//Clase Listener necesaria para poder obtener los datos de la clase publisher
class Listener{
  public:
  virtual void onEvent(string msg) = 0;
};

//Clase Publisher da un mensaje para que las demas clases lo escuchen
class Publisher{

    //El metodo vector guarda punteros hacia todas las clases que esten suscritas a la clase Publisher
    vector<Listener*> listeners;


    //Metodo que agrega el puntero de las clases listener al vector
    public:
    void addListener(Listener* lis){
      listeners.push_back(lis);
    }

    //Invoca el metodo "onEvent" de cada objeto cuya dirrecion de memoria este guardade en el vector
    void publishEvent(string msg){
      for(Listener* lis: listeners)
      lis ->onEvent(msg);
    }

    //Publica un mensaje para cada objeto subscrito
    void doSometing(){
      publishEvent("Hello World!");
    }
};

//Clase que hereda de Listener
class Listener1 : public Listener{

  //Agrega una referencia hacia publisher
  public:
  Listener1(Publisher& p){
    p.addListener(this);
  }

  //Cuando Publisher publica algo este metodo imprime el mensaje
  virtual void onEvent(string msg){
    cout << "Listener1: " << msg << endl;
  }

};

class Listener2 : public Listener{
  public:
  Listener2(Publisher& p){
    p.addListener(this);
  }

  virtual void onEvent(string msg){
    cout << "Listener2: " << msg << endl;
  }


};

int main(){
  Publisher p;
  Listener1* ptr1 = new Listener1(p);
  Listener2* ptr2 = new Listener2(p);

  p.doSometing();
  
  delete ptr1;
  delete ptr2;
}

