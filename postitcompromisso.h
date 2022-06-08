#ifndef POSTITCOMPROMISSO_H
#define POSTITCOMPROMISSO_H

#include "postit.h"

class PostitCompromisso : public Postit
{
    QString tipo;
    QString horario;
public:
    QString getNome();
    QString getdata();
    QString getdescricao();
    QString getTipo();
    QString gethorario();
    void setNome(QString);
    void setdata(QString);
    void setdescricao(QString);
    void setTipo(QString);
    void sethorario(QString);
    PostitCompromisso(QString nome, QString data,
                      QString tipo, QString descricao,
                      QString horario, QWidget *parent);
    PostitCompromisso(QWidget* parent = nullptr);
    void paintEvent(QPaintEvent*);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void destruir(){delete this;}
};

#endif // POSTITCOMPROMISSO_H
