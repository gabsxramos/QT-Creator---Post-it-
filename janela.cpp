#include <QTextEdit>
#include <QLabel>
#include <QInputDialog>
#include <QPushButton>
#include <QApplication>
#include <QMessageBox>
#include <QFile>
#include "PostitTrab.h"
#include "postitcompromisso.h"
#include "PostitBasico.h"
#include "postitfesta.h"
#include "janela.h"

Janela::Janela(QWidget *parent):QMainWindow{parent}
{
    this->setGeometry(100,100,1344,756);
    this->setWindowTitle("QUADRO DE POST IT");

    basico = new QPushButton("Basico",this);
    basico->setGeometry(1230,10,100,50);
    connect(basico, SIGNAL(clicked(bool)), this, SLOT(CriarPostitBasico()));

    trabalho = new QPushButton("Trabalho", this);
    trabalho->setGeometry(1230,70,100,50);
    connect(trabalho, SIGNAL(clicked(bool)), this, SLOT(CriarPostitTrab()));

    compromisso = new QPushButton("Compromisso",this);
    compromisso->setGeometry(1230,130,100,50);
    connect(compromisso, SIGNAL(clicked(bool)), this, SLOT(CriarPostitcompromisso()));

    festa = new QPushButton("Festa", this);
    festa->setGeometry(1230,190,100,50);
    connect(festa, SIGNAL(clicked(bool)), this, SLOT(CriarPostitFesta()));

    salvar = new QPushButton("Salvar", this);
    salvar->setGeometry(1230,250,100,50);
    connect(salvar, SIGNAL(clicked(bool)), this, SLOT(Salvar()));

    abrir = new QPushButton("Abrir", this);
    abrir->setGeometry(1230,310,100,50);
    connect(abrir, SIGNAL(clicked(bool)), this, SLOT(Abrir()));
}

void Janela::Salvar()
{
        vector<Postit*>::iterator it;
        QFile Pfile(file);
        if(!Pfile.open(QFile::WriteOnly | QFile::Text)){
            QMessageBox::critical(this, "ERRO", "Nao foi possivel abrir o arquivo");
            return;
        }
        Postit* aux;
        QTextStream saida(&Pfile);
        saida << v.size();
        saida << ",";
        for(it=v.begin(); it!=v.end(); it++){
            aux = *it;
            if(aux->getNome()=="Basico"){
                PostitBasico *auxb = static_cast<PostitBasico*>(aux);
                saida << auxb->x();
                saida << ",";
                saida << auxb->y();
                saida << ",";
                saida << auxb->getNome();
                saida << ",";
                saida << auxb->getdata();
                saida << ",";
                saida << auxb->getdescricao();
                saida << ",";
          }
            else if(aux->getNome()=="Trabalho"){
                PostitTrab *auxt = static_cast<PostitTrab*>(aux);
                saida << auxt->x();
                saida << ",";
                saida << auxt->y();
                saida << ",";
                saida << auxt->getNome();
                saida << ",";
                saida << auxt->getdata();
                saida << ",";
                saida << auxt->getdisciplina();
                saida << ",";
                saida << aux->getdescricao();
                saida << ",";
            }
            else if(aux->getNome()=="Compromisso"){
                PostitCompromisso *auxc = static_cast<PostitCompromisso*>(aux);
                saida << auxc->x();
                saida << ",";
                saida << auxc->y();
                saida << ",";
                saida << auxc->getNome();
                saida << ",";
                saida << auxc->getdata();
                saida << ",";
                saida << auxc->getTipo();
                saida << ",";
                saida << auxc->getdescricao();
                saida << ",";
                saida << auxc->gethorario();
                saida << ",";
           }
            else if(aux->getNome()=="Festa"){
                PostitFesta *auxf = static_cast<PostitFesta*>(aux);
                saida << auxf->x();
                saida << ",";
                saida << auxf->y();
                saida << ",";
                saida << auxf->getNome();
                saida << ",";
                saida << auxf->getdata();
                saida << ",";
                saida << auxf->getEstilo();
                saida << ",";
                saida << auxf->gethorario();
                saida << ",";
           }

        }
Pfile.flush();
Pfile.close();
    return;
}

