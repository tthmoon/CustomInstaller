#include "finishpage.h"
#include "ui_finishpage.h"

FinishPage::FinishPage(QWidget *parent) :
  BasePage(parent),
  ui(new Ui::FinishPage)
{
  ui->setupUi(this);
  QPixmap pm(":/images/finish");
  ui->label->setPixmap(pm);
  ui->label->setScaledContents(true);
}

FinishPage::~FinishPage()
{
  delete ui;
}
