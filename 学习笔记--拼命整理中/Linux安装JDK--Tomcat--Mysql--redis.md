# Springboot 启动：java -jar course.jar --spring.profiles.active=prod
# 后台一直启动：nohup java -jar course.jar --spring.profiles.active=prod &

tar -zxvf jdk....

cd jdk1.8.0_121/
[root@iZ2zeia63xtlrnola5zvshZ jdk1.8.0_121]# ll
total 25924
drwxr-xr-x 2 10 143     4096 Dec 13  2016 bin
-r--r--r-- 1 10 143     3244 Dec 13  2016 COPYRIGHT
drwxr-xr-x 4 10 143     4096 Dec 13  2016 db
drwxr-xr-x 3 10 143     4096 Dec 13  2016 include
-rwxr-xr-x 1 10 143  5094116 Dec 13  2016 javafx-src.zip
drwxr-xr-x 5 10 143     4096 Dec 13  2016 jre
drwxr-xr-x 5 10 143     4096 Dec 13  2016 lib
-r--r--r-- 1 10 143       40 Dec 13  2016 LICENSE
drwxr-xr-x 4 10 143     4096 Dec 13  2016 man
-r--r--r-- 1 10 143      159 Dec 13  2016 README.html
-rw-r--r-- 1 10 143      526 Dec 13  2016 release
-rw-r--r-- 1 10 143 21116095 Dec 13  2016 src.zip
-rwxr-xr-x 1 10 143   110114 Dec 13  2016 THIRDPARTYLICENSEREADME-JAVAFX.txt
-r--r--r-- 1 10 143   177094 Dec 13  2016 THIRDPARTYLICENSEREADME.txt
[root@iZ2zeia63xtlrnola5zvshZ jdk1.8.0_121]# pwd
/opt/software/jdk1.8.0_121

[root@iZ2zeia63xtlrnola5zvshZ jdk1.8.0_121]# vim /etc/profile
[root@iZ2zeia63xtlrnola5zvshZ jdk1.8.0_121]# vim /etc/profile

# /etc/profile

# System wide environment and startup programs, for login setup
# Functions and aliases go in /etc/bashrc

# It's NOT a good idea to change this file unless you know what you
# are doing. It's much better to create a custom.sh shell script in
# /etc/profile.d/ to make custom changes to your environment, as this
# will prevent the need for merging in future updates.

pathmunge () {
    case ":${PATH}:" in
        *:"$1":*)
            ;;
        *)
            if [ "$2" = "after" ] ; then
                PATH=$PATH:$1
            else
                PATH=$1:$PATH
            fi
    esac
}


if [ -x /usr/bin/id ]; then
    if [ -z "$EUID" ]; then
        # ksh workaround
        EUID=`/usr/bin/id -u`
        UID=`/usr/bin/id -ru`
    fi
    USER="`/usr/bin/id -un`"
    LOGNAME=$USER
    MAIL="/var/spool/mail/$USER"
fi

# Path manipulation
if [ "$EUID" = "0" ]; then
    pathmunge /usr/sbin
    pathmunge /usr/local/sbin
else
    pathmunge /usr/local/sbin after
    pathmunge /usr/sbin after
fi

HOSTNAME=`/usr/bin/hostname 2>/dev/null`
HISTSIZE=1000
if [ "$HISTCONTROL" = "ignorespace" ] ; then
    export HISTCONTROL=ignoreboth
else
    export HISTCONTROL=ignoredups
fi

export PATH USER LOGNAME MAIL HOSTNAME HISTSIZE HISTCONTROL

# By default, we want umask to get set. This sets it for login shell
# Current threshold for system reserved uid/gids is 200
# You could check uidgid reservation validity in
# /usr/share/doc/setup-*/uidgid file
if [ $UID -gt 199 ] && [ "`/usr/bin/id -gn`" = "`/usr/bin/id -un`" ]; then
    umask 002
else
    umask 022
fi