void Janela::Abrir()
{
    QFile Pfile(file);
    if(!Pfile.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::critical(this, "ERRO", "Nao foi possivel abrir o arquivo");
        return;
    }
    QTextStream in(&Pfile);
    QString PS;
    PS = in.readAll();
    int j = 1;
    QStringList lista = PS.split(QLatin1Char(','), Qt::SkipEmptyParts);
    QString tam = lista[0];
    for(int i = 0; i<tam.toInt(); i++){
        if(lista[j+2]=="Basico"){
              j+=5;
              PostitBasico *b = new PostitBasico(lista[j-3], lista[j-2], lista[j-1], this);
              b->setGeometry(lista[j-5].toInt(), lista[j-4].toInt(), 140, 170);
              v.push_back(b);
              b->show();
        }
        else if(lista[j+2]=="Trabalho"){
              j+=6;
              PostitTrab *t = new PostitTrab(lista[j-4], lista[j-3], lista[j-2], lista[j-1], this);
              t->setGeometry(lista[j-6].toInt(), lista[j-5].toInt(), 140, 170);
              v.push_back(t);
              t->show();
        }
        else if(lista[j+2]=="Compromisso"){
              j+=7;
              PostitCompromisso *c = new PostitCompromisso(lista[j-5], lista[j-4], lista[j-3], lista[j-2], lista[j-2], this);
              c->setGeometry(lista[j-7].toInt(), lista[j-6].toInt(), 140, 170);
              v.push_back(c);
              c->show();
        }
        else if(lista[j+2]=="Festa"){
              j+=7;
              PostitFesta *f = new PostitFesta(lista[j-5], lista[j-4], lista[j-3], lista[j-2], lista[j-2], this);
              f->setGeometry(lista[j-7].toInt(), lista[j-6].toInt(), 140, 170);
              v.push_back(f);
              f->show();

        }
   }
}

void Janela::CriarPostitTrab(){
   QString nome = "Trabalho";
   bool ok;
   bool certo = false;
   QString data;
while(!certo){
   try{
   data = QInputDialog::getText(this, "Data", "Digite sua data:", QLineEdit::Normal, "dd/mm", &ok);
   if(ok==false){return;}
   if(data.length()!=5){throw 1;}
   for(int i = 0; i<2; i++){
       if(!data[i].isDigit()){throw 1;}
   }
   for(int j = 3; j<5; j++){
       if(data[2] != '/' || !data[j].isDigit()){throw 1;}
   }
   certo=true;
   }
catch (int erro) {QMessageBox::critical(this, "ERRO", "Data invalida, digite novamente");}
}
   QString disciplina = QInputDialog::getText(this, "Disciplina", "Digite qual sua disciplina:", QLineEdit::Normal, "", &ok);
   if(ok==false){return;}
   QString descricao = QInputDialog::getText(this, "Descricao", "Digite sua descricao:", QLineEdit::Normal, "", &ok);
   if(ok==false){return;}
   PostitTrab *t = new PostitTrab(nome, data, disciplina, descricao, this);
   t->show();
   v.push_back(t);
}

