# NiTiS Languages Runtime
[![bug](https://img.shields.io/github/issues/nitis-languages/runtime/bug?style=flat-square&color=CC3F3F&label=bug)](https://github.com/nitis-languages/runtime/labels/bug)

* [What is NLR?](#what-is-nlr)
* [How can I contribute?](#how-can-i-contribute)
* [How to build](#how-to-build)

## What is NLR?
Official documentation: <https://nitis-languages.github.io>
> Later

### Supported OS
Currently development aimed to Windows, but in future we are planning add support to more systems.

## About Contribution
You can read contribution rules in [this file](CONTRIBUTING.md)

## How to build
Before building ensure that our OS is supported

Requirements:
+ CMake [\[download\]](https://cmake.org/download/)
+ C/C++ compiler:
	+ MSVC on Windows [\[download\]](https://visualstudio.microsoft.com/downloads/)

### Build via terminal
#### Windows

Create build files
```shell
cmake -Ssrc/nlr-core/ -Bbuild
```

Build project
```shell
cmake --build build --config Release
```

The output files will be in `bin/` directory.

### Build via IDE
#### VSCode
You can use `CTRL+SHIFT+D` to open *Run and Debug* menu in VSCode.  
In this menu choose suitable option for you.
Then press green button or `F5` key on keyboard to launch.