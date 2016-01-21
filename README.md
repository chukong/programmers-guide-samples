# programmers-guide-samples

## Conventions used in this book

* `auto` is used for creating local variables.
* `using namespace cocos2d;` is used to shorten types.
* each chapter has a compilable source code sample to demonstrate concepts.
* each chapter should subclass `Ref`
* each chapter should do as much work in the constructor. no need for `::init()`
* model the code design after chapter 2's example code. Follow these same conventions.

## Prerequisites
* make sure to drop in the pre-built libraries into __libs/__.
For iOS you should have:
```
libs/libcocos2d iOS.a
```
For Android you should have everything if you have the Cocos app installed. If you do not, you can drop the pre-built libraries into __libs/__ and edit your projects config to reflect this.

For Windows 10 UWP and Windows 8.1 Universal App projects (WinRT Platforms) it is easier to work with the cocos2d-x source. Do the following:
```
$ cd programmers-guide-samples/cpp
$ git clone https://github.com/cocos2d/cocos2d-x.git cocos2d
$ cd cocos2d
$ git submodule update --init
$ download-deps.py
```
This will setup the cocos2d-x code needed by the Windows 10 and 8.1 projects.


## How to compile the samples
iOS:
```
$ git clone https://github.com/chukong/programmers-guide-samples.git
$ cd programmers-guide-samples/cpp
$ open proj.ios_mac/Programmers\ Guide.xcodeproj/
```
Android:
```
$ git clone https://github.com/chukong/programmers-guide-samples.git
$ cd programmers-guide-samples/cpp
$ cd proj.android
$ cocos run -p android
```
Windows 10 UWP (WinRT Platform):
```
$ git clone https://github.com/chukong/programmers-guide-samples.git
$ cd programmers-guide-samples/cpp
$ cd proj.win10

1. Open test.sln with VS2015 update 1
2. Select the Debug/x86 configuration
3. Right click on the test project and select Set as StartUp Project from the menu
4. Select Start Debugging from the Debug menu

```
Windows 8.1 Universal App (WinRT Platform):
```
$ git clone https://github.com/chukong/programmers-guide-samples.git
$ cd programmers-guide-samples/cpp
$ cd proj.win8.1-universal

1. Open test.sln with VS2015 Update 1 or Visual Studio 2013 Update 4 or 5
2. Select the Debug/x86 configuration
3. Right click on the test project and select Set as StartUp Project from the menu
4. Select Start Debugging from the Debug menu
```
