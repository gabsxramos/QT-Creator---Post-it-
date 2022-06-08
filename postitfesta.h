#ifndef POSTITFESTA_H
#define POSTITFESTA_H

#include "postit.h"

class PostitFesta : public Postit
{
    QString estilo;
    QString horario;
public:
    QString getNome();
    QString getdata();
    QString getdescricao();
    QString getEstilo();
    QString gethorario();
    void setNome(QString);
    void setdata(QString);
    void setdescricao(QString);
    void setEstilo(QString);
    void sethorario(QString);
    PostitFesta(QString nome, QString data, QString estilo,
                QString descricao, QString horario, QWidget *parent);
    PostitFesta(QWidget* parent = nullptr);
    void paintEvent(QPaintEvent*);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void destruir(){delete this;}
};


#endif // POSTITFESTA_H
