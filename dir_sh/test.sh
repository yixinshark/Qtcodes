#!/bin/bash 
echo -e "1\t2\t3"
#--------
fruit=apple
count=5
echo "we have $count ${fruit}(s)"
#--------
echo -e "\e[1;31m This is red text \e[0m"
echo -e "\e[1;42m Green Background \e[0m"
#-------
var=12345
length=${#var}
echo ${#var}
echo $length
#-------

if [ $UID -ne 0 ];
then
    echo Non root user. Please run as root.
else
    echo "Root user"
fi
#---------Find--------
sudo find / -iname "*.sh" #-iname 可以忽略大小写
#寻找目录，可以用-type d 这个参数和管道以及grep合用
find . -maxdepth 2 -type -d | grep c++ #其中-maxdepth 2为最大深度为２,此句意思为寻找c++的目录
#寻找出当前目录下面所有的文件夹
ls -d */ # */表示所有以/结合的，即目录文件
find . -type d -maxdepth 1
#正确使用grep-----------------------grep------
#最长使用的方式：
grep "hello world" -Rn #递归并且打印行号（-n）
#在ｃ或者cpp文件中查找，并且递归查询
grep "hello world" . -r --include *.c --include *.cpp

#-------
#tr 将以'\0'结尾符换成'\n'，从而换行
cat /proc/6785/environ | tr '\0' '\n' | grep QTDIR
#-------
#Shell 进行算数运算，使用 let命令
no1=1
no2=5
let result=no1+no2
echo $result
#或者
result=$[ no1 + no2 ]
echo $result
#或者
result=$(( no1 + 50 ))
echo $result

result=`expr 3 + 4`
echo $result

result=$(expr $no1 + 5)
echo $result
#以上都是用于整数运算，bc则是用于数学运算的高级工具，是一个精密的计算器，包含了大量选项
echo "4 * 0.25" | bc

no=100
result=`echo "$no * 1.5" | bc`
echo $result


#------------------------命令行向.bashrc中添加环境变量或者其他————－－－－－－－－－－
echo 'alias install ="sudo apt-get install"' >> .bashrc # >> 为在末尾追加，>表示覆盖
source .bashrc
#----------------------------------------------------------
