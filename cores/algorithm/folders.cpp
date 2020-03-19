#include "folders.h"

#include <shlobj.h>

Folders::Folders()
  : system_name_ {System::getPrettyOsName()}
{
}

void Folders::tryToCreateDirWithCleanup(const QString& path)
{
  if (system_name_ == SystemNames::WINDOWS){
    QDir qdir(path);
    if (qdir.exists()){
      qdir.removeRecursively();
    }
   qdir.mkpath(path);
  }
}

void Folders::tryToCreateDir(const QString& path)
{
  if (system_name_ == SystemNames::WINDOWS){
    QDir qdir(path);
    if (qdir.exists()){
      return;
    }
   qdir.mkpath(path);
  }
}

bool Folders::createStartMenuEntry(
  const QString& program_path,
  const QString& start_menu_folder,
  const QString& link_name,
  const QString& shortcut_disription
)
{

  WCHAR startMenuPath[MAX_PATH];
  HRESULT result = SHGetFolderPathW(NULL, CSIDL_PROGRAMS, NULL, 0, startMenuPath);

  if (SUCCEEDED(result)) {
      QDir dir(QString::fromWCharArray(startMenuPath) + QDir::separator() + start_menu_folder);
      if (!dir.exists()){
        dir.mkdir(".");
      }
      QString linkPath = dir.absoluteFilePath(link_name);
      CoInitialize(NULL);
      IShellLinkW* shellLink = NULL;
      result = CoCreateInstance(CLSID_ShellLink, NULL, CLSCTX_ALL, IID_IShellLinkW, (void**)&shellLink);
      if (SUCCEEDED(result)) {
          shellLink->SetPath(program_path.toStdWString().c_str());
          shellLink->SetDescription(shortcut_disription.toStdWString().c_str());
          shellLink->SetIconLocation(program_path.toStdWString().c_str(), 0);
          IPersistFile* persistFile;
          result = shellLink->QueryInterface(IID_IPersistFile, (void**)&persistFile);

          if (SUCCEEDED(result)) {
              result = persistFile->Save(linkPath.toStdWString().c_str(), TRUE);

              persistFile->Release();
          } else {
              return false;
          }
          shellLink->Release();
      } else {
          return false;
      }
  } else {
      return false;
  }
  return true;
}
