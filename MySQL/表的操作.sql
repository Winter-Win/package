-- 1.创建表
CREATE TABLE table_name(
	fielid1 datatype,
	fielid2 datatype,
	fielid3 datatype
)charactor set 字符集 collate 校验规则 engine 存储引擎;

-- 说明：
--     field 表示列名
--     datatype 表示列的类型
--     character set 字符集，如果没有指定字符集，则以所在数据库的字符集为准
--     collate 校验规则，如果没有指定校验规则，则以所在数据库的校验规则为准

-- 表相关操作
-- 建表
CREATE TABLE students (
	id INT,
	name VARCHAR(30),
	idcard CHAR(18)
);

-- 查看有默认库下有哪些表
SHOW TABLES;

-- 查看建表信息
SHOW CREATE TABLE students;
DESC students;

-- 删表
DROP TABLE students;

-- 修改表名称
RENAME students TO study_students;

-- 插入数据
INSERT INTO students (id, name) VALUES (18, "小文"); 

-- 修改数据
UPDATE students SET name = '小红' WHERE id = 18;

-- 查询
SELECT * FROM students WHERE name = '小文';

-- 删除
DELETE FROM students WHERE name = '小文';




/* 一对一、一对多、多对多 */

-- 老师表
CREATE TABLE teachers (
	id INT PRIMARY KEY AUTO_INCREMENT,
	name VARCHAR(20) NOT NULL
);

CREATE TABLE classes (
	id INT PRIMARY KEY AUTO_INCREMENT,
	name VARCHAR(20) NOT NULL
);

CREATE TABLE students (
	id INT PRIMARY KEY AUTO_INCREMENT,
	name VARCHAR(20) NOT NULL,
	class_id INT NOT NULL,
	FOREIGN KEY (class_id) REFERENCES classes(id)
);

SELECT LAST_INSERT_ID(); -- 相当于一个函数接口

INSERT INTO classes (name) VALUES ('比特50班'), ('比特51班');
INSERT INTO students (name, class_id) VALUES
('小A', 2),
('小B', 1);

DELETE FROM classes WHERE name = '比特50班'; -- 会失败

DELETE FROM students WHERE name = '小B';
DELETE FROM classes WHERE name = '比特50班'; -- 会成功

-- MySQL 不建议使用外键


CREATE TABLE goods (
	id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT COMMENT '',
	name VARCHAR(30) NOT NULL COMMENT '',
	price INT NOT NULL COMMENT '单位是分',
	category VARCHAR(20) NOT NULL DEFAULT '' COMMENT '',
	provider VARCHAR(50) NOT NULL DEFAULT '' COMMENT ''
) COMMENT '商品信息';

CREATE TABLE customers (
	id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT COMMENT '',
	name VARCHAR(20) NOT NULL COMMENT '',
	address VARCHAR(100) COMMENT '',
	email VARCHAR(100) COMMENT '',
	gender TINYINT NOT NULL COMMENT '0 保密 1 女 2 男',
	idcard CHAR(18) NOT NULL COMMENT '实名制'
) COMMENT '客户信息';

CREATE TABLE purchases (
	id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT COMMENT '',
	customer_id INT UNSIGNED NOT NULL COMMENT '',
	goods_id INT UNSIGNED NOT NULL COMMENT '',
	num INT NOT NULL DEFAULT 0 COMMENT '',
	FOREIGN KEY (customer_id) REFERENCES customers(id),
	FOREIGN KEY (goods_id) REFERENCES goods(id)
) COMMENT '订单信息';

/*
博客系统
1. 用户管理
2. 每个用户都有权限发文章
	1. 标题、作者、发文时间、正文
3. 每篇文章，每个用户都有权限去评论
	1. 评论者、关联文章、评论信息、评论时间
4. 每个用户都可以点赞某一篇文章
	1. 谁 点赞 哪篇文章
*/

/*
作业：
设计表结构
1. 确定需求及需求边界

2. 确定哪几类数据，找对象
	1. 用户
	2. 文章
	3. 评论
	4. 点赞信息
3. 找关系
	1. 用户-文章		一对多
	2. 文章-评论		一对多
	3. 用户-评论		一对多
	4. 用户-点赞-文章	多对多
4. 确定属性
	1. 用户
		1. 主键
		2. 用户名（可以重复，也可以不重复，根据需求确定）
		3. 【完善】注册时间/上次登陆时间/登陆时长/头像信息/个性签名
	2. 文章
		1. 主键
		2. 标题
		3. 作者 id
		4. 正文（TEXT)
		5. 发表时间
		6. 【冗余】点赞数量（需要程序自行保证数据的一致性）
		6. 【标签】
	3. 评论
		1. 主键
		2. 文章 id
		3. 评论者 id
		4. 评论正文(VARCHAR(100))
		5. 评论时间
	4. 点赞信息
		1. 主键
		2. 文章 id
		3. 用户 id
		4. 点赞时间
		（文章id + 用户id）唯一
5. 确定每个字段的数据类型
*/

/*
	插入
		1. 可以指定插入的字段；也可以不指定
		2. 可以单行插入；也可以批量插入
		3. 主键/唯一键冲突
			INSERT ... ON DUPLICATE KEY UPDATE ...
			REPLACE INTO ...
	查询
		1. SELECT 子句
			1. *
			2. 逗号分割的字段 或者 表达式（可以包含字段运算）
			3. 可选的 AS 给出别名
			4. DISTINCT 合并重复
		2. WHERE
			1. 与或非连接的逻辑表达式，结果为真的行作为查询结果
			2. = 作为相等判断而不是 ==
			2. BETWEEN .. AND ..	左闭右闭
			3. IN (...) 任意一个就是 true
			2. LIKE 的用法 '%' 和 '_'; NOT LIKE
			3. IS NULL 而不能 = NULL
			4. 了解 = 和 <=> 的区别；了解 <> 是不等于
		3. ORDER BY
			1. 没有 ORDER BY 的部分，认为无序
			2. ORDER BY 多字段，只有前面字段值相等的情况下，后边的字段才有意义
			3. ORDER BY 前后字段，升序降序规则独立，不干扰
		3. LIMIT
			2. 两种作用，三种写法
	*/
	
	
CREATE TABLE t1 (
	id INT UNIQUE
);

CREATE TABLE t2 (
	id INT UNIQUE
);

CREATE TABLE t3 (
	t1_id INT UNIQUE,
	t2_id INT UNIQUE,
	FOREIGN KEY (t1_id) REFERENCES t1(id),	-- id 必须是 t1 表的主键或者唯一键
	FOREIGN KEY (t2_id) REFERENCES t2(id)	-- id 必须是 t2 表的主键或者唯一键
);