for i in /etc/profile.d/*.sh /etc/profile.d/sh.local ; do
    if [ -r "$i" ]; then
        if [ "${-#*i}" != "$-" ]; then
            . "$i"
        else
            . "$i" >/dev/null
        fi
    fi
done

unset i
unset -f pathmunge
# 最后一行
JAVA_HOME=/opt/software/jdk1.8.0_121
PATH=$PATH:$JAVA_HOME/bin
# 输入i 
# 按Esc键  :wq!



[root@iZ2zeia63xtlrnola5zvshZ jdk1.8.0_121]# source /etc/profile   # 使配置文件生效
[root@iZ2zeia63xtlrnola5zvshZ jdk1.8.0_121]# echo $JAVA_HOME  # 打印JAVA_HOME路径
/opt/software/jdk1.8.0_121


[root@iZ2zeia63xtlrnola5zvshZ jdk1.8.0_121]# java -version     # 查看Java版本
java version "1.8.0_121"


Tomcat:

tar -zxvf apache-tomcat-7.0.75.tar.gz

## 启动tomcat 
./startup.sh

安装 MySQL
[root@crowd software]# rpm -qa | grep mariadb
mariadb-libs-5.5.56-2.el7.x86_64
[root@crowd software]# rpm -e mariadb-libs-5.5.56-2.el7.x86_64 --nodeps
[root@crowd software]# yum install -y libaio
[root@crowd software]# rpm -ivh MySQL-server-5.5.52-1.el6.x86_64.rpm
[root@crowd software]# rpm -ivh MySQL-client-5.5.52-1.el6.x86_64.rpm
[root@crowd software]# systemctl start mysql.service
[root@crowd software]# mysqladmin -u root password
New password:
Confirm new password:
[root@crowd software]# mysql -u root -p
Enter password:
Welcome to the MySQL monitor. Commands end with ; or \g. Your MySQL connection id is 2
Server version: 5.5.52 MySQL Community Server (GPL)
Copyright (c) 2000, 2016, Oracle and/or its affiliates. All rights reserved. Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners. Type 'help;' or '\h' for help. Type '\c' to clear the current input statement. mysql>
mysql> exit;
Bye

5 设置 MySQL
3.5.1 设置访问授权
mysql> GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' IDENTIFIED BY 'atguigu' WITH GRANT
OPTION;
※重启 MySQL 服务使之生效


mysql> GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' IDENTIFIED BY 'root' WITH GRANT OPTION;
Query OK, 0 rows affected (0.00 sec)

mysql> FLUSH PRIVILEGES;
Query OK, 0 rows affected (0.01 sec)

mysql> 


----------------------------------------------------------------------------

JavaEE 课程系列
—————————————————————————————
1
更多 Java –大数据 –前端 –python 人工智能资料下载，可访问百度：尚硅谷官网
尚筹网
[22-尚硅谷-尚筹网-部署]
1 图纸
2 租赁 ESC 服务器
2.1 网址
https://www.aliyun.com/product/ecs?spm=5176.12825654.h2v3icoap.14.e9392c4a2yR
8Xj&aly_as=XIqIqbY8
2.2 内存选择
由于所有程序、Web 应用、微服务都要在一个实例中运行，所以实例的内存建议
使用 8G 内存。
JavaEE 课程系列
—————————————————————————————
2
更多 Java –大数据 –前端 –python 人工智能资料下载，可访问百度：尚硅谷官网
2.3 实例管理
2.3.1 进入控制台
2.3.2 进入 ECS 控制台
JavaEE 课程系列
—————————————————————————————
3
更多 Java –大数据 –前端 –python 人工智能资料下载，可访问百度：尚硅谷官网
2.3.3 使用 Xshell 远程连接
使用公网地址进行连接
3 安装服务器端运行环境
3.1 上传
3.2 安装 JDK
解压 JDK 压缩包
配置/etc/profile 文件
使用 source 命令使/etc/profile 文件生效
JavaEE 课程系列
—————————————————————————————
4
更多 Java –大数据 –前端 –python 人工智能资料下载，可访问百度：尚硅谷官网
3.3 解压 Tomcat
解压
设置安全组：放行 8080 端口
JavaEE 课程系列
—————————————————————————————
5
更多 Java –大数据 –前端 –python 人工智能资料下载，可访问百度：尚硅谷官网
3.4 安装 MySQL
[root@crowd software]# rpm -qa | grep mariadb
mariadb-libs-5.5.56-2.el7.x86_64
[root@crowd software]# rpm -e mariadb-libs-5.5.56-2.el7.x86_64 --nodeps
[root@crowd software]# yum install -y libaio
[root@crowd software]# rpm -ivh MySQL-server-5.5.52-1.el6.x86_64.rpm
[root@crowd software]# rpm -ivh MySQL-client-5.5.52-1.el6.x86_64.rpm
[root@crowd software]# systemctl start mysql.service
[root@crowd software]# mysqladmin -u root password
New password:
Confirm new password:
[root@crowd software]# mysql -u root -p
Enter password:
Welcome to the MySQL monitor. Commands end with ; or \g. Your MySQL connection id is 2
Server version: 5.5.52 MySQL Community Server (GPL)
Copyright (c) 2000, 2016, Oracle and/or its affiliates. All rights reserved. Oracle is a registered trademark of Oracle Corporation and/or its
JavaEE 课程系列
—————————————————————————————
6
更多 Java –大数据 –前端 –python 人工智能资料下载，可访问百度：尚硅谷官网
affiliates. Other names may be trademarks of their respective
owners. Type 'help;' or '\h' for help. Type '\c' to clear the current input statement. mysql>
mysql> exit;
Bye
3.5 设置 MySQL
3.5.1 设置访问授权
mysql> GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' IDENTIFIED BY 'atguigu' WITH GRANT
OPTION;
※重启 MySQL 服务使之生效
3.5.2 设置统一字符集
第一步：准备配置文件
cp /usr/share/mysql/my-small.cnf /etc/my.cnf
第二步：编辑配置文件
[mysqld]
port = 3306
socket = /var/lib/mysql/mysql.sock
skip-external-locking
key_buffer_size = 16K
max_allowed_packet = 1M
table_open_cache = 4
sort_buffer_size = 64K
read_buffer_size = 256K
read_rnd_buffer_size = 256K
net_buffer_length = 2K
thread_stack = 128K
character-set-server=utf8
JavaEE 课程系列
—————————————————————————————
7
更多 Java –大数据 –前端 –python 人工智能资料下载，可访问百度：尚硅谷官网
3.5.3 拍摄快照
3.6 安装 Redis
3.6.1 安装 gcc-c++
yum install -y gcc-c++
3.6.2 解压编译安装 Redis
[root@crowd software]# tar -zxvf redis-4.0.2.tar.gz
[root@crowd redis-4.0.2]# vim src/Makefile
修改 PREFIX?=/usr/local/redis
[root@crowd redis-4.0.2]# make
[root@crowd redis-4.0.2]# make install
3.6.3 配置 Redis
[root@crowd redis-4.0.2]# cp /opt/software/redis-4.0.2/redis.conf /usr/local/redis/
[root@crowd redis-4.0.2]# mkdir /var/redis
[root@crowd redis-4.0.2]# vim /usr/local/redis/redis.conf
修改下面的配置项：
daemonize yes
logfile "/var/redis/redis.log" dir /usr/local/redis
3.6.4 启动 Redis
[root@crowd redis-4.0.2]# /usr/local/redis/bin/redis-server /usr/local/redis/redis.conf
[root@crowd redis-4.0.2]# /usr/local/redis/bin/redis-cli
JavaEE 课程系列
—————————————————————————————
8
更多 Java –大数据 –前端 –python 人工智能资料下载，可访问百度：尚硅谷官网
4 修改参数
4.1 MySQL 连接信息
访问地址：localhost
用户名：root
密码：atguigu
4.2 Redis 连接信息
主机地址改成 127.0.0.1
4.3 支付接口涉及的被调用地址
notify-url: http://47.115.166.86/pay/notify
return-url: http://47.115.166.86/pay/return
4.4 跨微服务请求、重定向请求的主机地址
把 www.crowd.com 改成 47.115.166.86
5 工程打包
5.1 工程之间关系
5.2 Maven 对于安装顺序的要求
 依赖关系对安装顺序的要求
A 依赖 B
Maven 要求先安装 B，再安装 A
 继承关系对安装顺序的要求
A（子工程）继承 B（父工程）
JavaEE 课程系列
—————————————————————————————
9
更多 Java –大数据 –前端 –python 人工智能资料下载，可访问百度：尚硅谷官网
Maven 要求先安装 B，再安装 A
如果配置聚合，那么对聚合工程执行 install 命令，Maven 就会自动按照正确的
顺序安装各个模块工程。
但是我们现在 common-util 工程没有参与聚合，所以要先单独对 common-util
执行安装。
5.3 SpringBoot 工程打包
5.3.1 目标效果
通过运行 java -jar xxx.jar 命令直接启动 SpringBoot 微服务。此时要求这个 jar
包中包含 SpringBoot 内置的 Tomcat、SpringBoot 环境 jar 包以及其他依赖 jar 包。
5.3.2 实现效果的关键
在SpringBoot所在Maven工程的pom.xml文件中配置build标签使用SpringBoot
指定的 Maven 插件进行打包。
<!-- Maven 构建过程相关配置 -->
<build>
<!-- 构建过程中所需要用到的插件 -->
<plugins>
<!-- 这个插件将 SpringBoot 应用打包成一个可执行的 jar 包 -->
<plugin>
<groupId>org.springframework.boot</groupId>
<artifactId>spring-boot-maven-plugin</artifactId>
</plugin>
</plugins>
</build>
要想使用上面的配置必须让当前工程或父工程继承 SpringBoot。
<!-- 继承 SpringBoot 官方指定的父工程 -->
<parent>
<groupId>org.springframework.boot</groupId>
<artifactId>spring-boot-starter-parent</artifactId>
<version>2.1.6.RELEASE</version>
</parent>
如果在父工程中加入 build 配置，那么各个子工程就都不必加入 build。但是我
们现在的情况是：有的子工程并不是 SpringBoot 微服务，所以哪个需要就给哪个加
上。
也就是下图所示的工程：
JavaEE 课程系列
—————————————————————————————
10
更多 Java –大数据 –前端 –python 人工智能资料下载，可访问百度：尚硅谷官网
5.3.3 打包命令
mvn clean install -Dmaven.test.skip=true
表示先清理、再安装，跳过测试
注意：执行 Maven 命令一定要进入 pom.xml 所在的目录！
6 启动命令
admin-webui.war 包需要放到 Tomcat 的 webapps 目录下，启动 Tomcat
/opt/software/apache-tomcat-7.0.75/bin/startup.sh
微服务
java -jar /opt/packages/atcrowdfunding08-member-eureka-0.0.1-SNAPSHOT.jar
java -jar /opt/packages/atcrowdfunding10-member-mysql-provider-0.0.1-SNAPSHOT.jar
java -jar /opt/packages/atcrowdfunding11-member-redis-provider-0.0.1-SNAPSHOT.jar
java -jar
/opt/packages/atcrowdfunding12-member-authentication-consumer-0.0.1-SNAPSHOT.jar
java -jar /opt/packages/atcrowdfunding13-member-project-consumer-0.0.1-SNAPSHOT.jar
java -jar /opt/packages/atcrowdfunding14-member-order-consumer-0.0.1-SNAPSHOT.jar
java -jar /opt/packages/atcrowdfunding15-member-pay-consumer-0.0.1-SNAPSHOT.jar
java -jar /opt/packages/atcrowdfunding16-member-zuul-0.0.1-SNAPSHOT.jar





