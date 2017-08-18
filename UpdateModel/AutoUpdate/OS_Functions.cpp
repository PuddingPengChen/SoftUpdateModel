/*************************************************************************************
//
//  LICENSE INFORMATION
//
//  BCreator(tm)
//  Software for the control of the 3D Printer, "Creator"(tm)
//
//  Copyright 2011-2012 Creations, LLC
//  Creations(tm) and Creator(tm) are trademarks of Creations, LLC
//
//  This file is part of Creator
//
//    Creator is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    Creator is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with Creator .  If not, see <http://www.gnu.org/licenses/>.
//
//  The above copyright notice and this permission notice shall be
//    included in all copies or substantial portions of the Software.
//
//    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
//    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
//    LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
//    OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
//    WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
*************************************************************************************/

#include "OS_Functions.h"
#include <QFileDialog>

#include <QDebug>
#include <stdio.h>
#include <QCoreApplication>
#include <QDesktopServices>
#include <QDir>
#include <QMessageBox>
#include <QApplication>


#ifdef Q_OS_WIN
    #include "Windows.h"
#endif



QString CROSS_GetSaveFileName(QWidget * parent,
                                 const QString & caption,
                                 const QString & directory,
                                 const QString & filter,
                                 const QStringList & saveAbleExtensions)
{
    QString saveFileName;

    #ifdef Q_OS_LINUX

        QFileDialog dialog(parent,
                           caption,
                           directory,
                           filter);
        QString chosenDirectory;
        QString chosenFileName;
        QString chosenFilter;
        QString chosenFilter_suffix;



        dialog.setFileMode(QFileDialog::AnyFile);
        dialog.setAcceptMode(QFileDialog::AcceptSave);

        if(dialog.exec())
        {

            chosenDirectory = dialog.directory().path();
            chosenFileName = QFileInfo(dialog.selectedFiles()[0]).completeBaseName();

            saveFileName = chosenDirectory + "/" + chosenFileName;

            //check if we need to apply a suffix
            if(QFileInfo(saveFileName).completeSuffix().isEmpty())
            {
                chosenFilter = dialog.selectedNameFilter();

                qDebug() << chosenFilter;

                chosenFilter_suffix = chosenFilter.split("*")[1].remove(1);
                chosenFilter_suffix.chop(1);

                saveFileName += chosenFilter_suffix;
            }
        }

        return saveFileName;

    #endif
    #ifndef Q_OS_LINUX//windows or mac

        QFileDialog dialog(parent);

        saveFileName = dialog.getSaveFileName(parent,caption,directory,filter,0,QFileDialog::DontConfirmOverwrite);

        if(saveFileName.isEmpty())
            return "";

        QStringList parts = saveFileName.split(".");
        QString extension = parts.last();

        if(saveAbleExtensions.size())
        {
            if(extension != saveAbleExtensions.first())
            {
                saveFileName += "." + saveAbleExtensions.first();
            }
        }


        //now we check if the file already exists, and if we want to replace it.
        if(QFile::exists(saveFileName))
        {
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setText(saveFileName + " Already Exists");
            msgBox.setInformativeText("Do you want to overwrite it?");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::No);
            int choice = msgBox.exec();
            if(choice == QMessageBox::No)
            {
                return "";
            }
        }
        return saveFileName;


    #endif

}


//Returns true filepath for a  update entry
QString CROSS_GetDirectoryFromLocationTag(QString locationtag)
{
    QString dir;
    if(locationtag == "APPLICATION_DIR")
    {
        #ifdef Q_OS_WIN // User/AppData/Local/Creatoions LLC/Creator
            dir = "./";
        #endif
        #ifdef Q_OS_MAC//AppBundle/content/resources
           dir = "./";
        #endif
        #ifdef Q_OS_LINUX
           dir = "./";
        #endif
    }
    if(locationtag == "EXECUTABLE_DIR")
    {
        dir = QCoreApplication::applicationDirPath();
    }
    if(locationtag == "TEMP_DIR")
    {
        dir = "./temp";
    }
    if(locationtag == "DOCUMENTS_DIR")
    {
        dir ="./documents";
    }

    return QDir(dir).absolutePath();
}

//FILE HANDING HELPER FUNCTIONS
//streams in "some random text with spaces" from the opened text file.
//will also read in single word without quotes
//or single word with qoutes.
QString StreamInTextQuotes(QTextStream &stream)
{
    QString str, buff;
    stream >> buff;
    if(buff.count("\"") == 1)
    {
        str = buff;
        do{
            stream >> buff;
            str.append(" ");
            str.append(buff);
        }while(!buff.contains("\""));

        str.remove("\"");
    }
    else if(buff.count("\"") == 2)
    {
        str = buff.remove("\"");
    }
    else
        str = buff;



    return str;
}


//Cursor waiting
void Enable_User_Waiting_Cursor()
{
    QCursor curs;
    curs.setShape(Qt::WaitCursor);
    QApplication::setOverrideCursor(curs);
}

void Disable_User_Waiting_Cursor()
{
    QCursor curs;
    curs.setShape(Qt::ArrowCursor);
    QApplication::setOverrideCursor(curs);
}

