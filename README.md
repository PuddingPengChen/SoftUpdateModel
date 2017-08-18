# CPUpdate  软件更新模块

本模块专用于软件启动后自动更新，方便嵌入到各种Qt的应用程序中。(Qt5已测试)

### 1.使用方法

本工程中的AutoUpdate是自动更新所需要的全部依赖。

按照如下代码即可调用模块:
    
		
    UpdateManager* updater = new UpdateManager();
    updater->TransitionFromPreviousVersions();

    //Schedule an auto update check
    QTimer::singleShot(1000,updater,SLOT(AutoCheckForUpdates()));



### 2. 文件设置

在工程文件按夹Runfile中，有三个文件。其中Config.ini文件和FileVersion.txt文件放在与可执行文件同级的目录下面。

##### 1. Config.ini文件

文件里面的内容为:

    [updateinfo]
	RemoteManifestFileName=Mainfest_version_1.0.txt
	RemoteManifestPath=http://www.bingou3d.com/UpdateSoft/test1/
	excuteName=UpdateModel.exe

RemoteManifestFileName指定了远程的版本文件，他会和本地的FileVersion.txt做比较，得到需要更新下载的列表

RemoteManifestPath 指定远程版本文件的地址

excuteName 指定要更新的主运行程序的名称

##### 2. Mainfest_version_1.0.txt

这个文件是要放置在服务器上的。下面举例说明用法:

    EXECUTABLE_DIR "UpdateModel.exe" 1859 WIN
	EXECUTABLE_DIR "hello.exe" 2 WIN

第一行的 "UpdateModel.exe"指定了要更新的文件的名称，后面的数字是最新的版本号  最后的WIN标志在window下运行

每个要更新的文件，都可以另起一行来进行


##### 3. FileVersion.txt

放在本地的版本信息文件，每次更新后，会被远程的最新的版本内容给覆盖掉。





