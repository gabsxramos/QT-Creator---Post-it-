#include<QApplication>
#include "janela.h"

int main(int argc, char*argv[]){
    QApplication app(argc, argv);

   Janela *j = Janela::instancia();
   j->show();

    return app.exec();
}
