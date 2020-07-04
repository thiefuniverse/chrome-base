# chromium base lib of flythief
裁剪后的Chromium的base库代码. Fork from [chrome-base](https://github.com/bingoli/chrome-base "base")。目前只支持Windows平台的编译.

### base源码说明
基于Chromium的分支79.0.3945.56开发.

## 前置条件
### windows
* 安装 visual studio 2019 (>=16.0.0)
    * 安装windows sdk，且版本大于或等于10.0.18362
* build脚本需要使用python(带win32file包),如果系统使用的python不包含win32file包，需要安装
``` sh
python -m pip install pywin32
```

# 编译说明
运行编译脚本build_debug.bat, 一键编译.

# 编译失败debug
我在fork代码并编译过程中遇到一些编译相关的问题，记录如下:

1. 我的系统默认环境的python版本是2.7,运行时提示不能import win32file,我这边应该是这个版本的python就不自带pywin32的module,我换成使用python3.7,用pip安装了pywin32后解决.

2. 在 ./src/build/vs_toolchain.py 的第226行_SortByHighestVersionNumberFirst 这个函数内运行会出错，提示 sort的时候 int和str不能进行compare,这一点我已经通过对list_of_str_versions进行修改，修复了该问题.
``` sh
  for it in [ 'x86', 'arm', 'arm64', 'x64']:
    if it in list_of_str_versions:
      list_of_str_versions.remove(it)
```
