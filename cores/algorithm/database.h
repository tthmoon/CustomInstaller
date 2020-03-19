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
  explicit DataBase(QString* sql_path, QString* db_path);

  void executeSqlFile(const QString &sql_file_path);
  void removeService(const QString &service_name);
  void addUserToDB(const QString &user, const QString &pass);
  void addService(const QString &service_name, const QString &ini_path);
  void initializeINI(const QString &ini_path);
private:
  QString* ptr_sql_path_;
  QString* ptr_db_path_;
  SystemNames system_name_;
  QString addCmdCommas(const QString& string);
};

#endif // DATABASE_H
