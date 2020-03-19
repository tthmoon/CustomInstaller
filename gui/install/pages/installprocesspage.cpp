#include "installprocesspage.h"
#include "ui_installprocesspage.h"

#include <QAbstractButton>
#include <QDebug>

InstallProcessPage::InstallProcessPage(DataProvider* data_provider, InstallationCore* core, QWidget *parent) :
  BasePage(parent),
  ui(new Ui::InstallProcessPage),
  data_provider_{data_provider},
  core_{core}
{
  ui->setupUi(this);
  setTitle(tr("Istall process page title"));
  setSubTitle(tr(" "));
  connect(core_,  SIGNAL(installSuccess()),      this,   SLOT(slotGoToFinishPage()) );
  connect(core_,  SIGNAL(successStep(QString)),  this,   SLOT(slotSuccessStep(QString)) );
  connect(core_,  SIGNAL(numberOfEvents(int)),   this,   SLOT(slotNumberOfEvents(int)) );
  ui->progb_install->setValue(0);
  setCommitPage(true);
  setButtonText(QWizard::CommitButton, tr("Next"));
}

void InstallProcessPage::initializePage(){
  core_->startProcess();
}

bool InstallProcessPage::isComplete() const{
  return false;
}

void InstallProcessPage::slotGoToFinishPage(){
  wizard()->next();
}

void InstallProcessPage::slotSuccessStep(QString txt){
  ui->le_install_info->setText(txt);
  ui->progb_install->setValue(ui->progb_install->value() + 1);
}

void InstallProcessPage::slotNumberOfEvents(int number){
  ui->progb_install->setMaximum(number);
}


InstallProcessPage::~InstallProcessPage()
{
  delete ui;
}
