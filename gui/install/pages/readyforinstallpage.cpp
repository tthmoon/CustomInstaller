#include "readyforinstallpage.h"
#include "ui_readyforinstallpage.h"

ReadyForInstallPage::ReadyForInstallPage(QWidget *parent) :
  BasePage(parent),
  ui(new Ui::ReadyForInstallPage)
{
  ui->setupUi(this);
  setTitle(tr("All Ready for install Page Title"));
  setSubTitle(" ");
//  setButtonText(QWizard::NextButton, tr("Install"));
  ui->lab_memory_req->setText( ui->lab_memory_req->text().arg("650"));
  setCommitPage(true);
}
void ReadyForInstallPage::initializePage(){
}

ReadyForInstallPage::~ReadyForInstallPage()
{
  delete ui;
}
