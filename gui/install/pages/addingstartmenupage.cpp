#include "addingstartmenupage.h"
#include "ui_addingstartmenupage.h"

#include <shlobj.h>

#include <QDir>
#include <QDebug>
#include <QStringListModel>

AddingStartMenuPage::AddingStartMenuPage(
  DataProvider* data_provider,
  QWidget *parent
) :
  BasePage(parent),
  ui(new Ui::AddingStartMenuPage),
  data_provider_ {data_provider}
{
  ui->setupUi(this);
  setTitle(tr("Adding folder to start menu page title"));
  setSubTitle(tr("Folder choosing algorythm"));
}

bool AddingStartMenuPage::validatePage(){
}

void  AddingStartMenuPage::initializePage(){
  ui->le_folder_name->setText(data_provider_->installer_.shortcut_.start_menu_folder_);
  fillFoldersList();
}

AddingStartMenuPage::~AddingStartMenuPage()
{
  delete ui;
}

void AddingStartMenuPage::fillFoldersList(){
  WCHAR startMenuPath[MAX_PATH];
  HRESULT result = SHGetFolderPathW(NULL, CSIDL_PROGRAMS, NULL, 0, startMenuPath);
  if (SUCCEEDED(result)) {
    QDir dir(QString::fromWCharArray(startMenuPath));
    QStringListModel* list = new QStringListModel( dir.entryList(QDir::Dirs|QDir::NoDotAndDotDot, QDir::Name) );
    ui->lw_existing_folders->setModel(list);
  }
}


void AddingStartMenuPage::on_lw_existing_folders_clicked(const QModelIndex &index)
{
  ui->le_folder_name->setText(index.data(Qt::DisplayRole).toString());
}
