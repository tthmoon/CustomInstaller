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

  connect(core_, SIGNAL(installSuccess()), this, SLOT(slotGoToFinishPage()) );
}

void InstallProcessPage::initializePage(){
  core_->startProcess();
}

void InstallProcessPage::slotGoToFinishPage(){
  wizard()->next();
}

InstallProcessPage::~InstallProcessPage()
{
  delete ui;
}
