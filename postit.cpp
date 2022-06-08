
#include "postit.h"
#include <QtWidgets>
Postit::Postit(QWidget* parent) : QLabel(parent)
{
    setAcceptDrops(true);
}
void paintEvent(QPaintEvent *event);






