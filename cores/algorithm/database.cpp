#include "database.h"

#include <QDebug>

DataBase::DataBase(QString* sql_path, QString* db_path)
{
   ptr_sql_path_ = sql_path;
   ptr_db_path_ = db_path;
   system_name_ = System::getPrettyOsName();
}

QString DataBase::addCmdCommas(const QString& string)
{
  return "\"" + string + "\"";
}


void DataBase::removeService(const QString& service_name){
  QProcess db;
  if (system_name_ == SystemNames::WINDOWS){
    db.start(
        addCmdCommas( QDir::toNativeSeparators(*ptr_sql_path_ + "\\Database\\bin\\mysqld") )
      + " --remove "
      + service_name
    );
    db.waitForFinished();
  }
}

void DataBase::addService(const QString& service_name, const QString& ini_path){
  QProcess db;
  if (system_name_ == SystemNames::WINDOWS){
    db.start(
        addCmdCommas( QDir::toNativeSeparators(*ptr_sql_path_ + "\\Database\\bin\\mysqld") )
      + " --install "
      + service_name
      + " --defaults-file="
      + addCmdCommas(ini_path)
    );
    db.waitForFinished();
  }
}

void DataBase::initializeINI(const QString& ini_path){
  QProcess db;
  if (system_name_ == SystemNames::WINDOWS){
    db.start(
        addCmdCommas( QDir::toNativeSeparators(*ptr_sql_path_ + "\\Database\\bin\\mysqld") )
      + " --defaults-file="
      + addCmdCommas(ini_path)
      + " --initialize-insecure --console"
    );
    db.waitForFinished();
  }
}

void DataBase::addUserToDB(const QString& user, const QString& pass){
  QProcess db;
  if (system_name_ == SystemNames::WINDOWS){
    db.start(
        addCmdCommas( QDir::toNativeSeparators(*ptr_sql_path_ + "\\Database\\bin\\mysqladmin") )
      + " --host=localhost --port="
      + INFO::BASE_INFO::BASE_PORT
      + " --user="
      + addCmdCommas(user)
      + " --password=\"\" password "
      + addCmdCommas(pass)
    );
    db.waitForFinished();
  }
}

void DataBase::executeSqlFile(const QString& sql_file_path){
  QProcess db;
  if (system_name_ == SystemNames::WINDOWS){
    db.setStandardInputFile(sql_file_path);
    db.start(
        addCmdCommas( QDir::toNativeSeparators(*ptr_sql_path_ + "\\Database\\bin\\mysql" ))
      + " --host=localhost --port="
      + INFO::BASE_INFO::BASE_PORT
      + " --user="
      + addCmdCommas(INFO::BASE_INFO::BASE_USER)
      + " --password="
      + addCmdCommas(INFO::BASE_INFO::BASE_PASS)
    );
    db.waitForFinished();
    qDebug()<< QDir::toNativeSeparators(*ptr_sql_path_ + "\\Database\\bin\\mysql")
               + " --host=localhost --port="
               + INFO::BASE_INFO::BASE_PORT
               + " --user="
               + addCmdCommas(INFO::BASE_INFO::BASE_USER)
               + " --password="
               + addCmdCommas(INFO::BASE_INFO::BASE_PASS);
  }
}