void Janela::CriarPostitcompromisso(){
   QString nome = "Compromisso";
    bool ok;
   QString horario;
   bool datacerto = false;
   bool horariocerto = false;
   QString data;
while(!datacerto){
   try{
   data = QInputDialog::getText(this, "Data", "Digite sua data:", QLineEdit::Normal, "dd/mm", &ok);
   if(ok==false){return;}
   if(data.length()!=5){throw 1;}
   for(int i = 0; i<2; i++){
       if(!data[i].isDigit()){throw 1;}
   }
   for(int j = 3; j<5; j++){
       if(data[2] != '/' || !data[j].isDigit()){throw 1;}
   }
   datacerto=true;
   }
catch (int erro) {QMessageBox::critical(this, "ERRO", "Data invalida, digite novamente");}
}
   if(ok==false){return;}
   QString tipo = QInputDialog::getText(this, "Disciplina", "Digite qual o tipo do compromisso:", QLineEdit::Normal, "", &ok);
   if(ok==false){return;}
   QString descricao = QInputDialog::getText(this, "Descricao", "Digite sua descricao:", QLineEdit::Normal, "", &ok);
   while(!horariocerto){
      try{
      horario = QInputDialog::getText(this, "Horario", "Digite o Horario:", QLineEdit::Normal, "hh:mm", &ok);
      if(ok==false){return;}
      if(horario.length()!=5){throw 1;}
      for(int i = 0; i<2; i++){
          if(!horario[i].isDigit()){throw 1;}
      }
      for(int j = 3; j<5; j++){
          if(horario[2] != ':' || !horario[j].isDigit()){throw 1;}
      }
      horariocerto=true;
      }
   catch (int erro) {QMessageBox::critical(this, "ERRO", "Horario invalido, digite novamente");}
   }
   PostitCompromisso *c = new PostitCompromisso(nome, data, tipo, descricao, horario, this);
   c->show();
   v.push_back(c);
}

void Janela::CriarPostitBasico(){
   QString nome = "Basico";
    bool ok;
   QString data;
   bool datacerto = false;
while(!datacerto){
   try{
   data = QInputDialog::getText(this, "Data", "Digite sua data:", QLineEdit::Normal, "dd/mm", &ok);
   if(ok==false){return;}
   if(data.length()!=5){throw 1;}
   for(int i = 0; i<2; i++){
       if(!data[i].isDigit()){throw 1;}
   }
   for(int j = 3; j<5; j++){
       if(data[2] != '/' || !data[j].isDigit()){throw 1;}
   }
   datacerto=true;
   }
catch (int erro) {QMessageBox::critical(this, "ERRO", "Data invalida, digite novamente");}
}

   QString descricao = QInputDialog::getText(this, "Descricao", "Digite sua descricao:");
      if(ok==false){return;}
   PostitBasico *b = new PostitBasico(nome, data, descricao, this);
   b->show();
   v.push_back(b);
}

void Janela::CriarPostitFesta(){
    QString nome = "Festa";
    bool ok;
    QString data;
    QString horario;
    bool datacerto = false;
    bool horariocerto = false;
    while(!datacerto){
       try{
       data = QInputDialog::getText(this, "Data", "Digite sua data:", QLineEdit::Normal, "dd/mm", &ok);
       if(ok==false){return;}
       if(data.length()!=5){throw 1;}
       for(int i = 0; i<2; i++){
           if(!data[i].isDigit()){throw 1;}
       }
       for(int j = 3; j<5; j++){
           if(data[2] != '/' || !data[j].isDigit()){throw 1;}
       }
       datacerto=true;
       }
    catch (int erro) {QMessageBox::critical(this, "ERRO", "Data invalida, digite novamente");}
    }
    QString estilo = QInputDialog::getText(this, "estilo", "Digite qual sera o estilo de musica da festa:");
    if(ok==false){return;}
    QString descricao = QInputDialog::getText(this, "Descricao", "Digite sua descricao:");
    if(ok==false){return;}
    while(!horariocerto){
       try{
       horario = QInputDialog::getText(this, "Horario", "Digite o Horario:", QLineEdit::Normal, "hh:mm", &ok);
       if(ok==false){return;}
       if(horario.length()!=5){throw 1;}
       for(int i = 0; i<2; i++){
           if(!horario[i].isDigit()){throw 1;}
       }
       for(int j = 3; j<5; j++){
           if(horario[2] != ':' || !horario[j].isDigit()){throw 1;}
       }
       horariocerto=true;
       }
    catch (int erro) {QMessageBox::critical(this, "ERRO", "Horario invalido, digite novamente");}
    }
    PostitFesta *f = new PostitFesta(nome, data, estilo, descricao, horario, this);
    f->show();
    v.push_back(f);
}
