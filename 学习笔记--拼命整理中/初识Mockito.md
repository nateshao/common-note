# 初识Mockito

> Mockito是一个针对Java的mocking框架。将模拟对象来代替真实对象。

1. 模拟任何外部依赖并将这些模拟对象插入测试代码中
2. 执行测试中的代码
3. 验证代码是否按照预期执行

## 前期工作

打开IDEA，new--> project --> Spring Initializr--> ..-->添加Spring Web...-->新建项目。

![项目结构](https://nateshao-blog.oss-cn-shenzhen.aliyuncs.com/img/项目结构.png)

## 创建Student

```java
package com.nateshao.domain;
/**
 * @Author TongJie Shao
 * Created by @Author  on 2020/7/11 23:46
 */

public class Student {
    private int id;
    private int age;
    private String name;

    public Student(int id, int age, String name) {
        this.id = id;
        this.age = age;
        this.name = name;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}
```

## 创建StudentDao

```java
package com.nateshao.dao;

import com.nateshao.domain.Student;
import org.springframework.stereotype.Component;

/**
 * @Author TongJie Shao
 * Created by @Author  on 2020/7/11 23:46
 */
@Component
public class StudentDao {
    public Student getStudentById(int id){
        return new Student(1,10,"nateshao");
    }
}

```

## 创建StudentService

```java
package com.nateshao.service;

import com.nateshao.dao.StudentDao;
import com.nateshao.domain.Student;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

/**
 * @Author TongJie Shao
 * Created by @Author  on 2020/7/11 23:46
 */
@Service
public class StudentService {

    @Autowired
    private StudentDao studentDao;

    public Student getStudentById(int id){
        return studentDao.getStudentById(id);
    }
}
```

## 在StudentService上Go To 新建测试类StudentServiceTest

```java
package com.nateshao.service;

import com.nateshao.dao.StudentDao;
import com.nateshao.domain.Student;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.mockito.Mockito;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.boot.test.mock.mockito.MockBean;

import static org.junit.jupiter.api.Assertions.*;

/**
 * @Author TongJie Shao
 * Created by @Author  on 2020/7/11 23:51
 */
@SpringBootTest
class StudentServiceTest {

    @Autowired
    private StudentService studentService;
    @MockBean	// 不走数据库
    StudentDao studentDao;

    @BeforeEach
    void setUp() {
        Mockito.when(studentDao.getStudentById(1)).thenReturn(new Student(1,10,"nateshao"));
    }

    @Test
    void getStudentById() {
        Student student = studentService.getStudentById(1);
        assertNotNull(student);
        assertEquals(student.getId(),1);
        assertEquals(student.getAge(),10);
        assertEquals(student.getName(),"nateshao");
    }
}
```

## 测试结果

![测试结果](https://nateshao-blog.oss-cn-shenzhen.aliyuncs.com/img/测试结果.png)