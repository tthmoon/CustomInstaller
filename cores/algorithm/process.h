#ifndef PROCESS_H
#define PROCESS_H

#include "names.h"
#include "system/system.h"

#include <QProcess>
#include <QDir>

using SystemNames = System::SystemNames;

class Process
{
public:
  Process();
  void killProcess(const QString &process_name);
  void stopService(const QString &service_name);
  void startService(const QString &service_name);
private:
  const SystemNames system_name_;
};

#endif // PROCESS_H
