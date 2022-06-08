#ifndef JANELA_H
#define JANELA_H

#include "postit.h"
#include <QMainWindow>
#include <QPushButton>
#include <vector>
using namespace std;
class Janela : public QMainWindow
{
    Q_OBJECT
    QPushButton *basico, *trabalho, *compromisso, *festa, *abrir, *salvar;
    explicit Janela(QWidget *parent = nullptr);
protected:
    vector<Postit*> v;
    QString file = "E:/POO-QT/file.txt";
public:
    static Janela *instancia() {
                static Janela *instancia = 0;
                if (instancia == 0 ) {
                    instancia = new Janela();
                }
                return instancia;
            }
public slots:
    void CriarPostitTrab();
    void CriarPostitcompromisso();
    void CriarPostitBasico();
    void CriarPostitFesta();
    void Abrir();
    void Salvar();
signals:
};
#endif // JANELA_H
