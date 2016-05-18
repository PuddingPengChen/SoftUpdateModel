#include <QApplication>
#include "mainwindow.h"
#include "fvupdater.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	// Prerequisite for the Fervor updater
//    QApplication::setApplicationName("Sample");
//    QApplication::setApplicationVersion("2.0");
	QApplication::setOrganizationName("pypt");
	QApplication::setOrganizationDomain("pypt.lt");

	// Set feed URL before doing anything else
    FvUpdater::sharedUpdater()->SetFeedURL("http://www.bingou3d.com/Appcast.xml");

	// Check for updates automatically
//	FvUpdater::sharedUpdater()->CheckForUpdatesSilent();

	// Show main window
	MainWindow w;
	w.show();
	
	return a.exec();
}
