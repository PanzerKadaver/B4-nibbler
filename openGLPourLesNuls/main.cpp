//
// main.cpp for  in /home/aubert_n/rep/nibbler/openGLPourLesNuls
// 
// Made by Nathan AUBERT
// Login   <aubert_n@epitech.net>
// 
// Started on  Fri Apr  4 21:12:23 2014 Nathan AUBERT
// Last update Sat Apr  5 16:00:33 2014 Nathan AUBERT
//

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

int main()
{
  // crée la fenêtre
  sf::Window window(sf::VideoMode(800, 600), "OpenGL", sf::Style::Default, sf::ContextSettings(32));
  window.setVerticalSyncEnabled(true);

  // chargement des ressources, initialisation des états OpenGL, ...

  // la boucle principale
  bool running = true;
  while (running)
    {
  // gestion des évènements
  sf::Event event;
  while (window.pollEvent(event))
    {
  if (event.type == sf::Event::Closed)
    {
  // on stoppe le programme
  running = false;
}
  else if (event.type == sf::Event::Resized)
    {
  // on ajuste le viewport lorsque la fenêtre est redimensionnée
  glViewport(0, 0, event.size.width, event.size.height);
}
}

  // effacement les tampons de couleur/profondeur
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // dessin...

  // termine la trame courante (en interne, échange les deux tampons de rendu)
  window.display();
}

  // libération des ressources...

  return 0;
}
