#include "Sequence.h"


Sequence::Sequence(){
	this->contenuMixte = new ContenuMixte()
}

Sequence::~Sequence(){
	delete contenuMixte;
}

string Sequence::serialize(){
  string s = "";
}