#include "basewizard.h"

#include <QIcon>

BaseWizard::BaseWizard(QWidget* parent)
  : QWizard(parent)
{
  setWizardStyle(QWizard::ModernStyle);
  setWindowIcon(QIcon(":/images/icon"));

  setButtonText(QWizard::NextButton, tr("Next"));
  setButtonText(QWizard::FinishButton, tr("Finish"));
  setButtonText(QWizard::BackButton ,tr("Back"));
  setButtonText(QWizard::CancelButton, tr("Cancel"));
}

