#ifndef INSTALLATIONCORE_H
#define INSTALLATIONCORE_H

#include <QThread>
#include <QBasicTimer>
#include <QDateTime>

#include "../data/dataprovider.h"

class InstallationCore
  : public QThread
{
  Q_OBJECT
signals:
  instalSuccess();
public:
  explicit InstallationCore(DataProvider* data_provider);
  void quit();
  void startProcess();

protected:
  void run() override;

private:
  DataProvider* data_provider_;
  bool work_is_enable_;
  QString addCmdCommas(QString string);
  void appendToFile(QString file_path, QString txt);
  void tryToCreateDir(QString path);
};

#endif // INSTALLATIONCORE_H
