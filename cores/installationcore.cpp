#include "installationcore.h"
#include "../names.h"

#include <QFile>
#include <QDir>
#include <QDebug>
#include <QProcess>

#include "qzipreader_p.h"
#include "qzipwriter_p.h"


InstallationCore::InstallationCore(DataProvider* data_provider)
  : data_provider_ {data_provider}
{
}

void InstallationCore::startProcess()
{
  work_is_enable_ = true;
  QThread::start();
}

void InstallationCore::quit()
{
  work_is_enable_ = false;
}

QString InstallationCore::addCmdCommas(QString string)
{
  return "\"" + string + "\"";
}


void InstallationCore::appendToFile(QString file_path, QString txt)
{
  QFile file_a(file_path);
  if(file_a.open(QIODevice::Append|QIODevice::Text)){
      QTextStream outLog(&file_a);
      outLog << (txt + "\n");
  }
  file_a.close();
}

void InstallationCore::tryToCreateDir(QString path)
{
  QDir qdir(path);
  if (qdir.exists()){
    qdir.removeRecursively();
  }
 qdir.mkpath(const_cast<QString&>(path));
}

void InstallationCore::run(){
  qDebug() << "rtest";

  qDebug() << "Пересоздание папочек";
  tryToCreateDir(data_provider_->installer_.folders_.program_path_);
  tryToCreateDir(data_provider_->installer_.folders_.work_path_);
  tryToCreateDir(data_provider_->installer_.folders_.base_path_);
  tryToCreateDir(data_provider_->installer_.folders_.tar_path_);
  tryToCreateDir( QDir::toNativeSeparators(data_provider_->installer_.folders_.base_path_ + "\\data") );
  tryToCreateDir( QDir::toNativeSeparators(data_provider_->installer_.folders_.base_path_ + "\\uploads") );

  qDebug() <<"стоп сервиса";
  QProcess db_service;
  db_service.start(QDir::toNativeSeparators(qgetenv("windir") + "\\system32\\net") + " stop " + INFO::BASE_INFO::SERVICE_NAME);
  db_service.waitForFinished();
  db_service.start(
    addCmdCommas( QDir::toNativeSeparators(data_provider_->installer_.folders_.program_path_ + "\\Database\\bin\\mysqld") )
    + " --remove "
    + INFO::BASE_INFO::SERVICE_NAME
  );
  db_service.waitForFinished();

  qDebug() << "нужна проверка на наличие архива";
  QZipReader* zip = new QZipReader(QDir::currentPath() + QDir::separator() + "data" + QDir::separator() + INFO::FILES::BASE_ARCHIVE);
  zip->extractAll( data_provider_->installer_.folders_.program_path_);
  zip->close();

  qDebug() << "переместить ини и заполнить";
  QFile distIni (data_provider_->installer_.folders_.base_path_ + "\\" + INFO::FILES::BASE_INI);
  if (distIni.exists()){
    distIni.remove();
  }
  QFile::copy(
    data_provider_->installer_.folders_.program_path_ + "\\pre\\install\\" + INFO::FILES::BASE_INI,
    data_provider_->installer_.folders_.base_path_ + "\\" + INFO::FILES::BASE_INI
  );

//  appendToFile(data_provider_->installer_.folders_.base_path_ + "\\" + INFO::FILES::BASE_INI, "port=" + INFO::BASE_INFO::BASE_PORT);
//  appendToFile(data_provider_->installer_.folders_.base_path_ + "\\" + INFO::FILES::BASE_INI, "#	Path ");
//  appendToFile(
//        data_provider_->installer_.folders_.base_path_ + "\\" + INFO::FILES::BASE_INI,
//        "basedir=" + QDir::toNativeSeparators( addCmdCommas(data_provider_->installer_.folders_.program_path_ + "\\Database") )
//  );
//  appendToFile(
//        data_provider_->installer_.folders_.base_path_ + "\\" + INFO::FILES::BASE_INI,
//        "datadir=" + QDir::toNativeSeparators( addCmdCommas(data_provider_->installer_.folders_.base_path_ + "\\data") )
//  );
//  qDebug() << "test";
//  appendToFile(
//        data_provider_->installer_.folders_.base_path_ + "\\" + INFO::FILES::BASE_INI,
//        "secure-file-priv=" + QDir::toNativeSeparators( addCmdCommas(data_provider_->installer_.folders_.base_path_ + "\\uploads") )
//  );

  appendToFile(data_provider_->installer_.folders_.base_path_ + "\\" + INFO::FILES::BASE_INI, "[client]");
  appendToFile(data_provider_->installer_.folders_.base_path_ + "\\" + INFO::FILES::BASE_INI, "port=" + INFO::BASE_INFO::BASE_PORT);

  qDebug() << "установка сервиса";

  QString temp_sql_path = QDir::toNativeSeparators(data_provider_->installer_.folders_.program_path_ + "\\pre\\install\\sql\\");
  QString sql_path = addCmdCommas( QDir::toNativeSeparators(data_provider_->installer_.folders_.program_path_ + "\\Database\\bin\\mysql"));

  db_service.start(
    addCmdCommas( QDir::toNativeSeparators(data_provider_->installer_.folders_.program_path_+ "\\Database\\bin\\mysqld") )
    + " --install "
    + INFO::BASE_INFO::SERVICE_NAME
    + " --defaults-file="
    + addCmdCommas( QDir::toNativeSeparators(data_provider_->installer_.folders_.base_path_ + QDir::separator() + INFO::FILES::BASE_INI))
  );
  qDebug() << addCmdCommas( QDir::toNativeSeparators(data_provider_->installer_.folders_.program_path_+ "\\Database\\bin\\mysqld") )
              + " --install "
              + INFO::BASE_INFO::SERVICE_NAME
              + " --defaults-file="
              + addCmdCommas( QDir::toNativeSeparators(data_provider_->installer_.folders_.base_path_ + QDir::separator() + INFO::FILES::BASE_INI));
  db_service.waitForFinished();
  db_service.start(QDir::toNativeSeparators(qgetenv("windir") + "\\system32\\net") + " start " + INFO::BASE_INFO::SERVICE_NAME);
  qDebug() <<QDir::toNativeSeparators(qgetenv("windir") + "\\system32\\net") + " start " + INFO::BASE_INFO::SERVICE_NAME;
  db_service.waitForFinished();


  qDebug() << "Database Data Init";

  auto addProceduresPack = [&](const QString& file_name)
  {
    db_service.start(
      sql_path
      + " --host=localhost --port="
      + INFO::BASE_INFO::BASE_PORT
      + " -u root --password="
      + INFO::BASE_INFO::BASE_PASS
      + " < "
      + addCmdCommas(temp_sql_path + file_name)
    );
    db_service.waitForFinished();
    qDebug() << sql_path
                + " --host=localhost --port="
                + INFO::BASE_INFO::BASE_PORT
                + " -u root --password="
                + INFO::BASE_INFO::BASE_PASS
                + " < "
                + addCmdCommas(temp_sql_path + file_name);
  };

  db_service.start(
    addCmdCommas( QDir::toNativeSeparators(QDir::toNativeSeparators(data_provider_->installer_.folders_.program_path_ + "\\Database\\bin\\mysqladmin")))
    + " --host=localhost --port="
    + INFO::BASE_INFO::BASE_PORT
    + " --user=root --password=\"\" password "
    + INFO::BASE_INFO::BASE_PASS
  );
  db_service.waitForFinished();

  addProceduresPack("create.sql");
  addProceduresPack("tables.sql");
  addProceduresPack("db_config.sql");
  addProceduresPack("procedures\\general.sql");
  addProceduresPack("procedures\\services.sql");
  addProceduresPack("procedures\\stats.sql");
  addProceduresPack("procedures\\targets_add.sql");
  addProceduresPack("procedures\\targets_process_allvehicles.sql");
  addProceduresPack("procedures\\targets_process_violations.sql");
  addProceduresPack("procedures\\targets_push.sql");
  addProceduresPack("procedures\\device_serials.sql");

  qDebug() << "установка доп по";
  qDebug() << "нужна проверка на наличие по";
  QProcess vcredist;
  QString vsr_path = QDir::toNativeSeparators("\"" + data_provider_->installer_.folders_.program_path_ + "\\pre\\install\\" + INFO::FILES::VCREDIST + "\"");
  vcredist.start(vsr_path , QStringList() << "/quiet" << "/repair" <<  "/norestart");
  vcredist.waitForFinished(60000);


  if (data_provider_->installer_.if_clear_base_dir_){

  }
  emit instalSuccess();

}
