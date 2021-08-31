#include "gui_board.h"

Gui_board::Gui_board(Game &game) : game(&game)
{
    gui_ball = new Gui_ball(*game.ball);
    this->addItem(gui_ball);
    connect(this->game,SIGNAL(updateGui()),this,SLOT(update()));
}

void Gui_board::update()
{
    this->gui_ball->updatePosition();


}
