#include "folderchoosingpage.h"
#include "ui_folderchoosingpage.h"

#include <QDebug>

FolderChoosingPage::FolderChoosingPage(
  DataProvider* data_provider,
  QWidget *parent
) :
  BasePage(parent),
  ui(new Ui::FolderChoosingPage),
  data_provider_ {data_provider}
{
  ui->setupUi(this);
  setTitle(tr("Folder choosing page title"));
  setSubTitle(" ");
}

void FolderChoosingPage::initializePage(){
  ui->le_folder->setText(data_provider_->installer_.folders_.program_path_);
}

FolderChoosingPage::~FolderChoosingPage()
{
  delete ui;
}

void FolderChoosingPage::on_pb_explore_clicked()
{
  WDirectory::choose(tr("Choose folder in popup"), data_provider_->installer_.folders_.program_path_);
}

bool FolderChoosingPage::validatePage(){
  data_provider_->installer_.folders_.program_path_ = ui->le_folder->text();
  data_provider_->save();
  qDebug() <<"aaa";
  return true;
}
