#include "folders.h"

Folders::Folders()
  : system_name_ {getPrettyOsName()}
{
}
void Folders::tryToCreateDir(const QString& path)
{
  if (system_name_ == SystemNames::WINDOWS){
    QDir qdir(path);
    if (qdir.exists()){
      qdir.removeRecursively();
    }
   qdir.mkpath(path);
  }
}
