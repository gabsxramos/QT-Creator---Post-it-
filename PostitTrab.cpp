#include "PostitTrab.h"

PostitTrab::PostitTrab(QWidget* parent) : Postit(parent)
{}

QString PostitTrab::getNome(){return nome;}
QString PostitTrab::getdata(){return data;}
QString PostitTrab::getdescricao(){return descricao;}
QString PostitTrab::getdisciplina(){return disciplina;}
void PostitTrab::setNome(QString a){this->nome = a;}
void PostitTrab::setdata(QString a){this->data = a;}
void PostitTrab::setdescricao(QString a){this->descricao = a;}
void PostitTrab::setdisciplina(QString a){this->disciplina = a;}

void PostitTrab::paintEvent(QPaintEvent *event) {
    this->setText("Data: " + data + "\n" + "Disciplina: " + disciplina + "\n" + "Descrição: " + descricao);
    QPalette p;
    p.setColor(QPalette::Window, QColor(255, 105, 97));
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

PostitTrab::PostitTrab(QString nome1, QString data1, QString disciplina1, QString descricao1, QWidget *parent) : Postit(parent){
   data = data1;
   disciplina = disciplina1;
   descricao = descricao1;
   nome = nome1;
   this->setGeometry(600,256,140,170);
}

void PostitTrab::mouseMoveEvent(QMouseEvent *event)
{
        QPointF pontoAnteriorCursor = Posi;
        QPointF pontoAtualCursor = event->globalPosition();

        QPoint pontoAnteriorFigura = this->pos();

        float pontoAtualFigura_x = (pontoAtualCursor.rx() - pontoAnteriorCursor.rx()) + pontoAnteriorFigura.rx();
        float pontoAtualFigura_y = (pontoAtualCursor.ry() - pontoAnteriorCursor.ry()) + pontoAnteriorFigura.ry();

        this->setGeometry(pontoAtualFigura_x, pontoAtualFigura_y, width(), height());
        Posi = pontoAtualCursor;

}

void PostitTrab::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::RightButton){
        destruir();
    }
    else if(event->button() == Qt::LeftButton){
        Posi = event->globalPosition();
    }
}
