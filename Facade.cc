class Subsistema1{
    public:
     std::string Operacion1() const{
        return "Subsistema1: Listo\n"
    }
    std::string OperacionN() const{
        return "Subsistema1: Inicio\n"
    }
};
class Subsistema2 {
 public:
  std::string Operacion1() const {
    return "Subsistema2: Preparese!\n";
  }
  std::string OperacionM() const {
    return "Subsystem2: Ejecuten!\n";
  }
};
class Facade {

 protected:
  Subsistema1 *subsistema1_;
  Subsistema2 *subsistema2_;

 public:
  Facade(
      Subsistema1 *subsistema1 = nullptr,
      Subsistema2 *subsistema2 = nullptr) {
    this->subsistema1_ = subsistema1 ?: new Subsistema1;
    this->subsistema2_ = subsistema2 ?: new Subsistema2;
  }
  ~Facade() {
    delete subsistema1_;
    delete subsistema2_;
  }
  std::string Operation() {
    std::string result = "Facade inicializa los subsistemas:\n";
    result += this->subsistema1_->Operacion1();
    result += this->subsistema2_->Operacion1();
    result += "Facade le ordena a los subsitemas realizar las acciones:\n";
    result += this->subsistema1_->OperacionN();
    result += this->subsistema2_->OperacionZ();
    return result;
  }
  void ClientCode(Facade *facade) {
  std::cout << facade -> Operation();
}
int main() {
  Subsistema1 *subsistema1 = new Subsistema1;
  Subsistema2 *subsistema2 = new Subsistema2;
  Facade *facade = new Facade(subsistema1, subsistema2);
  ClientCode(facade);

  delete facade;

  return 0;
}

};
