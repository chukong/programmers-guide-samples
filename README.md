# programmers-guide-samples

## Conventions used in this book

* `auto` is used for creating local variables.
* `using namespace cocos2d;` is used to shorten types. 
* each chapter has a compilable source code sample to demonstrate concepts.
* each chapter should subclass `Ref`
* each chapter should do as much work in the constructor. no need for `::init()`
* model the code design after chapter 2's example code. Follow these same conventions.

## How to compile the samples

    $ git clone https://github.com/chukong/programmers-guide-samples.git
    $ cd programmers-guide-samples
    $ git submodule update --init
    $ cd libs/cocos2d-x
    $ ./download-deps.py
    $ cd ../..
    $ open proj.ios_mac/Programmers\ Guide.xcodeproj/
