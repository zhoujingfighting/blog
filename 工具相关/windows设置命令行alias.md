## 创建一个bat文件

一般是在用户根目录下创建一个.bat文件, 名字随便起,例如`auto_run.bat`
我的电脑上这个文件路径就是:`c:/user/admin/auto_run.bat`


## 在windows注册表上添加

`win+r`,输入`regedit`,编辑注册表信息`计算机\HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Command Processor`

右键新建一个
* key值随便
* value填写bat文件路径:`c:/user/admin/auto_run.bat`

重启cmd完事儿~


