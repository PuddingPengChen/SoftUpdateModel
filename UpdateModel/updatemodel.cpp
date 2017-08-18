#include "updatemodel.h"
#include "ui_updatemodel.h"

class UpdateManager;

UpdateModel::UpdateModel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UpdateModel)
{
    ui->setupUi(this);
    updater = new UpdateManager();
    updater->TransitionFromPreviousVersions();

    //Schedule an auto update check
    QTimer::singleShot(1000,updater,SLOT(AutoCheckForUpdates()));

}

UpdateModel::~UpdateModel()
{
    delete ui;
}



