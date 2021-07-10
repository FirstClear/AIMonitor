#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
class Config
{
public:
	//定义构造函数
	Config(string file);
	void setConfig();
	void setUser(string & user);
	string getUser();
	void setPassword(string & password);
	string getPassword();
	void setChannel(string & channel);
	vector<int> getChannel();
	void setLocation(string & location);
	string getLocation();
	void setSending(string & sending);
	string getSending();
	void setDuring(string & during);
	string getDuring();
	void setVersion(string & version);
	string getVersion();
	void setId(string & id);
	string getId();
	void printConfig();
	string file="file";//文件路径
	string id="id";  //激活id
	string username="username"; //综合系统用户名
	string password="password"; //综合系统密码
	string channel="channel";//选择的通道，空为全选
	string location="location";//连接地址，http://pm.cscec81.com/
	string sending="sending";//是否发送信息
	string during="during";//发送间隔
	string version="version";//版本号
private:
	map<string, int> hasAttribute;//判断是否含有相关属性
	map<string, string> attributes;   //属性
};

