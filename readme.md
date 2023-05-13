# mementopattern cpp demo code

## Overview

    Memento Patternの使い方

## 使いどころ

    あるオブジェクトの今しかない瞬間を保持しておく必要がある場合に利用します。  
    変更前のオブジェクトを保持しておくことで、以前の状態に戻すことが出来るようになります。  

## Build

    1. このリポジトリをクローンします。  
    2. 以下のコマンドでビルドします。  
    ex. VS2017 の場合  
    powershell.exe cmake -S . -B build -G "\"Visual Studio 15 2017 Win64\""  
    powershell.exe cmake --build build  

    ex. VS2019以上の場合  
    powershell.exe cmake -S . -B build  
    powershell.exe cmake --build build  

    ex. Ninja + LLVMの場合(LLVM 15 win64で検証)  
    powershell.exe cmake -S . -B build -G "\"Ninja Multi-Config\""  
    powershell.exe cmake --build build --config debug

## Licence

[MIT](https://github.com/IwachanOrigin/mementopattern_cpp/blob/master/LICENSE)

