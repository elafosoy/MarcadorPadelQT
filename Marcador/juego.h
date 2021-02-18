#ifndef JUEGO_H
#define JUEGO_H
#include "equipo.h"

class Juego {
  Equipo *m_equipo;
  Juego *m_otherJuego;
  int m_puntos;
  int m_otherPuntos;

 public:
  Juego(Equipo *equipo);
  void setOtherJuego(Juego *otherJuego);

  void suma();
  void resta();
  int puntos();

  void clear();
};

#endif  // JUEGO_H
