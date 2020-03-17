#ifndef DATABASE_H
#define DATABASE_H

#include "names.h"
#include "system/system.h"

#include <QProcess>
#include <QDir>

using SystemNames = System::SystemNames;

class DataBase
{
public:
  explicit DataBase(const QString* sql_path, const QString* db_path);

  void removeService();
  void addService();
  void addUserToDB();
  void executeSqlFile(const QString &sql_file_path);
private:
  SystemNames system_name_;
  QString* sql_path_ = Q_NULLPTR;
  QString* db_path_ = Q_NULLPTR;
  QString addCmdCommas(QString string);
};

#endif // DATABASE_H
