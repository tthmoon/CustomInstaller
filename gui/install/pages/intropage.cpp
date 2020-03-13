#include "intropage.h"
#include "ui_intropage.h"

IntroPage::IntroPage(QWidget *parent) :
  BasePage(parent),
  ui(new Ui::IntroPage)
{
  ui->setupUi(this);
  setTitle(tr("Intro Page Title"));
  setSubTitle(" ");
}

IntroPage::~IntroPage()
{
  delete ui;
}
