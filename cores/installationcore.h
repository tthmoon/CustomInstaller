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
  installSuccess();
  successStep(QString step_result);
  numberOfEvents(int number);
public:
  explicit InstallationCore(DataProvider* data_provider);
  void quit();
  void startProcess();

protected:
  void run() override;

private:
  DataProvider* data_provider_;
  bool work_is_enable_;
};

#endif // INSTALLATIONCORE_H
