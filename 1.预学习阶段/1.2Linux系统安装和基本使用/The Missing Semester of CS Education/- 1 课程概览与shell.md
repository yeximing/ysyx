# 1 
使用`echo $SHELL`命令可以查看您的 shell 是否满足要求。如果打印结果为`/bin/bash`或`/usr/bin/zsh`则是可以的。

```
$ echo $SHELL
/bin/bash
```

# 2  
在 `/tmp` 下新建一个名为 `missing` 的文件夹。
```
$ cd /tmp
$ mkdir missing
```

# 3
用 `man` 查看程序 `touch` 的使用手册。
```
$ man touch
```

# 4
用 `touch` 在 `missing` 文件夹中新建一个叫 `semester` 的文件。
```
$ cd ./missing/
$ touch semester
```

# 5
将以下内容一行一行地写入 `semester` 文件：

```
 #!/bin/sh
 curl --head --silent https://missing.csail.mit.edu
```

第一行可能有点棘手， `#` 在Bash中表示注释，而 `!` 即使被双引号（`"`）包裹也具有特殊的含义。 单引号（`'`）则不一样，此处利用这一点解决输入问题。

```
$ vim semester
##写入制定内容
```
 ```
 #!/bin/sh
 curl --head --silent https://missing.csail.mit.edu
 
 
 ##请求头信息并且静默模式

```
# 6
尝试执行这个文件。例如，将该脚本的路径（`./semester`）输入到您的shell中并回车。如果程序无法执行，请使用 `ls` 命令来获取信息并理解其不能执行的原因。
```
$ ./semester
bash: ./semester: Permission denied
$ ls -l semester
-rw-rw-r-- 1 yeximing yeximing 63 Oct  4 21:18 semester

```

# 7
查看 `chmod` 的手册(例如，使用 `man chmod` 命令)
```
$ man chod
```

# 8
使用 `chmod` 命令改变权限，使 `./semester` 能够成功执行，不要使用 `sh semester` 来执行该程序。您的 shell 是如何知晓这个文件需要使用 `sh` 来解析呢？
```
$ chmod 764 semester
$ ls -l
total 4
-rwxrw-r-- 1 yeximing yeximing 63 Oct  4 21:18 semester
$ ./semester
HTTP/1.1 200 Connection established

HTTP/2 200 
server: GitHub.com
content-type: text/html; charset=utf-8
last-modified: Tue, 03 Oct 2023 13:58:35 GMT
access-control-allow-origin: *
etag: "651c1e0b-1fce"
expires: Wed, 04 Oct 2023 13:34:50 GMT
cache-control: max-age=600
x-proxy-cache: MISS
x-github-request-id: B7B4:3A5B:459AE:57B7D:651D67A2
accept-ranges: bytes
date: Wed, 04 Oct 2023 13:24:50 GMT
via: 1.1 varnish
age: 0
x-served-by: cache-sjc1000096-SJC
x-cache: MISS
x-cache-hits: 0
x-timer: S1696425891.831371,VS0,VE103
vary: Accept-Encoding
x-fastly-request-id: eae1ff0755eb1f190750fa536df3c14ff677d204
content-length: 8142


```
# 9
使用 `|` 和 `>` ，将 `semester` 文件输出的最后更改日期信息，写入主目录下的 `last-modified.txt` 的文件中
```
yeximing@yeximing-laptop:/tmp/missing$ ./semester |grep 'last-modified' > last-modified.txt
yeximing@yeximing-laptop:/tmp/missing$ cat last-modified.txt 
last-modified: Tue, 03 Oct 2023 13:58:35 GMT
```

# 10
写一段命令来从 `/sys` 中获取笔记本的电量信息，或者台式机 CPU 的温度。
```
yeximing@yeximing-laptop:/sys/class/power_supply/BAT0$ cat /sys/class/power_supply/BAT0/capacity
100

```