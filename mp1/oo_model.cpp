#include <vector>

#include "oo_model.hpp"

#include <iostream>

Corpo::Corpo(float massa, float velocidade, float posicao, float coeficienteMola) {
  this->massa = massa;
  this->velocidade = velocidade;
  this->posicao = posicao;
  this->coeficienteMola = coeficienteMola;
}

void Corpo::update(float nova_velocidade, float nova_posicao, float nova_aceleracao) {
  this->velocidade = nova_velocidade;
  this->posicao = nova_posicao;
  this->aceleracao = nova_aceleracao;
}

float Corpo::get_massa() {
  return this->massa;
}

float Corpo::get_velocidade() {
  return this->velocidade;
}

float Corpo::get_posicao() {
  return this->posicao;
}

float Corpo::get_aceleracao() {
  return this->aceleracao;
}


float Corpo::get_coeficienteMola() {
  return this->coeficienteMola;
}

ListaDeCorpos::ListaDeCorpos() {
  this->corpos = new std::vector<Corpo *>(0);
}

void ListaDeCorpos::add_corpo(Corpo *c) {
  (this->corpos)->push_back(c);
  std::cout << "Agora tenho: " << this->corpos->size() << " elementos" << std::endl;
}

std::vector<Corpo*> *ListaDeCorpos::get_corpos() {
  return (this->corpos);
}

Fisica::Fisica(ListaDeCorpos *ldc) {
  this->lista = ldc;
}

void Fisica::update(float deltaT) {
  // Atualiza parametros dos corpos!
  std::vector<Corpo *> *c = this->lista->get_corpos();
  for (int i = 0; i < (*c).size(); i++) {
    float new_acel = -((*c)[i]->get_coeficienteMola()) * (*c)[i]->get_posicao() / (*c)[i]->get_massa();
    float new_vel = (*c)[i]->get_velocidade() + (float)deltaT * new_acel/1000;
    float new_pos = (*c)[i]->get_posicao() + (float)deltaT * new_vel/1000;

    (*c)[i]->update(new_vel, new_pos, new_acel);
  }
}


