#ifndef INSTALLALGORITHM_H
#define INSTALLALGORITHM_H

#include "process.h"
#include "database.h"
#include "files.h"
#include "folders.h"

#include <QString>

class InstallAlgorithm
{
public:
  explicit InstallAlgorithm(const QString& sql_path, const QString& db_path);
private:
  Process* process_= Q_NULLPTR;
  DataBase* database_ = Q_NULLPTR;
  Files* files_= Q_NULLPTR;
  Folders* folders_= Q_NULLPTR;

};

#endif // INSTALLALGORITHM_H
