#include "installationcore.h"
#include "../names.h"

#include <QFile>
#include <QDir>
#include <QDebug>
#include <QProcess>

#include "qzipreader_p.h"
#include "qzipwriter_p.h"
#include "algorithm/installalgorithm.h"


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

void InstallationCore::run(){

  auto stepIter = [&](bool if_success,const QString& text)
  {
    if (if_success)
      emit successStep(text);
  };

  emit numberOfEvents(10);
  InstallAlgorithm* install_algorithm = new InstallAlgorithm(&data_provider_->installer_.folders_.program_path_, &data_provider_->installer_.folders_.base_path_);

  stepIter(true, tr("Start of installation..."));
  if (!work_is_enable_){
    return;
  }

  QString temp_ini_path = data_provider_->installer_.folders_.program_path_ + QDir::toNativeSeparators("\\pre\\install\\") + INFO::FILES::BASE_INI;
  QString ini_path = data_provider_->installer_.folders_.base_path_ + QDir::separator() + INFO::FILES::BASE_INI;

  stepIter(true, tr("Process mysqld stoping..."));
  if (!work_is_enable_){
    return;
  }

  install_algorithm->process_->killProcess("mysqld.exe");

  stepIter(true, tr("Process mysqld stoping..."));
  if (!work_is_enable_){
    return;
  }

  install_algorithm->process_->stopService(INFO::BASE_INFO::SERVICE_NAME);
  install_algorithm->database_->removeService(INFO::BASE_INFO::SERVICE_NAME);

  stepIter(true, tr("Folders recreating..."));
  if (!work_is_enable_){
    return;
  }

  install_algorithm->folders_->tryToCreateDirWithCleanup(data_provider_->installer_.folders_.program_path_);
  install_algorithm->folders_->tryToCreateDir(data_provider_->installer_.folders_.work_path_);
  install_algorithm->folders_->tryToCreateDir(data_provider_->installer_.folders_.tar_path_);
  if (data_provider_->installer_.if_clear_base_dir_){
    install_algorithm->folders_->tryToCreateDirWithCleanup(data_provider_->installer_.folders_.base_path_);
  }
  else{
    install_algorithm->folders_->tryToCreateDir(data_provider_->installer_.folders_.base_path_);
  }
  install_algorithm->folders_->tryToCreateDir(data_provider_->installer_.folders_.base_path_ + QDir::separator() + "data");
  install_algorithm->folders_->tryToCreateDir(data_provider_->installer_.folders_.base_path_ + QDir::separator() + "uploads");


  stepIter(true, tr("Extracting data..."));
  if (!work_is_enable_){
    return;
  }

  install_algorithm->files_->extractZip(
    QDir::currentPath() + QDir::separator() + "data" + QDir::separator() + INFO::FILES::BASE_ARCHIVE,
    data_provider_->installer_.folders_.program_path_
  );

  stepIter(true, tr("Init files forming..."));
  if (!work_is_enable_){
    return;
  }

  install_algorithm->files_->copyFile(temp_ini_path, ini_path);


  install_algorithm->files_->appendToFile(ini_path, "[client]");
  install_algorithm->files_->appendToFile(ini_path, "port=" + INFO::BASE_INFO::BASE_PORT);

  install_algorithm->database_->initializeINI(ini_path);


  stepIter(true, tr("Service start..."));
  if (!work_is_enable_){
    return;
  }

  install_algorithm->database_->addService(INFO::BASE_INFO::SERVICE_NAME, ini_path);
  install_algorithm->process_->startService(INFO::BASE_INFO::SERVICE_NAME);


  stepIter(true, tr("Init database data..."));
  if (!work_is_enable_){
    return;
  }

  install_algorithm->database_->addUserToDB(INFO::BASE_INFO::BASE_USER, INFO::BASE_INFO::BASE_PASS);


  install_algorithm->database_->executeSqlFile(":/../server/db/sql/create.sql");
  install_algorithm->database_->executeSqlFile(":/../server/db/sql/db_config.sql");
  install_algorithm->database_->executeSqlFile(":/../server/db/sql/tables.sql");

  foreach( const QString &filename, QDir(":/server/db/sql/procedures").entryList()) {
    install_algorithm->database_->executeSqlFile(":/server/db/sql/procedures/" + filename);
  }

  stepIter(true, tr( "VCREDIST installation..."));
  if (!work_is_enable_){
    return;
  }

  qDebug() << "нужна проверка на наличие по";
  install_algorithm->files_->runApp(
     data_provider_->installer_.folders_.program_path_ + QDir::toNativeSeparators("\\pre\\install\\") + INFO::FILES::VCREDIST,
     QStringList() << "/quiet" << "/repair" <<  "/norestart",
     600000
  );

  stepIter(true, tr( "Shortcut creating..."));
  if (!work_is_enable_){
    return;
  }

  install_algorithm->folders_->createStartMenuEntry(
     data_provider_->installer_.shortcut_.target_path_,
     data_provider_->installer_.shortcut_.start_menu_folder_,
     data_provider_->installer_.shortcut_.link_name_,
     data_provider_->installer_.shortcut_.shortcut_disription_
  );

  emit installSuccess();

}
