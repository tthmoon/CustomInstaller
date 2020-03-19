#include "settingspage.h"
#include "ui_settingspage.h"

#include <QDebug>
#include <QProcess>
#include <QDir>

SettingsPage::SettingsPage(DataProvider* data_provider, QWidget *parent) :
  BasePage(parent),
  ui(new Ui::SettingsPage),
  data_provider_ {data_provider}
{
  ui->setupUi(this);
}

void SettingsPage::initializePage(){
  setTitle(tr("Settings page title"));
  setSubTitle(" ");

  ui->le_path_to_base->setText(data_provider_->installer_.folders_.base_path_);
  ui->le_path_to_work->setText(data_provider_->installer_.folders_.work_path_);
  ui->le_path_to_tar->setText(data_provider_->installer_.folders_.tar_path_);

  ui->cb_if_clear_base->setChecked(data_provider_->installer_.if_clear_base_dir_);
}

bool SettingsPage::validatePage(){
  data_provider_->installer_.folders_.base_path_ = QDir::toNativeSeparators(ui->le_path_to_base->text());
  data_provider_->installer_.folders_.work_path_ = QDir::toNativeSeparators(ui->le_path_to_work->text());
  data_provider_->installer_.folders_.tar_path_  = QDir::toNativeSeparators(ui->le_path_to_tar->text());

  data_provider_->installer_.if_clear_base_dir_  = ui->cb_if_clear_base->isChecked();

  data_provider_->save();


  return true;
}

SettingsPage::~SettingsPage()
{
  delete ui;
}
