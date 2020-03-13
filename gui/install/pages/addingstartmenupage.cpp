#include "addingstartmenupage.h"
#include "ui_addingstartmenupage.h"

//#include <shlobj.h>

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
//  createStartMenuEntry();
}

bool AddingStartMenuPage::validatePage(){
}

void  AddingStartMenuPage::initializePage(){
  ui->le_folder_name->setText(data_provider_->installer_.shortcut_.start_menu_folder_);
//  fillFoldersList();
}

AddingStartMenuPage::~AddingStartMenuPage()
{
  delete ui;
}

//void AddingStartMenuPage::fillFoldersList(){
//  WCHAR startMenuPath[MAX_PATH];
//  HRESULT result = SHGetFolderPathW(NULL, CSIDL_PROGRAMS, NULL, 0, startMenuPath);
//  if (SUCCEEDED(result)) {
//    QDir dir(QString::fromWCharArray(startMenuPath));
//    QStringListModel* list = new QStringListModel( dir.entryList(QDir::Dirs|QDir::NoDotAndDotDot, QDir::Name) );
//    ui->lw_existing_folders->setModel(list);
//  }
//}

//bool AddingStartMenuPage::createStartMenuEntry()
//{
//  QString targetPath = QDir::toNativeSeparators(data_provider_->installer_.shortcut_.target_path_);

//  WCHAR startMenuPath[MAX_PATH];
//  HRESULT result = SHGetFolderPathW(NULL, CSIDL_PROGRAMS, NULL, 0, startMenuPath);

//  if (SUCCEEDED(result)) {
//      QDir dir(QString::fromWCharArray(startMenuPath) + QDir::separator() + data_provider_->installer_.shortcut_.start_menu_folder_);
//      if (!dir.exists()){
//        dir.mkdir(".");
//      }
//      QString linkPath = dir.absoluteFilePath(data_provider_->installer_.shortcut_.link_name_);
//      qDebug()<<linkPath;
//      CoInitialize(NULL);
//      IShellLinkW* shellLink = NULL;
//      result = CoCreateInstance(CLSID_ShellLink, NULL, CLSCTX_ALL, IID_IShellLinkW, (void**)&shellLink);
//      if (SUCCEEDED(result)) {
//          shellLink->SetPath(targetPath.toStdWString().c_str());
//          shellLink->SetDescription(data_provider_->installer_.shortcut_.shortcut_disription_.toStdWString().c_str());
//          shellLink->SetIconLocation(targetPath.toStdWString().c_str(), 0);
//          IPersistFile* persistFile;
//          result = shellLink->QueryInterface(IID_IPersistFile, (void**)&persistFile);

//          if (SUCCEEDED(result)) {
//              result = persistFile->Save(linkPath.toStdWString().c_str(), TRUE);

//              persistFile->Release();
//          } else {
//              return false;
//          }
//          shellLink->Release();
//      } else {
//          return false;
//      }
//  } else {
//      return false;
//  }
//  return true;
//}


void AddingStartMenuPage::on_lw_existing_folders_clicked(const QModelIndex &index)
{
  ui->le_folder_name->setText(index.data(Qt::DisplayRole).toString());
}
