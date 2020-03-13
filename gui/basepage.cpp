#include "basepage.h"
#include <QGridLayout>

BasePage::BasePage(QWidget* parent)
  :  QWizardPage(parent)
{
  setPixmap(QWizard::LogoPixmap, QPixmap(":/images/logo"));

}

void BasePage::setBody(QWidget* content) {
  QGridLayout* gridlayout_main = new QGridLayout(this);
  gridlayout_main->setObjectName(QStringLiteral("GridLayoutMain"));
  gridlayout_main->addWidget(content, 0, 0);
  setLayout(gridlayout_main);

}
