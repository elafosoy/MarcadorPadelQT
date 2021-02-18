#ifndef MARCADOR_H
#define MARCADOR_H
#include "equipo.h"
#include "juego.h"
#include "set.h"

struct Pantalla {
  int puntosA = 0;
  int puntosB = 0;
  int juegosA = 0;
  int juegosB = 0;
};

class Marcador {
  Equipo m_equipoA;
  Equipo m_equipoB;

  Juego *m_juegoA;
  Juego *m_juegoB;

 public:
  Marcador();

  void sumaA();
  void sumaB();

  void restaA();
  void restaB();

  void totalA();
  void totalB();

  void refreshResults(Pantalla *pantalla);
};

#endif  // MARCADOR_H
