#ifndef POSTITBASICO_H
#define POSTITBASICO_H
#include <QMouseEvent>
#include "postit.h"


class PostitBasico : public Postit
{
public:
    QString getNome();
    QString getdata();
    QString getdescricao();
    void setNome(QString);
    void setdata(QString);
    void setdescricao(QString);
    PostitBasico(QString nome, QString data, QString descricao, QWidget *parent);
    PostitBasico(QWidget* parent = nullptr);
    void paintEvent(QPaintEvent*);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void destruir(){delete this;}
};
#endif // POSTITBASICO_H
