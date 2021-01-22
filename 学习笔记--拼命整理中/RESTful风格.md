# 你回去了解一下RESTful风格

[REST](https://baike.baidu.com/item/REST/6330506)（英文：**Representational State Transfer**，简称REST）描述了一个架构样式的网络系统，比如 web 应用程序。可以把它理解为一种软件架构风格或设计风格，而不是一个标准。

简单来说，RESTful风格就是把请求参数变成请求路径的一种风格。

- 例如，传统的URL请求格式为:`http://.../queryltems?id=l` 

- 而采用RESTful风格后，其URL请求为:`http://.../items/l` 

从上述两个请求中可以看出，RESTful风格中的URL将请求参数id=1变成了请求路径的一部分，并且URL中的queryltems也变成了items( RESTful风格中的URL不存在动词形式的路径，如queryltems表示查询订单，是一个动词，而items表示订单，为名词)。RESTful风格在HTIP请求中，使用put、delete、post和get方式分别对应添加、删除、修改和查询的操作。不过目前国内开发，还是只使用post和get方式来进行增删改查操作。



![](https://nateshao-blog.oss-cn-shenzhen.aliyuncs.com/img/c8177f3e6709c93d0961007c953df8dcd00054ad)

## 理解RESTful

> 要理解RESTful架构，需要理解Representational State Transfer这个词组到底是什么意思，它的每一个词都有些什么涵义。

REST 指的是一组架构[约束条件](https://baike.baidu.com/item/约束条件)和原则。满足这些约束条件和原则的应用程序或设计就是 RESTful。

- 资源与URI
- 统一资源接口
- 资源的表述
- 资源的链接
- 状态的转移

##  统一资源接口

RESTful架构应该遵循统一接口原则，统一接口包含了一组受限的预定义的操作，不论什么样的资源，都是通过使用相同的接口进行资源的访问。接口应该使用标准的HTTP方法如GET，PUT和POST，并遵循这些方法的语义。

如果按照HTTP方法的语义来暴露资源，那么接口将会拥有安全性和幂等性的特性，例如GET和HEAD请求都是安全的， 无论请求多少次，都不会改变服务器状态。而GET、HEAD、PUT和DELETE请求都是幂等的，无论对资源操作多少次， 结果总是一样的，后面的请求并不会产生比第一次更多的影响。

**下面列出了GET，DELETE，PUT和POST的典型用法:**

## GET

- 安全且幂等
- 获取表示
- 变更时获取表示（缓存）

- 200（OK） - 表示已在响应中发出

- 204（无内容） - 资源有空表示
- 301（Moved Permanently） - 资源的URI已被更新
- 303（See Other） - 其他（如，负载均衡）
- 304（not modified）- 资源未更改（缓存）
- 400 （bad request）- 指代坏请求（如，参数错误）
- 404 （not found）- 资源不存在
- 406 （not acceptable）- 服务端不支持所需表示
- 500 （internal server error）- 通用错误响应
- 503 （Service Unavailable）- 服务端当前无法处理请求

## POST

- 不安全且不幂等
- 使用服务端管理的（自动产生）的实例号创建资源
- 创建子资源
- 部分更新资源
- 如果没有被修改，则不过更新资源（乐观锁）

- 200（OK）- 如果现有资源已被更改

- 201（created）- 如果新资源被创建
- 202（accepted）- 已接受处理请求但尚未完成（异步处理）
- 301（Moved Prermanently）- 资源的URI被更新
- 303（See Other）- 其他（如，负载均衡）
- 400（bad request）- 指代坏请求
- 404 （not found）- 资源不存在
- 406 （not acceptable）- 服务端不支持所需表示
- 409 （conflict）- 通用冲突
- 412 （Precondition Failed）- 前置条件失败（如执行条件更新时的冲突）
- 415 （unsupported media type）- 接受到的表示不受支持
- 500 （internal server error）- 通用错误响应
- 503 （Service Unavailable）- 服务当前无法处理请求

## PUT

- 不安全但幂等
- 用客户端管理的实例号创建一个资源
- 通过替换的方式更新资源
- 如果未被修改，则更新资源（乐观锁）

- 200 （OK）- 如果已存在资源被更改

- 201 （created）- 如果新资源被创建
- 301（Moved Permanently）- 资源的URI已更改
- 303 （See Other）- 其他（如，负载均衡）
- 400 （bad request）- 指代坏请求
- 404 （not found）- 资源不存在
- 406 （not acceptable）- 服务端不支持所需表示
- 409 （conflict）- 通用冲突
- 412 （Precondition Failed）- 前置条件失败（如执行条件更新时的冲突）
- 415 （unsupported media type）- 接受到的表示不受支持
- 500 （internal server error）- 通用错误响应
- 503 （Service Unavailable）- 服务当前无法处理请求

## DELETE

- 不安全但幂等
- 删除资源

- 200 （OK）- 资源已被删除

- 301 （Moved Permanently）- 资源的URI已更改
- 303 （See Other）- 其他，如负载均衡
- 400 （bad request）- 指代坏请求
- 404 （not found）- 资源不存在
- 409 （conflict）- 通用冲突
- 500 （internal server error）- 通用错误响应
- 503 （Service Unavailable）- 服务端当前无法处理请求

## 实践中常见的问题:

> POST和PUT用于创建资源时有什么区别?

POST和PUT在创建资源的区别在于，所创建的资源的名称(URI)是否由客户端决定。 例如为我的博文增加一个java的分类，生成的路径就是分类名/categories/java，那么就可以采用PUT方法。不过很多人直接把POST、GET、PUT、DELETE直接对应上CRUD，例如在一个典型的rails实现的RESTful应用中就是这么做的。

我认为，这是因为rails默认使用服务端生成的ID作为URI的缘故，而不少人就是通过rails实践REST的，所以很容易造成这种误解。

> 客户端不一定都支持这些HTTP方法吧?

的确有这种情况，特别是一些比较古老的基于浏览器的客户端，只能支持GET和POST两种方法。

在实践上，客户端和服务端都可能需要做一些妥协。例如rails框架就支持通过隐藏参数_method=DELETE来传递真实的请求方法， 而像Backbone这样的客户端MVC框架则允许传递_method传输和设置X-HTTP-Method-Override头来规避这个问题。

> 统一接口是否意味着不能扩展带特殊语义的方法?

统一接口并不阻止你扩展方法，只要方法对资源的操作有着具体的、可识别的语义即可，并能够保持整个接口的统一性。

像WebDAV就对HTTP方法进行了扩展，增加了LOCK、UPLOCK等方法。而github的API则支持使用PATCH方法来进行issue的更新，例如:

```
PATCH /repos/:owner/:repo/issues/:number
```

不过，需要注意的是，像PATCH这种不是HTTP标准方法的，服务端需要考虑客户端是否能够支持的问题。

> 统一资源接口对URI有什么指导意义?

统一资源接口要求使用标准的HTTP方法对资源进行操作，所以URI只应该来表示资源的名称，而不应该包括资源的操作。

通俗来说，URI不应该使用动作来描述。例如，下面是一些不符合统一接口要求的URI:

- GET /getUser/1
- POST /createUser
- PUT /updateUser/1
- DELETE /deleteUser/1

## 资源的表述

-  资源在外界的具体呈现，可以有多种表述(或成为表现、表示)形式，在客户端和服务端之间传送的也是资源的表述，而不是资源本身。 例如文本资源可以采用html、xml、json等格式，图片可以使用PNG或JPG展现出来。

- 资源的表述包括数据和描述数据的元数据，例如，HTTP头"Content-Type" 就是这样一个元数据属性。

*那么客户端如何知道服务端提供哪种表述形式呢?*

答案是可以通过HTTP内容协商，客户端可以通过Accept头请求一种特定格式的表述，服务端则通过Content-Type告诉客户端资源的表述形式。

看一个github为例子，请求某组织资源的json格式的表述形式:

![](https://nateshao-blog.oss-cn-shenzhen.aliyuncs.com/img/291731048886033.jpg)

转xml格式的表述格式：

![](https://nateshao-blog.oss-cn-shenzhen.aliyuncs.com/img/291731045756062.jpg)



## RESTful应用案例--用户信息查询

本案例将采用RESTful风格的请求实现对用户信息的查询，同时返回JSON格式的数据。

其具体实现步骤如下。

( 1 )在控制器类UserController中，编写用户查询方法selectUser()，代码如下所示。

```java
package com.shaotongjie.controller;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;

import com.shaotongjie.po.User;
@Controller
public class UserController {
	/**
	 * 接收页面请求的JSON数据，并返回JSON格式结果
	 */
	@RequestMapping("/testJson")
	@ResponseBody
	public User testJson(@RequestBody User user) {
		// 打印接收的JSON格式数据
		System.out.println(user);
		// 返回JSON格式的响应
		return user;
	}
	
	@RequestMapping(value="/user/{id}",method=RequestMethod.GET)
	@ResponseBody
	public User selectUser(@PathVariable("id") String id){
	    System.out.println("id="+id);
	    User user=new User();
	    if(id.equals("1234")){	    	
	        user.setUsername("tom");
	    }
	    return user;
	}

}
```

在上述代码中，@RequestMapping(value="/user/{id}"，method=Requesttv1ethod.GET)注解用于匹配请求路径(包括参数)和方式。其中value="/user/{id}"表示可以匹配以"/user/{id}"结尾的请求，id为请求中的动态参数;method=RequestMethod.GET表示只接收GET方式的请求。方法中的@PathVariable(咽")注解则用于接收并绑定请求参数，它可以将请求URL中的变量映射到方法的形参上，如果请求路径为"/user/{id}"，即请求参数中的id和方法形参名称id一样，贝IJ@PathVariable后面的"(lIidll)"可以省略。

(2 )在WebContent目录下，编写页面文件restful.jsp，在页面中使用AJAX方式通过输入的用户编号来查询用户信息，如下所示。

```jsp
<%@ page language="java" contentType="text/html; charset=UTF-8"
     pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" 
"http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<title>RESTful测试</title>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<script type="text/javascript" 
    src="${pageContext.request.contextPath }/js/jquery-1.11.3.min.js">
</script>
<script type="text/javascript">
function search(){
	// 获取输入的查询编号
	var id = $("#number").val();
	$.ajax({
		url : "${pageContext.request.contextPath }/user/"+id,
		type : "GET", 
		//定义回调响应的数据格式为JSON字符串,该属性可以省略
		dataType : "json",
		//成功响应的结果
		success : function(data){
			if(data.username != null){	
			    alert("您查询的用户是："+data.username);
			}else{
			    alert("没有找到id为:"+id+"的用户！");
			}
		}
	});
}
</script>
</head>
<body>
    <form>
         编号：<input type="text" name="number" id="number">
	    <input type="button" value="搜索" onclick="search()" />
    </form> 
</body>
</html>
```

在请求路径中使用了RESTful风格的URL，并且定义了请求方式为GET。

将项目发布到Tomcat服务器并启动，在浏览器中访问地址http://localhost:8080/chapter14/restful.jsp

![restful测试](https://nateshao-blog.oss-cn-shenzhen.aliyuncs.com/img/restful测试.png)

在输入框中输入编号"1234"后，单击"查询"按钮，程序正确执行后，浏览器会弹出用户信息窗口

![restful测试1](https://nateshao-blog.oss-cn-shenzhen.aliyuncs.com/img/restful测试1.png)