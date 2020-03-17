#ifndef FOLDERS_H
#define FOLDERS_H

#include "names.h"
#include "system/system.h"

#include <QDir>

using namespace System;

class Folders
{
public:
  Folders();
  void tryToCreateDir(const QString &path);
private:
  SystemNames system_name_;
};

#endif // FOLDERS_H
