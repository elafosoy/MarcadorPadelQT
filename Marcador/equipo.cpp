#include "equipo.h"

Equipo::Equipo() { m_juegos = 0; }

void Equipo::sumaJuego() { m_juegos++; }

int Equipo::totalJuegosGanados() { return m_juegos; }
