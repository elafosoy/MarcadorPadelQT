# Marcador padel / tenis

### Aplicación para controlar los puntos en un partido de padel o tenis

> Empiezo a escribir esta aplicación, para depurar la logica de un marcador de padel.  
La idea es poder exportar estas mismas classes de marcador a un proyecto para correr en arduino.  
Asi hacer el proyecto de un marcador fisico con arduino y display led para usar en pista.

> Por comodidad resulta mas facil depurar en QT la parte de la logica de puntos y partidos y una vez  
resuelto esto seguir adelante con la arduino o wemos D1 mini.

1. El objeto principal es Marcador y tiene 5 metodos:
    * Suma punto Equipo A -> sumaA()
    * Suma punto Equipo B -> sumaB()
    * Resta punto Equipo A -> restaA()
    * Resta punto Equipo B -> restaB()
    * Actualiza pantalla -> refreshResults(Pantalla *pantalla)
