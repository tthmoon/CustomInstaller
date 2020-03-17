#include "intropage.h"
#include "ui_intropage.h"

#include <QDebug>

IntroPage::IntroPage(QWidget *parent) :
  BasePage(parent),
  ui(new Ui::IntroPage)
{
  ui->setupUi(this);
  setTitle(tr("Intro Page Title"));
  setSubTitle(" ");
}

void IntroPage::initializePage(){
}

IntroPage::~IntroPage()
{
  delete ui;
}
