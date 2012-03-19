#ifndef CONTENUCOMPOSE_H
#define CONTENUCOMPOSE_H


class ContenuCompose {

  public:
  	ContenuCompose(string type);
  	~ContenuCompose();
  	virtual string serialize();
  
  private:
  	string type; // ANY, EMPTY 
};

#endif
