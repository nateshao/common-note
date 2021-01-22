# 千羽的编程时光

# 介绍

hexo + Gitee搭建个人博客  (Hexo和GitHub类似，但是访问比较慢)

### 安装Nodejs

node -v #查看node版本
		npm -v #查看npm版本

### 安装淘宝的cnpm 管理器

npm install -g cnpm --registry=http://registry.npm.taobao.org 

### 安装hexo框架

- npm install hexo-cli -g
- hexo init blog  # 初始化博客
- cd blog   #进入blog目录
- hexo server   #启动本地博客服务

- http://localhost:4000/ #本地访问地址

# 提交到GitHub/Gitee

### Gitee/Github创建一个新的仓库 YourGithubName.github.io

cnpm install --save hexo-deployer-git #在blog目录下安装git部署插件
----
### 配置_config.yml

deploy:
type: git
repo: https://github.com/YourGithubName/YourGithubName.github.io.git

branch: master
-----
### 部署到Gitee仓库里

hexo d 
https://YourGithubName.github.io/ #访问这个地址可以查看博客

## 注意：这里要改一下

![](https://images.gitee.com/uploads/images/2020/0620/082224_d9c5053c_7399667.png)
![](https://images.gitee.com/uploads/images/2020/0620/082136_ce4fb8b4_7399667.png)

# 切换主题 [可到官网查看不同的主题](https://hexo.io/themes/)

### 克隆主题到themes下
git clone https://gitee.com/nateshao/hexo-theme-3-hexo themes/hexo-theme-3-hexo #下载yilia主题到本地

### 修改hexo根目录下的 _config.yml 文件 ： theme: hexo-theme-3-hexo

- hexo c #清理一下
- hexo g #生成
- hexo d #部署到远程Github仓库
- 或者一键 hexo g -d
- https://YourGithubName.github.io/ #查看博客

### 创建新的文章

hexo n "我的第一篇文章" 

### 每一次提交到Gitee,记住一定要在Gitee Pages设置一下哦