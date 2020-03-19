#ifndef FILES_H
#define FILES_H

#include "names.h"
#include "system/system.h"

#include <QProcess>
#include <QDir>

using SystemNames = System::SystemNames;

class Files
{
public:
  Files();
  void runApp(const QString &app_path, QStringList args, int msec_timeout);
  void appendToFile(const QString &file_path, QString txt);
  void extractZip(const QString &zip_path, const QString &output_path);
  void copyFile(const QString &file_path, const QString &dist_file_path);
private:
  SystemNames system_name_;
  QString addCmdCommas(QString string);
};

#endif // FILES_H
