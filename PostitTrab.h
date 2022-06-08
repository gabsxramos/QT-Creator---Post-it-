#ifndef POSTITTRAB_H
#define POSTITTRAB_H

#include "postit.h"

class PostitTrab : public Postit
{
    QString disciplina;

public:
    QString getNome();
    QString getdata();
    QString getdescricao();
    QString getdisciplina();
    void setNome(QString);
    void setdata(QString);
    void setdescricao(QString);
    void setdisciplina(QString);

    PostitTrab(QString nome, QString data, QString disciplina,
               QString descricao, QWidget *parent);
    PostitTrab(QWidget* parent = nullptr);
    void paintEvent(QPaintEvent*);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void destruir(){delete this;}
};

#endif // POSTITTRAB_H
