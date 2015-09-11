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

## How to compile the samples
iOS:
```
$ git clone https://github.com/chukong/programmers-guide-samples.git
$ cd programmers-guide-samples
$ open proj.ios_mac/Programmers\ Guide.xcodeproj/
```
Android:
```
$ git clone https://github.com/chukong/programmers-guide-samples.git
$ cd programmers-guide-samples
$ cd proj.android
$ cocos run -p android
```
