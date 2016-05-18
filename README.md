# SoftUpdateModel
Qt software version update auto check,when website have some change

## How to use it?
1. Use you Qt5 Qtcreator open the sample.pro
2. Build it
3. In the main.cpp file,change the follow funcation to change your local software version:
```markdown
    QApplication::setApplicationName("Sample");
    QApplication::setApplicationVersion("2.0");
```
change the version .
4. Edit you Appcast.xml file , most useful information are in 
```markdown
<enclosure
				url="http://you.com/app/Your%20Great%20App%202.0%20Windows.zip"
				fervor:version="2.0"
				fervor:platform="Q_OS_WIN32"
				length="1656492"
				type="application/octet-stream" />
```

5. Change you main.cpp file,following function:

```markdown
    FvUpdater::sharedUpdater()->SetFeedURL("http://www.xxx.com/Appcast.xml");
```
the software will compare the local software's version and the Server's Appcast.xml file.Your ReleaseNote also put inthe same path of your server.
