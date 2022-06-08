#ifndef POSTIT_H
#define POSTIT_H
#include <QLabel>
#include <QPushButton>
#include <QMouseEvent>
#include <QDrag>
#include <QMimeData>
#include <QWidget>
class Postit : public QLabel{
protected:
    QPointF Posi;
    QString data;
    QString descricao;
    QString nome;
public:
    virtual void mouseMoveEvent(QMouseEvent *event)=0;
    virtual void mousePressEvent(QMouseEvent *event)=0;
    virtual void destruir()=0;

    virtual QString getNome() = 0;
    virtual QString getdata() = 0;
    virtual QString getdescricao() = 0;

    virtual void setNome(QString) = 0;
    virtual void setdata(QString) = 0;
    virtual void setdescricao(QString) = 0;

    Postit(QWidget* parent = nullptr);
    virtual void paintEvent(QPaintEvent *event) = 0;
};

#endif // POSTIT_H
