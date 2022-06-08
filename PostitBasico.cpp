#include "PostitBasico.h"

PostitBasico::PostitBasico(QWidget* parent) : Postit(parent)
{}

QString PostitBasico::getNome(){return nome;}
QString PostitBasico::getdata(){return data;}
QString PostitBasico::getdescricao(){return descricao;}
void PostitBasico::setNome(QString a){this->nome = a;}
void PostitBasico::setdata(QString a){this->data = a;}
void PostitBasico::setdescricao(QString a){this->descricao = a;}

void PostitBasico::paintEvent(QPaintEvent *event) {

    this->setText("Data: " + data + "\n" + "Descrição: " + descricao);
    QPalette p;
    p.setColor(QPalette::Window, Qt::white);
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

void PostitBasico::mouseMoveEvent(QMouseEvent *event)
{    
        QPointF pontoAnteriorCursor = Posi;
        QPointF pontoAtualCursor = event->globalPosition();

        QPoint pontoAnteriorFigura = this->pos();

        float pontoAtualFigura_x = (pontoAtualCursor.rx() - pontoAnteriorCursor.rx()) + pontoAnteriorFigura.rx();
        float pontoAtualFigura_y = (pontoAtualCursor.ry() - pontoAnteriorCursor.ry()) + pontoAnteriorFigura.ry();

        this->setGeometry(pontoAtualFigura_x, pontoAtualFigura_y, width(), height());
        Posi = pontoAtualCursor;
}

void PostitBasico::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::RightButton){
        destruir();
    }
    else if(event->button() == Qt::LeftButton){
        Posi = event->globalPosition();
    }
}

PostitBasico::PostitBasico(QString nome1, QString data1, QString descricao1, QWidget *parent) : Postit(parent){
   data = data1;
   descricao = descricao1;
   nome = nome1;
   this->setGeometry(600,256,140,170);
}

