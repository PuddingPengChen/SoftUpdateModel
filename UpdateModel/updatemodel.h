#ifndef UPDATEMODEL_H
#define UPDATEMODEL_H

#include <QMainWindow>
#include "./AutoUpdate/updatemanager.h"



namespace Ui {
class UpdateModel;
}

class UpdateModel : public QMainWindow
{
    Q_OBJECT

public:
    explicit UpdateModel(QWidget *parent = 0);
    ~UpdateModel();

private:
    Ui::UpdateModel *ui;
    UpdateManager* updater;

//    void AutoCheckForUpdates();
};
#endif // UPDATEMODEL_H
