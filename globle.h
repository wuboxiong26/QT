#ifndef GLOBLE_H
#define GLOBLE_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QtDebug>
#include <QVariantList>

//static QString password_qj;
//static QString username_qj;
//QVariantList list_all_student;
//QVariantList list_all_dormstudent;
namespace Globel
{
    static QVariantList list_all_student;
    static QVariantList list_all_dormstudent;
}


static void connect()
{

    QSqlDatabase database;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        database = QSqlDatabase::database("qt_sql_default_connection");
    else
        database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("xiaowu.db");
    database.setUserName("wuboxiong");
    database.setPassword("1922030114");
    if (!database.open())
        qDebug() << database.lastError();
    else qDebug() << "open";

    QSqlQuery query(database);
    query.exec("CREATE TABLE `admin` ("
        "`id` int(11) NOT NULL DEFAULT '0',"
        "`username` text,"
        "`password` text,"
        "PRIMARY KEY (`id`)"
               ");");
    query.exec("INSERT INTO `admin` VALUES ('1', 'admin', 'admin');");
    query.exec("INSERT INTO `admin` VALUES ('2', '吴博雄', '1922030114');");

    query.exec("CREATE TABLE `class` ("
          "`classid` int(11) DEFAULT NULL,"
          "`classname` text,"
          "`major` text,"
          "`membernum` int(11) DEFAULT NULL,"
          "`instructor` text"
          " PRIMARY KEY (`classid`)"
               ");");

    query.exec("INSERT INTO `class` VALUES ('101', '计中职1901', '计算机科学与技术', '40', '张哈哈');");
    query.exec("INSERT INTO `class` VALUES ('102', '计科1901', '计算机科学与技术', '30', '王嘿嘿');");
    query.exec("INSERT INTO `class` VALUES ('103', '软工1901', '软件工程', '20', '李呵呵');");

    query.exec("CREATE TABLE `course` ("
      "`id` int(11) NOT NULL DEFAULT '0',"
      "`object` text,"
      "`teacher` text,"
      "`coursetime` text,"
      "`courseaddress` text,"
      "`period` text,"
      "`credit` text,"
      " PRIMARY KEY (`id`)"
               ");");
    query.exec("INSERT INTO `course` VALUES ('101', 'Java', '赵呼呼', '大三上', '三丰大厦102教室', '32', '4');");
    query.exec("INSERT INTO `course` VALUES ('103', 'c语言', '钱零零', '大一上', 'IC大厦109教室', '64', '3');");
    query.exec("INSERT INTO `course` VALUES ('105', 'C++', '孙乐乐', '大二下', '钻石大厦103教室', '56', '4');");
    query.exec("INSERT INTO `course` VALUES ('107', '数据结构与算法', '周涛涛', '大三下', '钻石大厦103教室', '48, '4');");

    query.exec("CREATE TABLE `student` ("
               "`id` bigint(11) NOT NULL,"
               "`name` text,"
               "`sex` text,"
               "`age` text,"
               "`major` text,"
               "`banji` int(11) DEFAULT NULL,"
               "`address` text,"
               "`phonenumber` text,"
               "`beizhu` text,"
               "`password` text,"
               "`dormnum` text,"
               "`bednum` text,"
               "`award` text,"
               "`punish` text,"
               " PRIMARY KEY (`id`)"
               ");");
    query.exec("INSERT INTO `student` VALUES ('1000', '张三', '男', '19', '计算机科学与技术', '1001', '大连', '15484321047', '学生', '123456', '520', '1', '无', '记过');");
    query.exec("INSERT INTO `student` VALUES ('1002', '李四', '男', '18', '软件工程', '1002', '锦州', '17425963248', '学生', '123456', '522', '3', '数学竞赛一等奖', '无');");
    query.exec("INSERT INTO `student` VALUES ('1004', '王五', '女', '19', '信息安全', '1003', '青岛', '15463240127', '学生', '123456', '523', '5', '运动会跳远第一', '无');;");
    query.exec("INSERT INTO `student` VALUES ('1006', '赵六', '女', '18', '土木工程', '1004', '三亚', '19875663259', '学生', '123456', '513', '2', '学习积极分子', '无');");
    query.exec("INSERT INTO `student` VALUES ('1008', '李虎', '男', '18', '网络工程', '1005', '新民', '10265471023', '学生', '123456', '222', '4', '先进班干部', '无');");
    query.exec("INSERT INTO `student` VALUES ('1922030114', '吴博雄', '男', '23', '计算机科学与技术', '1901', '沈阳', '18742447287', '本人是个大帅哥', '1922030114', '521', '2', '二等奖学金', '无');");


    query.exec("CREATE TABLE `fee` ("
      "`id` bigint(20) DEFAULT NULL,"
      "`name` text,"
      "`banji` text,"
      "`major` text,"
      "`term` text,"
      "`fee` text,"
      "`arrearage` text"
                ");");
    query.exec("INSERT INTO `fee` VALUES ('1922030114', '吴博雄', '1901', '计算机科学与技术', '大一下', '4800元', '0元');");
    query.exec("INSERT INTO `fee` VALUES ('1000', '张三', '1001', '计算机科学与技术', '大一上', '4800元', '4800元');");
    query.exec("INSERT INTO `fee` VALUES ('1002', '李四', '1002', '软件工程', '大一下', '4800元', '9600元');");
    query.exec("INSERT INTO `fee` VALUES ('1004', '王五', '1003', '信息安全', '大一下', '10000元', '20000元');");
    query.exec("INSERT INTO `fee` VALUES ('1006', '赵六', '1004', '土木工程', '大一下', '4800元', '0元');");
    query.exec("INSERT INTO `fee` VALUES ('1008', '李虎', '1005', '网络工程', '大一下', '10000元', '0元');");

    query.exec("CREATE TABLE `score` ("
          "`id` bigint(20) DEFAULT NULL,"
          "`time` text,"
          "`object` text,"
          "`score` text,"
          "`banji` text,"
          "`student` text"
                ");");

    query.exec("INSERT INTO `score` VALUES ('10002', '大一上', 'Java', '81', '1001', '张三');");
    query.exec("INSERT INTO `score` VALUES ('10003', '大一上', 'C++', '89', '1002', '李四');");
    query.exec("INSERT INTO `score` VALUES ('10004', '大一下', 'c语言', '100', '1003', '王五');");
    query.exec("INSERT INTO `score` VALUES ('10005', '大一下', '++', '83', '1005', '李虎');");
    query.exec("INSERT INTO `score` VALUES ('10006', '大一下', '大物', '98', '1001', '张三');");
    query.exec("INSERT INTO `score` VALUES ('10007', '大一下', '++',', '2', '1003', '王五');;");

    database.close();
}

#endif
