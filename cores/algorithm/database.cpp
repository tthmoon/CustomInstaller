#include "database.h"

DataBase::DataBase(const QString* sql_path, const QString* db_path)
  : sql_path_ {sql_path},
    db_path_ {db_path},
    system_name_ {getPrettyOsName()}
{
}

QString DataBase::addCmdCommas(QString string)
{
  return "\"" + string + "\"";
}


void DataBase::removeService(){
  QProcess db;
  if (system_name_ == SystemNames::WINDOWS){
    db.start(
        addCmdCommas( QDir::toNativeSeparators(sql_path_ + "\\Database\\bin\\mysqld") )
      + " --remove "
      + INFO::BASE_INFO::SERVICE_NAME
    );
    db.waitForFinished();
  }
}

void DataBase::addService(){
  QProcess db;
  if (system_name_ == SystemNames::WINDOWS){
      db.start(
          addCmdCommas( QDir::toNativeSeparators(sql_path_ + "\\Database\\bin\\mysqld") )
        + " --install "
        + INFO::BASE_INFO::SERVICE_NAME
        + " --defaults-file="
        + addCmdCommas( QDir::toNativeSeparators(db_path_ + QDir::separator() + INFO::FILES::BASE_INI))
      );
    db.waitForFinished();
  }
}

void DataBase::addUserToDB(){
  QProcess db;
  if (system_name_ == SystemNames::WINDOWS){
    db.start(
        addCmdCommas( QDir::toNativeSeparators(sql_path_ + "\\Database\\bin\\mysqladmin") )
      + " --host=localhost --port="
      + INFO::BASE_INFO::BASE_PORT
      + " --user="
      + addCmdCommas(INFO::BASE_INFO::BASE_USER)
      + " --password=\"\" password "
      + addCmdCommas(INFO::BASE_INFO::BASE_PASS)
    );
    db.waitForFinished();
  }
}

void DataBase::executeSqlFile(const QString& sql_file_path){
  QProcess db;
  if (system_name_ == SystemNames::WINDOWS){
    db.setStandardInputFile(sql_file_path);
    db.start(
        sql_path
      + " --host=localhost --port="
      + INFO::BASE_INFO::BASE_PORT
      + " --user="
      + addCmdCommas(INFO::BASE_INFO::BASE_USER)
      + " --password="
      + addCmdCommas(INFO::BASE_INFO::BASE_PASS)
    );
    db.waitForFinished();
  }
}
