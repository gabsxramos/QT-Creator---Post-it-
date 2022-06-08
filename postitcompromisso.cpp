#include "postitcompromisso.h"

PostitCompromisso::PostitCompromisso(QWidget* parent) : Postit(parent)
{}

QString PostitCompromisso::getNome(){return nome;}
QString PostitCompromisso::getdata(){return data;}
QString PostitCompromisso::getdescricao(){return descricao;}
QString PostitCompromisso::getTipo(){return tipo;}
QString PostitCompromisso::gethorario(){return horario;}
void PostitCompromisso::setNome(QString a){this->nome = a;}
void PostitCompromisso::setdata(QString a){this->data = a;}
void PostitCompromisso::setdescricao(QString a){this->descricao = a;}
void PostitCompromisso::setTipo(QString a){this->tipo = a;}
void PostitCompromisso::sethorario(QString a){this->horario = a;}


void PostitCompromisso::paintEvent(QPaintEvent *event) {
    this->setText("Data: " + data + "\n" + "Tipo: " + tipo + "\n" + "Horario: " + horario + "\n" + "Descrição: " + descricao);
    QPalette p;
    p.setColor(QPalette::Window, QColor(5, 87, 255));
    this->setAutoFillBackground(true);
    this->setPalette(p);
    QLabel::paintEvent(event);
    this->setAlignment(Qt::AlignLeft);
    this->setTextFormat(Qt::PlainText);
    this->setWordWrap(true);
    this->setFrameShape(QFrame::Box);
    this->setFrameShadow(QFrame::Raised);
    this->setMargin(3);

}
PostitCompromisso::PostitCompromisso(QString nome1, QString data1, QString tipo1, QString descricao1, QString horario1, QWidget *parent) : Postit(parent){
   data = data1;
   tipo = tipo1;
   descricao = descricao1;
   horario = horario1;
   nome = nome1;
   this->setGeometry(600,256,140,170);
}

void PostitCompromisso::mouseMoveEvent(QMouseEvent *event)
{
        QPointF pontoAnteriorCursor = Posi;
        QPointF pontoAtualCursor = event->globalPosition();

        QPointF pontoAnteriorFigura = this->pos();

        float pontoAtualFigura_x = (pontoAtualCursor.rx() - pontoAnteriorCursor.rx()) + pontoAnteriorFigura.rx();
        float pontoAtualFigura_y = (pontoAtualCursor.ry() - pontoAnteriorCursor.ry()) + pontoAnteriorFigura.ry();

        this->setGeometry(pontoAtualFigura_x, pontoAtualFigura_y, width(), height());
        Posi = pontoAtualCursor;

}

void PostitCompromisso::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::RightButton){
        destruir();
    }
    else if(event->button() == Qt::LeftButton){
        Posi = event->globalPosition();
    }
}
