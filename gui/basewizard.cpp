#include "basewizard.h"
#include "dialogforms.h"

#include <QIcon>
#include <QAbstractButton>

BaseWizard::BaseWizard(QWidget* parent)
  : QWizard(parent)
{
  setWizardStyle(QWizard::ModernStyle);
  setWindowIcon(QIcon(":/images/icon"));

  setButtonText(QWizard::NextButton, tr("Next"));
  setButtonText(QWizard::FinishButton, tr("Finish"));
  setButtonText(QWizard::BackButton ,tr("Back"));
  setButtonText(QWizard::CancelButton, tr("Cancel"));
  setButtonText(QWizard::CommitButton, tr("Install"));

  disconnect( button( QWizard::CancelButton ), SIGNAL( clicked() ), this, SLOT( reject() ) );
  connect(button( QWizard::CancelButton ), SIGNAL( clicked() ), this, SLOT( slotCancelEvent() ) );
}

void BaseWizard::slotCancelEvent()
{
  if (DialogForms::question(tr("Exit installation title"), tr("Exit question?"))) {
    reject();
  }
}
