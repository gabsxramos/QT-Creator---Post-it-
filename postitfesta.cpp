#include "postitfesta.h"

PostitFesta::PostitFesta(QWidget* parent) : Postit(parent)
{}

QString PostitFesta::getNome(){return nome;}
QString PostitFesta::getdata(){return data;}
QString PostitFesta::getdescricao(){return descricao;}
QString PostitFesta::getEstilo(){return estilo;}
QString PostitFesta::gethorario(){return horario;}
void PostitFesta::setNome(QString a){this->nome = a;}
void PostitFesta::setdata(QString a){this->data = a;}
void PostitFesta::setdescricao(QString a){this->descricao = a;}
void PostitFesta::setEstilo(QString a){this->estilo = a;}
void PostitFesta::sethorario(QString a){this->horario = a;}

void PostitFesta::paintEvent(QPaintEvent *event) {
    this->setText("Data: " + data + "\n" + "Estilo: " + estilo + "\n" + "Horario: " + horario + "\n" + "Descrição: " + descricao);
    QPalette p;
    p.setColor(QPalette::Window, QColor(238, 173, 45));
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
PostitFesta::PostitFesta(QString nome1, QString data1, QString estilo1, QString descricao1, QString horario1, QWidget *parent) : Postit(parent){
   data = data1;
   estilo = estilo1;
   descricao = descricao1;
   horario = horario1;
   nome = nome1;
   this->setGeometry(600,256,140,170);
}

void PostitFesta::mouseMoveEvent(QMouseEvent *event)
{
        QPointF pontoAnteriorCursor = Posi;
        QPointF pontoAtualCursor = event->globalPosition();

        QPointF pontoAnteriorFigura = this->pos();

        float pontoAtualFigura_x = (pontoAtualCursor.rx() - pontoAnteriorCursor.rx()) + pontoAnteriorFigura.rx();
        float pontoAtualFigura_y = (pontoAtualCursor.ry() - pontoAnteriorCursor.ry()) + pontoAnteriorFigura.ry();

        this->setGeometry(pontoAtualFigura_x, pontoAtualFigura_y, width(), height());
        Posi = pontoAtualCursor;

}

void PostitFesta::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::RightButton){
        destruir();
    }
    else if(event->button() == Qt::LeftButton){
        Posi = event->globalPosition();
    }
}
