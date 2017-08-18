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

#ifndef LOADINGBAR_H
#define LOADINGBAR_H

#include <QDialog>
#include <QHBoxLayout>
#include <QProgressBar>
#include <QPushButton>


class LoadingBar : public QDialog
{
	Q_OBJECT

public:
    LoadingBar();
    LoadingBar(int min, int max, bool autoshow = true);
	~LoadingBar();

public slots:
	void setMax(int max);
	void setMin(int min);
	void setValue(int val);
	void setDescription(QString str);
    void setProgress(qint64 fraction, qint64 total);
    void useCancelButton(bool use);
	int GetValue();

private:
    void SetupUI(bool autoshow);
	void SetupConnections();
	QHBoxLayout* horizontalLayout;
	QProgressBar* progressBar;
	QPushButton* cancelButton;
};
#endif
