--  校验规则对数据库的影响
--	
--  不区分大小写
--	创建一个数据库，校验规则使用utf8_general_ci[不区分大小写]

CREATE DATABASE test_litlle COLLATE utf8_general_ci;

USE test_litlle;

CREATE TABLE person(
	name VARCHAR(20)
);

INSERT INTO person VALUES('a');
INSERT INTO person VALUES('B');
INSERT INTO person VALUES('A');
INSERT INTO person VALUES('b');

--	区分大小写
--	创建一个数据库，校验规则使用utf8_ bin[区分大小写]

CREATE DATABASE test_large COLLATE utf8_bin;

USE test_large;

CREATE TABLE person(
	name VARCHAR(20)
);

INSERT INTO person VALUES('a');
INSERT INTO person VALUES('A');
INSERT INTO person VALUES('b');
INSERT INTO person VALUES('B');

-- 不区分大小写的查询以及结果
USE test_litlle;
SELECT * FROM person WHERE name = 'a';

+------+
| name |
+------+
| a    |
| A    |
+------+
2 rows in set (0.12 sec)

-- 区分大小写的查询以及结果
USE test_large;
SELECT * FROM person WHERE name = 'a';

+------+
| name |
+------+
| a    |
+------+
1 row in set (0.01 sec)

-- 结果排序 不区分大小写排序以及结果：
USE test_litlle;
SELECT * FROM person ORDER BY name;

+------+
| name |
+------+
| a    |
| A    |
| B    |
| b    |
+------+
4 rows in set (0.00 sec)

-- 结果排序 区分大小写排序以及结果：
USE test_large;
SELECT * FROM person ORDER BY name;

+------+
| name |
+------+
| A    |
| B    |
| a    |
| b    |
+------+
4 rows in set (0.11 sec)


--  查看数据库
SHOW DATABASES;

--  显示创建数据语句
SHOW CREATE DATABASE 库名;

--  例如:
SHOW CREATE DATABASE test;

+----------+---------------------------------------------------------------+
| Database | Create Database                                               |
+----------+---------------------------------------------------------------+
| test     | CREATE DATABASE `test` /*!40100 DEFAULT CHARACTER SET utf8 */ |
+----------+---------------------------------------------------------------+
1 row in set (0.00 sec)
--  说明：
--  	MySQL 建议我们关键字使用大写，但是不是必须的。
--  	数据库名字的反引号``,是为了防止使用的数据库名刚好是关键字
--  	/*!40100 default.... */ 这个不是注释，表示当前mysql版本大于4.01版本，就执行这句话

--  数据库删除
DROP DATABASE [IF EXISTS] 库名;
--  执行删除之后的结果:
--  	数据库内部看不到对应的数据库
--  	对应的数据库文件夹被删除，级联删除，里面的数据表全部被删
--  注意：不要随意删除数据库

--  例如:
CREATE DATABASE haha;
DROP DATABASE haha;
