#include "installprocesspage.h"
#include "ui_installprocesspage.h"

InstallProcessPage::InstallProcessPage(DataProvider* data_provider, InstallationCore* core, QWidget *parent) :
  BasePage(parent),
  ui(new Ui::InstallProcessPage),
  data_provider_{data_provider},
  core_{core}

{
  ui->setupUi(this);
  setTitle(tr("Istall process page title"));
  setSubTitle(tr(" "));
}

void InstallProcessPage::initializePage(){
  core_->startProcess();
}

InstallProcessPage::~InstallProcessPage()
{
  delete ui;
}
