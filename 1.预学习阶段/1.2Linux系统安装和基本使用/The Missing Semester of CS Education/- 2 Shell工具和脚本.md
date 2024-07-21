# 1
- 阅读 man ls，然后使用`ls` 命令进行如下操作：
    
    - 所有文件（包括隐藏文件）
    - 文件打印以人类可以理解的格式输出 (例如，使用454M 而不是 454279954)
    - 文件以最近访问顺序排序
    - 以彩色文本显示输出结果
    
    典型输出如下：
    
    ```
     -rw-r--r--   1 user group 1.1M Jan 14 09:53 baz
     drwxr-xr-x   5 user group  160 Jan 14 09:53 .
     -rw-r--r--   1 user group  514 Jan 14 06:42 bar
     -rw-r--r--   1 user group 106M Jan 13 12:12 foo
     drwx------+ 47 user group 1.5K Jan 12 18:08 ..
    ```

解答：
```
yeximing@yeximing-laptop:/tmp/missing$ ls -alth --color=yes
total 20K
drwxrwxr-x  2 yeximing yeximing 4.0K Oct  4 23:27 .
-rwxrw-r--  1 yeximing yeximing 2.0K Oct  4 23:27 tms
drwxrwxrwt 23 root     root     4.0K Oct  4 22:47 ..
-rw-rw-r--  1 yeximing yeximing   46 Oct  4 22:19 last-modified.txt
-rwxrw-r--  1 yeximing yeximing   63 Oct  4 21:18 semester

```

# 2
编写两个bash函数 `marco` 和 `polo` 执行下面的操作。 每当你执行 `marco` 时，当前的工作目录应当以某种形式保存，当执行 `polo` 时，无论现在处在什么目录下，都应当 `cd` 回到当时执行 `marco` 的目录。 为了方便debug，你可以把代码写在单独的文件 `marco.sh` 中，并通过 `source marco.sh`命令，（重新）加载函数。

解答：
```
  1  #!/bin/bash
  2  marco(){
  3     echo "$(pwd)" > $HOME/savelocation
  4     echo "perfome sucessfully"
  5  }
  6  polo(){
  7     cd "$(cat "$HOME/savelocation")"
  8  }

```

```
yeximing@yeximing-laptop:/tmp/missing$ vim marco.sh
yeximing@yeximing-laptop:/tmp/missing$ source marco.sh 
yeximing@yeximing-laptop:/tmp/missing$ marco
perfome sucessfully
yeximing@yeximing-laptop:/tmp/missing$ cd
yeximing@yeximing-laptop:~$ polo
yeximing@yeximing-laptop:/tmp/missing$
```

# 3
- 假设您有一个命令，它很少出错。因此为了在出错时能够对其进行调试，需要花费大量的时间重现错误并捕获输出。 编写一段bash脚本，运行如下的脚本直到它出错，将它的标准输出和标准错误流记录到文件，并在最后输出所有内容。 加分项：报告脚本在失败前共运行了多少次。
    
    ```
     #!/usr/bin/env bash
    
     n=$(( RANDOM % 100 ))
    
     if [[ n -eq 42 ]]; then
        echo "Something went wrong"
        >&2 echo "The error was using magic numbers"
        exit 1
     fi
    
     echo "Everything went according to plan"
    ```
解答：
```
  1 #!/bin/bash
  2 
  3 counts=0
  4 ./testerr &>> ctrlscp
  5 
  6 while true
  7 do
  8     ./testerr &>> ctrlscp
  9     if [ $? -ne 0 ]
 10     then
 11         echo "script was performed $counts before failed"
 12         break
 13     fi
 14     ((counts++))
 15 done
```

# 4
您的任务是编写一个命令，它可以递归地查找文件夹中所有的HTML文件，并将它们压缩成zip文件。注意，即使文件名中包含空格，您的命令也应该能够正确执行（提示：查看 `xargs`的参数`-d`）

解答：
```
yeximing@yeximing-laptop:~/test$ find . -name "*.html" | xargs -d"\n" tar cvf html.zip
```

# 5
（进阶）编写一个命令或脚本递归的查找文件夹中最近使用的文件。更通用的做法，你可以按照最近的使用时间列出文件吗？

```
yeximing@yeximing-laptop:~/test$ find . -type f -print0 | xargs -0 ls -lt | head -10
-rw-rw-r-- 1 yeximing yeximing     0 Oct 12 22:50 ./newst
-rw-rw-r-- 1 yeximing yeximing 20480 Oct  9 23:59 ./html.zip
-rw-rw-r-- 1 yeximing yeximing     0 Oct  9 23:49 ./new/new.html
-rw-rw-r-- 1 yeximing yeximing 10240 Oct  9 23:43 ./pp.html
-rw-rw-r-- 1 yeximing yeximing     0 Oct  9 23:30 ./i i.html
-rw-rw-r-- 1 yeximing yeximing     0 Oct  9 23:20 ./u u.html
-rw-rw-r-- 1 yeximing yeximing     0 Oct  9 23:18 ./ww.html
-rw-rw-r-- 1 yeximing yeximing     0 Oct  9 23:17 ./tt.html



yeximing@yeximing-laptop:~/test$ find . -type f -mmin -60 -print0 | xargs -0 ls -lt | head -10
-rw-rw-r-- 1 yeximing yeximing 0 Oct 12 22:50 ./newst

```

```
-mmin 匹配最近修改时间（分钟），—60，六十分钟前

print0 以空格分隔输出

xargs -0 同上
```