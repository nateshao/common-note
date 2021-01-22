# SpringBoot-Vue 前后端分离开发

## 安装Vue.js
- vue安装最新版本 npm install -g @vue/cli 或 yarn global add @vue/cli
- Win + R 输入vue -V 或者vue -version , 出现版本号即Vue可安装完成。
- 继续输入vue ui（vue要3.0以上版本才行） ,启动项目，会自动跳转http://localhost:8080/页面。
- 然后可创建项目vue项目进行开发啦。

### IEDA导入前端工程

### IDEA启动项目
- 打开Terminal 输入npm run serve即可。

### 编写代码

![vuetest结构](https://mateshao.oss-cn-shenzhen.aliyuncs.com/SpringBoot-Vue%20%E5%89%8D%E5%90%8E%E7%AB%AF%E5%88%86%E7%A6%BB%E5%BC%80%E5%8F%91/vuetest%E7%9B%AE%E5%BD%95.png)

配置路由
![](https://mateshao.oss-cn-shenzhen.aliyuncs.com/SpringBoot-Vue%20%E5%89%8D%E5%90%8E%E7%AB%AF%E5%88%86%E7%A6%BB%E5%BC%80%E5%8F%91/%E9%85%8D%E7%BD%AE%E8%B7%AF%E7%94%B1.png)

### 新建Book.vue

```java
<template>
  <div>
    <table>
      <tr>
        <td>编号</td>
        <td>图书名称</td>
        <td>作者</td>
      </tr>
      <tr v-for="item in books">
        <td>{{item.id}}</td>
        <td>{{item.name}}</td>
        <td>{{item.author}}</td>
      </tr>
    </table>
    {{msg}}
  </div>
</template>
<script>
  export default {
    name:"Book",
    data(){
      return{
        msg:"Hello Vue",
        books:[{
            id: 1 ,
            name: '千羽',
            author: '千羽的编程之路'
        },{
          id: 2 ,
          name: '千寻',
          author: 'SpringBoot-Vue 前后端分离开发'
        },{
          id: 3 ,
          name: '小明',
          author: 'SpringBoot入门到精通'
        }
        ]
      }
    },
    created() {
      const _this = this
      axios.get('http://localhost:8181/book/findAll').then(function(resp){
        _this.books = resp.data
      })
  }
  }

</script><style scoped=""></style>
```

配置路由
![配置路由](https://mateshao.oss-cn-shenzhen.aliyuncs.com/SpringBoot-Vue%20%E5%89%8D%E5%90%8E%E7%AB%AF%E5%88%86%E7%A6%BB%E5%BC%80%E5%8F%91/%E9%85%8D%E7%BD%AE%E8%B7%AF%E7%94%B1.png)

在terminal添加axios库：vue add axios

### 新建数据库

```sql

```

create databases library;
use databases;

导入数据

![](https://mateshao.oss-cn-shenzhen.aliyuncs.com/SpringBoot-Vue%20%E5%89%8D%E5%90%8E%E7%AB%AF%E5%88%86%E7%A6%BB%E5%BC%80%E5%8F%91/%E6%95%B0%E6%8D%AE%E5%BA%93.png)

创建SpringBootTest工程
![](https://mateshao.oss-cn-shenzhen.aliyuncs.com/SpringBoot-Vue%20%E5%89%8D%E5%90%8E%E7%AB%AF%E5%88%86%E7%A6%BB%E5%BC%80%E5%8F%91/1.png)
![](https://mateshao.oss-cn-shenzhen.aliyuncs.com/SpringBoot-Vue%20%E5%89%8D%E5%90%8E%E7%AB%AF%E5%88%86%E7%A6%BB%E5%BC%80%E5%8F%91/2.png)

添加lombok,Spring Web,SpringData Jpa,MySQL Driver

配置yml文件
```yaml
spring:
  datasource:
    url: jdbc:mysql://localhost:3306/library?useUnicode=true&characterEncoding=UTF-8&serverTimezone=Asia/Shanghai
    username: root
    password: 123456
    driver-class-name: com.mysql.cj.jdbc.Driver
  jpa:
    show-sql: true
    properties:
      hibernate:
        format_sql: true
server:
  port: 8181
```
创建实体类Book.java
```java
package com.southwind.springboottest.entity;

import lombok.Data;

import javax.persistence.Entity;
import javax.persistence.Id;

@Entity  //类名与表名绑定
@Data
public class Book {   //编写实体类
        @Id
        private Integer id;
        private String name;
        private String author;

}

```

创建BookHandler
```java
package com.southwind.springboottest.controller;

import com.southwind.springboottest.entity.Book;
import com.southwind.springboottest.reporesity.BookReposity;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.Mapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/book")
public class BookHandler {

  @Autowired
  private BookReposity bookReposity;

  @GetMapping("/findAll")
  public List<Book> findAll(){
    return bookReposity.findAll();
  }

}

```

![](https://mateshao.oss-cn-shenzhen.aliyuncs.com/SpringBoot-Vue%20%E5%89%8D%E5%90%8E%E7%AB%AF%E5%88%86%E7%A6%BB%E5%BC%80%E5%8F%91/%E8%B7%A8%E5%9F%9F%E9%97%AE%E9%A2%98.png)

解决跨域问题CrosConfig.java

```java
package com.southwind.springboottest.config;

import org.springframework.context.annotation.Configuration;
import org.springframework.web.servlet.config.annotation.CorsRegistry;
import org.springframework.web.servlet.config.annotation.WebMvcConfigurer;

@Configuration
public class CrosConfig implements WebMvcConfigurer {

  @Override
  public void addCorsMappings(CorsRegistry registry) {
    registry.addMapping("/**")
      .allowedOrigins("*")
      .allowedMethods("GET", "HEAD", "POST", "PUT", "DELETE", "OPTIONS")
      .allowCredentials(true)
      .maxAge(3600)
      .allowedHeaders("*");
  }
}


```
创建BookReposity接口
```java
package com.southwind.springboottest.reporesity;

import com.southwind.springboottest.entity.Book;
import org.springframework.data.jpa.repository.JpaRepository;

public interface BookReposity extends JpaRepository<Book,Integer>{


}

```
debug测试
![](https://mateshao.oss-cn-shenzhen.aliyuncs.com/SpringBoot-Vue%20%E5%89%8D%E5%90%8E%E7%AB%AF%E5%88%86%E7%A6%BB%E5%BC%80%E5%8F%91/%E6%8B%BF%E5%88%B0%E6%95%B0%E6%8D%AE.png)

启动SpringboottestApplication

实现前后端数据交互啦！

![](https://mateshao.oss-cn-shenzhen.aliyuncs.com/SpringBoot-Vue%20%E5%89%8D%E5%90%8E%E7%AB%AF%E5%88%86%E7%A6%BB%E5%BC%80%E5%8F%91/%E7%BB%93%E6%9E%9C.png)


实现技术
Spring Boot + Vue
使⽤ Spring Boot 进⾏后端应⽤开发，使⽤ Vue 进⾏前端应⽤开发。

# Vue + Element UI

> 先了解了一下Element(饿了么) UI，Element-Ul是饿了么前端团队推出的一款基于Vue.js 2.0 的桌面端UI框架。小编感觉它太强大了，主要你会查找和Ctrl + C，会前端开发基本上问题不大。

## Vue 集成 Element UI

前提是要安装好Element插件，

### Element UI 后台管理系统主要的标签：
- el-container：构建整个⻚⾯框架。
- el-aside：构建左侧菜单。
- el-menu：左侧菜单内容，常⽤属性：
	- :default-openeds：默认展开的菜单，通过菜单的 index 值来关联。
	- :default-active：默认选中的菜单，通过菜单的 index 值来关联。
- el-submenu：可展开的菜单，常⽤属性：
- index：菜单的下标，⽂本类型，不能是数值类型。
- template：对应 el-submenu 的菜单名。
- i：设置菜单图标，通过 class 属性实则。
   - el-icon-messae
   - el-icon-menu
   - el-icon-setting
- el-menu-item：菜单的⼦节点，不可再展开，常⽤属性：
- index：菜单的下标，⽂本类型，不能是数值类型。

## Vue router 来动态构建左侧菜单

- 导航1
	- ⻚⾯1
	- ⻚⾯2

- 导航2
	- ⻚⾯3
	- ⻚⾯4

## menu 与 router 的绑定

1. 标签添加 router 属性。
2. 在⻚⾯中添加 标签，它是⼀个容器，动态渲染你选择的 router。
3. 标签的 index 值就是要跳转的 router。

## Element UI 表单数据校验
> 定义 rules 对象，在 rules 对象中设置表单各个选项的校验规则

- required: true, 是否为必填项
- message: 'error', 提示信息
- trigger: 'blur'，触发事件

> vuetest结构层次

![](https://mateshao.oss-cn-shenzhen.aliyuncs.com/SpringBoot-Vue%20%E5%89%8D%E5%90%8E%E7%AB%AF%E5%88%86%E7%A6%BB%E5%BC%80%E5%8F%91/vue%E7%BB%93%E6%9E%84.png)

### AddBook.vue
![](https://mateshao.oss-cn-shenzhen.aliyuncs.com/SpringBoot-Vue%20%E5%89%8D%E5%90%8E%E7%AB%AF%E5%88%86%E7%A6%BB%E5%BC%80%E5%8F%91/%E6%B7%BB%E5%8A%A0%E5%9B%BE%E4%B9%A6.png)
```vue
<template>
    <el-form style="width: 60%" :model="ruleForm" :rules="rules" ref="ruleForm" label-width="100px" class="demo-ruleForm">

        <el-form-item label="图书名称" prop="name">
            <el-input v-model="ruleForm.name"></el-input>
        </el-form-item>

        <el-form-item label="作者" prop="author">
            <el-input v-model="ruleForm.author"></el-input>
        </el-form-item>


        <el-form-item>
            <el-button type="primary" @click="submitForm('ruleForm')">提交</el-button>
            <el-button @click="resetForm('ruleForm')">重置</el-button>
          <el-button @click="test()">test</el-button>
        </el-form-item>

    </el-form>
</template>

<script>
    export default {
        data() {
            return {
                ruleForm: {
                    name: '',
                    author: ''
                },
                rules: {
                    name: [
                        { required: true, message: '图书名称不能为空', trigger: 'blur' }
                    ],
                    author:[
                        { required: true, message: '作者不能为空', trigger: 'blur' }
                    ]
                }
            };
        },
        methods: {
          test(){
            console.log(this.ruleForm)
          },
            submitForm(formName) {
                const _this = this
                this.$refs[formName].validate((valid) => {
                    if (valid) {
                        axios.post('http://localhost:8181/book/save',this.ruleForm).then(function(resp){
                            if(resp.data == 'success'){
                                _this.$alert('《'+_this.ruleForm.name+'》添加成功！', '消息', {
                                    confirmButtonText: '确定',
                                    callback: action => {
                                        _this.$router.push('/BookManage')
                                    }
                                })
                            }
                        })
                    } else {
                        return false;
                    }
                });
            },
            resetForm(formName) {
                this.$refs[formName].resetFields();
            }
        }
    }
</script>

```

### BookManage.vue

```vue
<template>
    <div>
        <el-table
                :data="tableData"
                border
                style="width: 70%">
            <el-table-column
                    fixed
                    prop="id"
                    label="编号"
                    width="150">
            </el-table-column>
            <el-table-column
                    prop="name"
                    label="图书名"
                    width="120">
            </el-table-column>
            <el-table-column
                    prop="author"
                    label="作者"
                    width="120">
            </el-table-column>
            <el-table-column
                    fixed="right"
                    label="操作"
                    width="100">
                <template slot-scope="scope">
                    <el-button @click="edit(scope.row)" type="text" size="small">修改</el-button>
                    <el-button @click="deleteBook(scope.row)" type="text" size="small">删除</el-button>
                </template>
            </el-table-column>
        </el-table>

        <el-pagination
                background
                layout="prev, pager, next"
                :page-size="pageSize"
                :total="total"
                @current-change="page">
        </el-pagination>
    </div>
</template>

<script>
    export default {
        methods: {
            deleteBook(row){
                const _this = this
                axios.delete('http://localhost:8181/book/deleteById/'+row.id).then(function(resp){
                    _this.$alert('《'+row.name+'》删除成功！', '消息', {
                        confirmButtonText: '确定',
                        callback: action => {
//                          动态刷新
                            window.location.reload()
                        }
                    })
                })
            },
            edit(row) {
                this.$router.push({
                    path: '/update',
                    query:{
                        id:row.id
                    }
                })
            },
            page(currentPage){
                const _this = this
                axios.get('http://localhost:8181/book/findAll/'+currentPage+'/6').then(function(resp){
                    console.log(resp)
                    _this.tableData = resp.data.content
                    _this.pageSize = resp.data.size
                    _this.total = resp.data.totalElements
                })
            }
        },

        data() {
            return {
                pageSize:'1',
                total:'11',
                tableData: null
            }
        },

        created() {
            const _this = this
            axios.get('http://localhost:8181/book/findAll/1/6').then(function(resp){
                console.log(resp)
                _this.tableData = resp.data.content
                _this.pageSize = resp.data.size
                _this.total = resp.data.totalElements
            })
        }
    }
</script>

```

### BookUpdate
![](https://mateshao.oss-cn-shenzhen.aliyuncs.com/SpringBoot-Vue%20%E5%89%8D%E5%90%8E%E7%AB%AF%E5%88%86%E7%A6%BB%E5%BC%80%E5%8F%91/%E4%BF%AE%E6%94%B9.png)

```vue
<template>
    <el-form style="width: 60%" :model="ruleForm" :rules="rules" ref="ruleForm" label-width="100px" class="demo-ruleForm">

        <el-form-item label="图书编号">
            <el-input v-model="ruleForm.id" readOnly></el-input>
        </el-form-item>

        <el-form-item label="图书名称" prop="name">
            <el-input v-model="ruleForm.name"></el-input>
        </el-form-item>

        <el-form-item label="作者" prop="author">
            <el-input v-model="ruleForm.author"></el-input>
        </el-form-item>

        <el-form-item>
            <el-button type="primary" @click="submitForm('ruleForm')">修改</el-button>
            <el-button @click="resetForm('ruleForm')">重置</el-button>
        </el-form-item>

    </el-form>
</template>

<script>
    export default {
        data() {
            return {
                ruleForm: {
                    id: '',
                    name: '',
                    author: ''
                },
                rules: {
                    name: [
                        { required: true, message: '图书名称不能为空', trigger: 'blur' }
                    ],
                    author:[
                        { required: true, message: '作者不能为空', trigger: 'blur' }
                    ]
                }
            };
        },
        methods: {
            submitForm(formName) {
                const _this = this
                this.$refs[formName].validate((valid) => {
                    if (valid) {
                        axios.put('http://localhost:8181/book/update',this.ruleForm).then(function(resp){
                            if(resp.data == 'success'){
                                _this.$alert('《'+_this.ruleForm.name+'》修改成功！', '消息', {
                                    confirmButtonText: '确定',
                                    callback: action => {
                                        _this.$router.push('/BookManage')
                                    }
                                })
                            }
                        })
                    } else {
                        return false;
                    }
                });
            },
            resetForm(formName) {
                this.$refs[formName].resetFields();
            }
        },
        created() {

            const _this = this
            axios.get('http://localhost:8181/book/findById/'+this.$route.query.id).then(function(resp){
                _this.ruleForm = resp.data
            })
        }
    }
</script>

```

配置路由/router/index.js

```vue
import Vue from 'vue'
import VueRouter from 'vue-router'
import BookManage from '../views/BookManage'
import AddBook from '../views/AddBook'
import Index from '../views/Index'
import BookUpdate from '../views/BookUpdate'

Vue.use(VueRouter)

const routes = [
  {
    path:"/",
    name:"图书管理",
    component:Index,
    show:true,
    redirect:"/BookManage",
    children:[
      {
        path:"/BookManage",
        name:"查询图书",
        component:BookManage
      },
      {
        path:"/AddBook",
        name:"添加图书",
        component:AddBook
      }
    ]
  },
  {
    path:'/update',
    component:BookUpdate,
    show:false
  }
]

const router = new VueRouter({
  mode: 'history',
  base: process.env.BASE_URL,
  routes
})

export default router

```

> 后端springbootTest代码实现BookHandler.java

`
package com.southwind.springboottest.controller;

import com.southwind.springboottest.entity.Book;
import com.southwind.springboottest.reporesity.BookReposity;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.PageRequest;
import org.springframework.data.domain.Pageable;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/book")
public class BookHandler {

  @Autowired
  private BookReposity bookReposity;

  @GetMapping("/findAll/{page}/{size}")
  public Page<Book> findAll(@PathVariable("page") Integer page, @PathVariable("size") Integer size){
    Pageable pageable = PageRequest.of(page-1,size);
    return bookReposity.findAll(pageable);
  }

  @PostMapping("/save")
  public String  save(@RequestBody Book book ){

    Book result = bookReposity.save(book);
    if(result != null){
      return "success";
    }else {
      return "error";
    }

  }
  @GetMapping("/findById/{id}")
  public Book findById(@PathVariable("id") Integer id){
    return bookReposity.findById(id).get();
  }

  @PutMapping("/update")
  public String update(@RequestBody Book book ) {
    Book result = bookReposity.save(book);
    if (result != null) {
      return "success";
    } else {
      return "error";
    }
  }
  @DeleteMapping("/deleteById/{id}")
  public void deleteById(@PathVariable("id") Integer id){
    bookReposity.deleteById(id);

  }

}

`

当然，在测试每一个功能时，建议在BookReposity接口上创建一个测试类BookReposityTest，测试看看是否成功
`
package com.southwind.springboottest.reporesity;

import com.southwind.springboottest.entity.Book;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import static org.junit.jupiter.api.Assertions.*;
@SpringBootTest
class BookReposityTest {

  @Autowired
  private BookReposity bookReposity;

  //测试查找所有数据
  @Test
  void findAll(){
    System.out.println(bookReposity.findAll());
  }

  //添加测试
  @Test
  void save(){
    Book book = new Book();
    book.setName("张三");
    book.setAuthor("李四");
    Book save = bookReposity.save(book);
    System.out.println(save);

  }

  @Test
  void findById(){
    Book book = bookReposity.findById(1).get();
    System.out.println(book);

  }

  //测试修改
  @Test
  void update(){
    Book book = new Book();
    book.setId(12);
    book.setName("测试测试");
    Book save = bookReposity.save(book);
    System.out.println(save);
  }
  //测试删除
  @Test
  void delete(){
    bookReposity.deleteById(12);
  }
}

`

## 功能展示
![](https://mateshao.oss-cn-shenzhen.aliyuncs.com/SpringBoot-Vue%20%E5%89%8D%E5%90%8E%E7%AB%AF%E5%88%86%E7%A6%BB%E5%BC%80%E5%8F%91/%E6%9F%A5%E8%AF%A2%E5%9B%BE%E4%B9%A6.png)