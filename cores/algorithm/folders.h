#ifndef FOLDERS_H
#define FOLDERS_H

#include "names.h"
#include "system/system.h"

#include <QDir>

using SystemNames = System::SystemNames;

class Folders
{
public:
  Folders();
  void tryToCreateDir(const QString &path);
  bool createStartMenuEntry(
    const QString &program_path,
    const QString &start_menu_folder,
    const QString &link_name,
    const QString &shortcut_disription
      );
  void tryToCreateDirWithCleanup(const QString &path);
private:
  SystemNames system_name_;
};

#endif // FOLDERS_H
