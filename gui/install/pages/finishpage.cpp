#include "finishpage.h"
#include "ui_finishpage.h"

FinishPage::FinishPage(QWidget *parent) :
  BasePage(parent),
  ui(new Ui::FinishPage)
{
  ui->setupUi(this);
  setTitle(tr("Finish page title"));
  setSubTitle(" ");
}

FinishPage::~FinishPage()
{
  delete ui;
}
