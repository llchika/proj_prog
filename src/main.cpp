#include <iostream>

#include <Game.h>
#include <constantes.h>

int main(int /*argc*/, char** /*argv*/) {
    std::cout << "Lancement du jeu ESIR1\n";

    srand((unsigned int)time(NULL));

    Game game(JeuESIR::screenWidth, JeuESIR::screenHeight);
    game.run();

    return 0;
}
