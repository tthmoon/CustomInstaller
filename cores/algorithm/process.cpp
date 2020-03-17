#include "process.h"

Process::Process()
{
  system_name_ {getPrettyOsName()};
}

void Process::killProcess(const QString& process_name){
  if (system_name_ == SystemNames::WINDOWS)
    QProcess::execute(QString("taskkill /im %1 /f").arg(process_name));
}

void Process::stopService(const QString& service_name){
  QProcess service;
  if (system_name_ == SystemNames::WINDOWS){
    service.start(QDir::toNativeSeparators(qgetenv("windir") + "\\system32\\net") + " stop " + service_name);
    service.waitForFinished();
  }
}

void Process::startService(const QString& service_name){
  QProcess service;
  if (system_name_ == SystemNames::WINDOWS){
    service.start(QDir::toNativeSeparators(qgetenv("windir") + "\\system32\\net") + " start " + service_name);
    service.waitForFinished();
  }
}
